#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = nullptr);
    virtual ~Controller();

    void startup();
    void shutdown();

signals:

public slots:
};

#endif // CONTROLLER_H
