#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QString>

class Controller : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString userName READ userName WRITE setUserName NOTIFY userNameChanged)

public:
  explicit Controller(QObject* parent = nullptr);
  virtual ~Controller();
  
  QString userName();
  void setUserName(const QString &userName);
  
signals:
  void userNameChanged();
  
private:
  QString m_userName;
};

#endif
