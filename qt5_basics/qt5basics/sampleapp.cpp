#include "sampleapp.h"

SampleApp::SampleApp(QObject *parent) : QObject(parent)
{

}

void SampleApp::run()
{
    emit finished();
}
