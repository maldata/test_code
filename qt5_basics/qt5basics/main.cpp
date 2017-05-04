#include <QCoreApplication>
#include <QTimer>

#include <iostream>

#include "sampleapp.h"

int main(int argc, char *argv[])
{
    std::cout << "Start" << std::endl;

    QCoreApplication a(argc, argv);
    SampleApp* app = new SampleApp(&a);

    std::cout << "Connecting." << std::endl;

    QObject::connect(app, &SampleApp::finished, &a, &QCoreApplication::quit);

    std::cout << "Starting up" << std::endl;

    QTimer::singleShot(0, app, &SampleApp::startup);

    std::cout << "Starting the event loop" << std::endl;

    int result = 0;
    result = a.exec();

    app->shutdown();

    return result;
}
