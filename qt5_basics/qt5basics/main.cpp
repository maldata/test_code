#include <QCoreApplication>
#include <QTimer>

#include "sampleapp.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    SampleApp* app = new SampleApp(&a);

    QObject::connect(app, SIGNAL(finished()), &a, SLOT(quit()));
    QTimer::singleShot(0, app, SLOT(run()));

    return a.exec();
}
