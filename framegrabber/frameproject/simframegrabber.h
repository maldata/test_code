#ifndef SIMFRAMEGRABBER_H
#define SIMFRAMEGRABBER_H

#include <QObject>

#include "iframegrabber.h"

class SimFrameGrabber : public IFrameGrabber
{
    Q_OBJECT

public:
    SimFrameGrabber(QObject* parent = 0);

    void start();
    void stop();
    void run();

protected:
    bool abort;
};

#endif // SIMFRAMEGRABBER_H
