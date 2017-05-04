#ifndef SAMPLEAPP_H
#define SAMPLEAPP_H

#include <QObject>

#include "iframegrabber.h"

class SampleApp : public QObject
{
    Q_OBJECT
public:
    explicit SampleApp(QObject *parent = nullptr);
    ~SampleApp();

private:
    IFrameGrabber* member;

signals:
    void finished();

public slots:
    void startup();
    void shutdown();
};

#endif // SAMPLEAPP_H
