#include "controller.h"

Controller::Controller(QObject* parent) :
    QObject(parent)
{
}

Controller::~Controller()
{
}

QString Controller::userName()
{
    return m_userName;
}

void Controller::setUserName(const QString &userName)
{
    if (userName == m_userName)
        return;

    m_userName = userName;
    emit userNameChanged();
}
