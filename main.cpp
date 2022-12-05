#include <QCoreApplication>
#include <QMediaPlayer>
#include <QTcpServer>
#include <QTcpSocket>
#include "server.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Server sv;
    return a.exec();
}
