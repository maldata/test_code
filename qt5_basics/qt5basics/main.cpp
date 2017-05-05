#include <QCoreApplication>
#include <QTimer>

#include <iostream>

#include "sampleapp.h"

int main(int argc, char *argv[])
{
    std::cout << "Starting main" << std::endl;

    QCoreApplication a(argc, argv);
    SampleApp* app = new SampleApp(&a);

    std::cout << "Connecting signals in main" << std::endl;

    QObject::connect(app, &SampleApp::finished, &a, &QCoreApplication::quit);
    QTimer::singleShot(0, app, &SampleApp::startup);
    QTimer::singleShot(10000, app, &SampleApp::shutdown);

    std::cout << "Starting the Qt5 event loop in main" << std::endl;

    int result = 0;
    result = a.exec();

    std::cout << "Qt5 event loop ended. All done!" << std::endl;

    return result;
}
