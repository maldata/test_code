#include "controller.h"

Controller::Controller(QObject* parent) :
    QObject(parent)
{
}

Controller::~Controller()
{
}

QString Controller::getPythonVersion()
{
    return _python_version;
}

void Controller::setPythonVersion(const QString& python_version)
{
    if (python_version == _python_version)
        return;

    _python_version = python_version;
    emit python_version_changed();
}
