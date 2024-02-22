#include <QCoreApplication>
#include <QDebug>
#include <QString>
#include <QMap>
#include <QSysInfo>
#include <QStorageInfo>
#include <QList>

int main(int argc, char *argv[])
{
    QCoreApplication        a(argc, argv);
    QString                 str = "Greg Rigole";
    QMap<QString,int>       map;
    QSysInfo                sysinfo;
    QList<QStorageInfo>     vols = QStorageInfo::mountedVolumes();

    // qInfo
    qInfo() << "Testing qInfo" << str;

    // QMap
    map.insert( "Greg", 56 );
    map.insert( "Marlene", 81 );
    map.insert( "Victor", 86 );
    map.insert( "Shelley", 54 );
    map.insert( "Roberta", 51 );

    qInfo() << map;
    qInfo() << "Greg is" << map["Greg"] << "years old.";

    // QSysInfo
    qInfo() << "BigEndian" << sysinfo.BigEndian;
    qInfo() << "LittleEndian" << sysinfo.LittleEndian;

    // QStorageInfo
    foreach (QStorageInfo fs, vols) {
        qInfo() << "==============================";
        qInfo() << "Name:" << fs.displayName();
        qInfo() << "Device:" << fs.device();
        qInfo() << "BlockSize:" << fs.blockSize();
        qInfo() << "Type:" << fs.fileSystemType();
        qInfo() << "Root?:" << fs.isRoot();
    }

    return a.exec();
}
