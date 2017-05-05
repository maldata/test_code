#include <iostream>

#include "sampleapp.h"
#include "simchild.h"

SampleApp::SampleApp(QObject *parent) : QObject(parent)
{
    std::cout << "Application object constructor" << std::endl;
    this->member = new SimChild();
}

SampleApp::~SampleApp()
{
    std::cout << "Application object destructor" << std::endl;
    delete this->member;
}

void SampleApp::startup()
{
    std::cout << "Starting up the application object" << std::endl;
    this->member->start();
}

void SampleApp::shutdown()
{
    std::cout << "Shutting down the application object" << std::endl;
    this->member->stop();
    this->member->wait();
    emit finished();
}
