#ifndef IFRAMEGRABBER_H
#define IFRAMEGRABBER_H

#include <QObject>
#include <QThread>

class IFrameGrabber : QThread
{
    Q_OBJECT

public:
    IFrameGrabber(QObject* parent = 0) = 0;

    virtual void start() = 0;
    virtual void stop() = 0;
    virtual void run() = 0;

protected:
    bool abort;
};

#endif // IFRAMEGRABBER_H
