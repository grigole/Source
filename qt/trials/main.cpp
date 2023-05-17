#include <QCoreApplication>
#include <QDebug>
#include <QString>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString str = "Greg Rigole";

    qInfo() << "Testing QInfo" << str;

    return a.exec();
}
