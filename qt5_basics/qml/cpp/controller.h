#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QString>

class Controller : public QObject
{
    Q_OBJECT

    // Here I create properties and explicitly specify the accessor functions to use
    // The arguments are (type name READ getter WRITE setter NOTIFY signal)
    // The property name and the getter can be the same or different, but the QML must use the property name.
    Q_PROPERTY(QString python_version READ pythonVersion WRITE setPythonVersion NOTIFY python_version_changed)
    Q_PROPERTY(bool connected READ connected WRITE setConnected NOTIFY connect_status_changed)
    Q_PROPERTY(QString qt_version READ qtVersion WRITE setQtVersion NOTIFY qt_version_changed)

    // This format for the property doesn't seem to work. The MEMBER keyword I think only allows the QML
    // to know it exists (creates ReadProperty and WriteProperty features in the moc).
    //Q_PROPERTY(bool connected MEMBER _connected NOTIFY connect_status_changed)

public:
    explicit Controller(QObject* parent = nullptr);
    virtual ~Controller();

    QString pythonVersion();
    void setPythonVersion(const QString& value);

    QString qtVersion();
    void setQtVersion(const QString& value);

    bool connected();
    void setConnected(const bool& value);

    void startup();

public slots:
    // public methods can only be called from QML if they are slots
    void connect();
    void shutdown();

signals:
  void python_version_changed();
  void qt_version_changed();
  void log_text_changed();
  void connect_status_changed();
  void ip_address_changed();
  void pub_port_changed();
  void router_port_changed();
  void topic_changed();
  void message_changed();
  
private:
  QString _python_version;
  QString _qt_version;
  bool _connected;
};

#endif
