#include <QCoreApplication>
#include <QTimer>

#include "sampleapp.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    SampleApp* app = new SampleApp(&a);

    QObject::connect(app, &SampleApp::finished, &a, &QCoreApplication::quit);
    QTimer::singleShot(0, app, &SampleApp::run);

    return a.exec();
}
