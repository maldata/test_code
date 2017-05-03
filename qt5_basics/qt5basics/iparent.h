#ifndef IPARENT_H
#define IPARENT_H

#include <QObject>

class IParent : public QObject
{
    Q_OBJECT
public:
    explicit IParent(QObject *parent = nullptr);

signals:

public slots:
};

#endif // IPARENT_H