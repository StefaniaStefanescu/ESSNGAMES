#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QObject>

class QTcpSocket;

class tcpclient : public QObject
{
    Q_OBJECT
public:
    static tcpclient& getInstance();
    static void destroyInstance();

    void start(QString ip, unsigned short port);
    void stop();

    QString getData(QString requestMessage);

  //aici setez username-ul curent
    static void setUsername(QString str) { tcpclient::clientUsername = str; }
    static QString getUsername() { return tcpclient::clientUsername; }

signals:
   void realtimemessage(QString message);

private slots:
    QString readyRead();


private:
    static tcpclient* instance;
    QTcpSocket* socket;
    static QString clientUsername;
    static QString readString;
    static bool readFlag;

    explicit tcpclient(QObject *parent = nullptr);
    //TCPClient(const TCPClient& client);
    //~TCPClient();
};

#endif // TCPCLIENT_H
