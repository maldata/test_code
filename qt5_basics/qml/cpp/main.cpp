#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickWindow>

#include "controller.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    Controller main_controller(&app);
    QQmlContext* context = engine.rootContext();
    context->setContextProperty("main", &main_controller);
    engine.load(QUrl("../qml/main.qml"));

    QObject* topLevel = engine.rootObjects().value(0);
    QQuickWindow* window = qobject_cast<QQuickWindow*>(topLevel);
    window->show();
    
    return app.exec();
}
