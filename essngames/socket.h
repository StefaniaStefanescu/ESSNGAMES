#ifndef SOCKET_H
#define SOCKET_H

#include <QObject>
#include<QDebug>
#include<QTcpSocket>
#include<QAbstractSocket>
#include <QFile>
#include <QTextStream>
#include <QJsonDocument>


class Socket : public QObject
{
    Q_OBJECT
public:
    explicit Socket(QObject *parent = nullptr);
    void Test();
signals:


public slots:
    void connectTo(QString ip, QString port);
    void bytesWritten(qint64 bytes);
    void readyRead();
    void send(QString string);
    void send(QJsonDocument doc);
    QString read();
private slots:
    void connected();
    void diconnected();
private:
    QTcpSocket*socket;



};

#endif // SOCKET_H
