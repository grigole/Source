#include <QCoreApplication>
#include <QtConcurrent>
#include <QFuture>
#include <QDebug>

#include "worker.h"

void runFunction( int id )
{
    qInfo() << "Called runFunction" << id << QThread::currentThread();
}

void testConcurrent( void )
{
    qInfo() << "Starting threads";

    QFuture<void> t1 = QtConcurrent::run( runFunction, 1 );
    QFuture<void> t2 = QtConcurrent::run( runFunction, 2 );
    QFuture<void> t3 = QtConcurrent::run( runFunction, 3 );

    t1.waitForFinished();
    t2.waitForFinished();
    t3.waitForFinished();

    qInfo() << "All threads finished";
}

void testThread( void )
{
    QThread     thread;
    Worker*     worker = new Worker();

    qInfo() << "Starting thread";

    // QObject::connect(thread.started,)
    
    worker->moveToThread( &thread );

    qInfo() << "Thread finished";
}

void testThreadPool( void )
{
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // testConcurrent();
    testThread();

    return a.exec();
}
