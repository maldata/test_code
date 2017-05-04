#include "simchild.h"

#include <unistd.h>

SimChild::SimChild(QObject* parent)
{

}

void SimChild::start()
{
    this->stop_flag = false;
    QThread::start();
}

void SimChild::stop()
{
    this->stop_flag = true;
}

void SimChild::run()
{
    while(!this->stop_flag)
    {
        usleep(100000);
    }
}
