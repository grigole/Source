#include <QCoreApplication>
#include <QDebug>
#include <QString>
#include <QMap>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString str = "Greg Rigole";
    QMap<QString,int> map;

    qInfo() << "Testing QInfo" << str;

    map.insert( "Greg", 56 );
    map.insert( "Marlene", 81 );
    map.insert( "Victor", 86 );
    map.insert( "Shelley", 54 );
    map.insert( "Roberta", 51 );

    qInfo() << map;
    qInfo() << "Greg is" << map["Greg"];

    return a.exec();
}
