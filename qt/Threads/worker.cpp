#include "worker.h"

Worker::Worker(QObject *parent)
    : QObject{parent}
{

}

void Worker::run()
{
    qInfo() << "Worker starting";

    qInfo() << "Worker finished";
}
