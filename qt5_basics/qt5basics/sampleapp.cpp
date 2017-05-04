#include <iostream>

#include "sampleapp.h"
#include "simchild.h"

SampleApp::SampleApp(QObject *parent) : QObject(parent)
{
    std::cout << "Constructor" << std::endl;
    this->member = new SimChild();
}

SampleApp::~SampleApp()
{
    std::cout << "Destructor" << std::endl;
    delete this->member;
}

void SampleApp::startup()
{
    std::cout << "Starting up" << std::endl;

    emit finished();
}

void SampleApp::shutdown()
{
    std::cout << "Shutting down" << std::endl;
}
