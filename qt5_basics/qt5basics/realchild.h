#ifndef REALCHILD_H
#define REALCHILD_H

#include "iframegrabber.h"

class RealChild : public IFrameGrabber
{
public:
    explicit RealChild(QObject* parent = nullptr);

protected:
    void run();
    void start();
    void stop();

private:

signals:

public slots:
};

#endif // REALCHILD_H
