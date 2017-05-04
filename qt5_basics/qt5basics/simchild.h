#ifndef SIMCHILD_H
#define SIMCHILD_H

#include "iframegrabber.h"

class SimChild : public IFrameGrabber
{
public:
    explicit SimChild(QObject* parent = nullptr);

protected:
    void run();
    void start();
    void stop();

private:

signals:

public slots:
};

#endif // SIMCHILD_H
