#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QUdpSocket>
#include <QMediaPlayer>

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);

signals:

public slots:
    void processRecievedData();

private:
    QUdpSocket *server;
    QMediaPlayer *player;

};

#endif // SERVER_H
