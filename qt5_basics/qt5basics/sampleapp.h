#ifndef SAMPLEAPP_H
#define SAMPLEAPP_H

#include <QObject>

#include "iparent.h"

class SampleApp : public QObject
{
    Q_OBJECT
public:
    explicit SampleApp(QObject *parent = nullptr);
    ~SampleApp();

private:
    IParent* member;

signals:
    void finished();

public slots:
    void startup();
    void shutdown();
};

#endif // SAMPLEAPP_H
