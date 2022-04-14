#include "socket.h"
#include <QtCore>
#include <QHostAddress>
Socket::Socket(QObject *parent)
    : QObject{parent}
{

}
void Socket::Test()
{
    socket=new QTcpSocket(this);
    connect(socket,SIGNAL(connected()),this,SLOT(conncted()));
    connect(socket,SIGNAL(bytesWritten(qint64 bytes)),this,SLOT(bytesWritten(qint64 bytes)));
    connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()));
    connect(socket,SIGNAL(diconnected()),this,SLOT(diconnected()));

    qDebug()<<"Connecting..";
    //conexiune cu un server

}

void Socket::connectTo(QString ip, QString port)
{
    socket->connectToHost(ip, port.toInt());
}
void Socket::connected(){
      qDebug()<<"Connected!";
}
void Socket::diconnected(){
     qDebug()<<"Disconnected!";
}
void Socket::bytesWritten(qint64 bytes){
     qDebug()<<"We wrote:"<<bytes;
}
void Socket::readyRead(){
     qDebug()<<"Reading..";

}

void Socket::send(QString string)
{
    QJsonDocument doc;
    QJsonArray array;
    array.append(QJsonValue(string));
    doc.setArray(array);
    send(doc);
}

void Socket::send(QJsonDocument doc)
{
      socket->write(doc.toJson());
}

QString Socket::read()
{
    QString buffer;
    buffer = socket->readAll();
    return buffer;
}
