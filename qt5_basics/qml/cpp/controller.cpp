#include "controller.h"

#include <QtCore>

Controller::Controller(QObject* parent) :
    QObject(parent)
{
    _python_version = "";
    _qt_version = "";
    _connected = false;
}

Controller::~Controller()
{
}

QString Controller::pythonVersion()
{
    return _python_version;
}

void Controller::setPythonVersion(const QString& value)
{
    if (value == _python_version)
        return;

    _python_version = value;
    emit python_version_changed();
}

QString Controller::qtVersion()
{
    return _qt_version;
}

void Controller::setQtVersion(const QString& value)
{
    if (value == _qt_version)
        return;

    _qt_version = value;
    emit qt_version_changed();
}

bool Controller::connected()
{
    return _connected;
}

void Controller::setConnected(const bool& value)
{
    if (_connected == value)
        return;

    _connected = value;
    emit connect_status_changed();
}

void Controller::connect()
{
    setConnected(true);
}

void Controller::startup()
{
    setPythonVersion("C++");
    setQtVersion(qVersion());
    setConnected(false);
}

void Controller::shutdown()
{
    return;
}
