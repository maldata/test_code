#include "simchild.h"

#include <iostream>
#include <unistd.h>

SimChild::SimChild(QObject* parent)
{
    std::cout << "QThread child constructor" << std::endl;
}

void SimChild::start()
{
    std::cout << "QThread child is starting" << std::endl;
    this->stop_flag = false;
    QThread::start();
}

void SimChild::stop()
{
    std::cout << "QThread child is being flagged to stop" << std::endl;
    this->stop_flag = true;
}

void SimChild::run()
{
    std::cout << "QThread is running..." << std::endl;
    while(!this->stop_flag)
    {
        usleep(100000);
    }

    std::cout << "QThread is finished running." << std::endl;
}
