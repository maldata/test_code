#ifndef IFRAMEGRABBER_H
#define IFRAMEGRABBER_H

#include <QObject>
#include <QThread>

class IFrameGrabber : public QThread
{
    Q_OBJECT

public:
    virtual void start() = 0;
    virtual void stop() = 0;

protected:
    virtual void run() = 0;

    bool stop_flag;

signals:

public slots:
};

Q_DECLARE_INTERFACE(IFrameGrabber, "IFrameGrabber")

#endif // IFRAMEGRABBER_H
