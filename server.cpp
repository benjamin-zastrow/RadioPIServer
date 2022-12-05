#include "server.h"
#include <iostream>

Server::Server(QObject *parent) : QObject(parent)
{
    server = new QUdpSocket(this);
    server->bind(45454, QUdpSocket::ShareAddress);
    connect(server, SIGNAL(readyRead()), this, SLOT(processRecievedData()));
    player = new QMediaPlayer(this);
}

void Server::processRecievedData()
{
    QByteArray datagram;
    while(server->hasPendingDatagrams())
    {
        datagram.resize(server->pendingDatagramSize());
        server->readDatagram(datagram.data(), datagram.size());
        QString msg = datagram.constData();
        if(msg.contains("vol"))
        {
            std::clog << "VOLUME SET TO: " << msg.split(";").at(1).toInt() << "\n";
            player->setVolume(msg.split(";").at(1).toInt());
        }
        if(msg.contains("play"))
        {
            std::clog << "PLAYING: " << msg.split(";").at(1).toStdString() << "\n";
            player->pause();
            player->setMedia(QUrl(msg.split(";").at(1)));
            player->play();
        }

    }
}
