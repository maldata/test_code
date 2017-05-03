#ifndef SAMPLEAPP_H
#define SAMPLEAPP_H

#include <QObject>

class SampleApp : public QObject
{
    Q_OBJECT
public:
    explicit SampleApp(QObject *parent = nullptr);

signals:
    void finished();

public slots:
    void run();
};

#endif // SAMPLEAPP_H
