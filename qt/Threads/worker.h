#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QRunnable>
#include <QDebug>

class Worker : public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr);



signals:


    // QRunnable interface
public:
    void run();
};

#endif // WORKER_H
