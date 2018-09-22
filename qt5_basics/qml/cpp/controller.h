#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QString>

class Controller : public QObject
{
    Q_OBJECT

    // Here I create a property and explicitly specify the accessor functions to use
    Q_PROPERTY(QString python_version READ getPythonVersion WRITE setPythonVersion NOTIFY python_version_changed)

    // Here I just create a property linked to a member variable and let Qt generate accessors behind the scenes
    Q_PROPERTY(bool connected MEMBER _connected NOTIFY connect_status_changed)

public:
  explicit Controller(QObject* parent = nullptr);
  virtual ~Controller();
  
  QString getPythonVersion();
  void setPythonVersion(const QString& python_version);
  
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
  bool _connected;
};

#endif
