import sys
import time
import threading

from PyQt5.QtCore import QObject, pyqtProperty, pyqtSignal, pyqtSlot
from PyQt5.QtQml import QQmlApplicationEngine
from PyQt5.QtGui import QGuiApplication


class MainController(QObject):
    pyzmq_version_changed = pyqtSignal()
    libzmq_version_changed = pyqtSignal()
    log_text_changed = pyqtSignal()
    connect_status_changed = pyqtSignal()
    ip_address_changed = pyqtSignal()
    pub_port_changed = pyqtSignal()
    router_port_changed = pyqtSignal()
    topic_changed = pyqtSignal()
    message_changed = pyqtSignal()
    message_received = pyqtSignal(bytes, bytes)

    def __init__(self, app):
        super(MainController, self).__init__()
        self._app = app

        self._pyzmq_version = ''
        self._libzmq_version = ''

        self._log_text = ''
        self._connected = False

        self._ip_address = '127.0.0.1'
        self._pub_port = 57879
        self._router_port = 57880

        self._router_url = ''
        self._pub_url = ''

        self.context = None
        self.router_socket = None
        self.pub_socket = None

        self._topic = b''
        self._message = b''

        self._polling_thread = None
        self._keep_going = False

    def startup(self):
        self.pyzmq_version = '3.0.0'
        self.libzmq_version = '2.1.2'

        self._log_text = ''

    @pyqtSlot()
    def shutdown(self):
        print("Shutting down.")
        self._keep_going = False
        self._polling_thread.join()
        self._app.quit()

    def polling_loop(self):
        while self._keep_going:
            time.sleep(1)

    @pyqtSlot(str, str)
    def publish(self, topic, message):
        self.log_text = 'Publishing {0}{1}'.format(topic, message)

    @pyqtProperty(str, notify=pyzmq_version_changed)
    def pyzmq_version(self):
        return self._pyzmq_version

    @pyzmq_version.setter
    def pyzmq_version(self, value):
        self._pyzmq_version = value
        self.pyzmq_version_changed.emit()

    @pyqtProperty(str, notify=libzmq_version_changed)
    def libzmq_version(self):
        return self._libzmq_version

    @libzmq_version.setter
    def libzmq_version(self, value):
        self._libzmq_version = value
        self.libzmq_version_changed.emit()

    @pyqtProperty(str, notify=log_text_changed)
    def log_text(self):
        return self._log_text

    @log_text.setter
    def log_text(self, value):
        self._log_text = value[:60] + '\n' + self._log_text  # Limit the line size to 60 characters 
        self._log_text = self._log_text[-2000:]  # Limit the total size to 2000 characters
        self.log_text_changed.emit()

    @pyqtProperty(bool, notify=connect_status_changed)
    def connected(self):
        return self._connected

    @connected.setter
    def connected(self, value):
        self._connected = value
        self.connect_status_changed.emit()

    @pyqtProperty(str, notify=ip_address_changed)
    def ip_address(self):
        return self._ip_address

    @ip_address.setter
    def ip_address(self, value):
        self._ip_address = value
        self.ip_address_changed.emit()

    @pyqtProperty(int, notify=pub_port_changed)
    def pub_port(self):
        return self._pub_port

    @pub_port.setter
    def pub_port(self, value):
        self._pub_port = value
        self.pub_port_changed.emit()

    @pyqtProperty(int, notify=router_port_changed)
    def router_port(self):
        return self._router_port

    @router_port.setter
    def router_port(self, value):
        self._router_port = value
        self.router_port_changed.emit()

    @pyqtProperty(str, notify=topic_changed)
    def topic(self):
        return self._topic.decode('ascii')

    @topic.setter
    def topic(self, value):
        self._topic = value.encode('ascii')
        self.topic_changed.emit()

    @pyqtProperty(str, notify=message_changed)
    def message(self):
        return self._message.decode('ascii')

    @message.setter
    def message(self, value):
        self._message = value.encode('ascii')
        self.message_changed.emit()

    @pyqtSlot()
    def connect(self):
        self.log_text = 'Binding to {0}:{1} and {0}:{2}'.format(self.ip_address,
                                                                self.pub_port,
                                                                self.router_port)
        self._router_url = 'tcp://{0}:{1}'.format(self.ip_address, self.router_port)
        self._pub_url = 'tcp://{0}:{1}'.format(self.ip_address, self.pub_port)
        self.log_text = 'Router URL: {0}'.format(self._router_url)
        self.log_text = 'Publisher URL: {0}'.format(self._pub_url)
        self.log_text = 'Sockets are bound.'

        self.message_received.connect(self.message_handler)
        self._keep_going = True
        self._polling_thread = threading.Thread(target=self.polling_loop)
        self._polling_thread.start()
        self.connected = True

    @pyqtSlot(str, str)
    def publish(self, topic, message):
        self.log_text = 'Publishing [{0}][{1}]'.format(topic, message)
        topic_bytes = topic.encode('ascii')
        message_bytes = message.encode('ascii')

    def message_handler(self, sender, message):
        #sender_str = sender.decode('ascii')
        #message_str = message.decode('ascii')
        self.log_text = '\t==> Message from {0}'.format(sender)
        self.log_text = '\t==> "{0}"'.format(message)

        
def main():
    app = QGuiApplication(sys.argv)
    qml_engine = QQmlApplicationEngine()

    main_controller = MainController(app)
    context = qml_engine.rootContext()
    context.setContextProperty("main", main_controller)
    qml_engine.load('qml/main.qml')

    main_window = qml_engine.rootObjects()[0]
    main_window.show()

    main_controller.startup()
    sys.exit(app.exec_())


if __name__ == '__main__':
    main()
