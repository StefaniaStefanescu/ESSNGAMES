#include "tcpclient.h"
#include "QTcpSocket"
#include "QDebug"
#include "QMessageBox"
#include "QStringList"

tcpclient* tcpclient::instance = nullptr;
QString tcpclient::clientUsername;
QString tcpclient::readString;
bool tcpclient::readFlag = false;

tcpclient::tcpclient(QObject *parent)
    : QObject{parent}
{

}

QString tcpclient::readyRead()
{
    QByteArray message;
    message = socket->readAll();
    tcpclient::readFlag = true;
    tcpclient::readString = QString(message);
    QStringList toks=QString(message).split('/');
    //mereu cand am 77 ma duc si prind semnalul
    if(toks[0]=="777"){

        emit realtimemessage(QString(message));
    }
    return QString(message);
}



QString tcpclient::getData(QString requestMessage)
{
    if(socket->isWritable())
    {
        qDebug() << "request message: " << requestMessage;

        QByteArray msg = requestMessage.toLocal8Bit();
        socket->write(msg.data(),qint64(requestMessage.size()));

        socket->waitForBytesWritten(1000);
    }
    while(tcpclient::readFlag == false)
    {
        socket->waitForReadyRead(5000);
    }
    QString msg = tcpclient::readString;
    tcpclient::readFlag = false;

    qDebug() << "answer message: " << msg;
    return msg;
}

void tcpclient::start(QString ip, unsigned short port)
{
    socket = new QTcpSocket(this);
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));

    socket->connectToHost(ip, port); // pune ip si port din parametri
    if (socket->waitForConnected(3000))
    {
        qDebug() << "Connected...";
    }
    else
    {
        qDebug() << "Connection to server failed...";
        QMessageBox endMessage;
        //endMessage.setStyleSheet("QLabel {min-width:300 px; min-height: 50; font-size: 18px; } QPushButton{ width:10px; font-size: 12px; }");
        endMessage.setIcon(QMessageBox::Critical);
        endMessage.setText("Can't connect to server...");
        endMessage.setInformativeText("Application will close. Press button.");
        endMessage.setStandardButtons(QMessageBox::Close);
        endMessage.setDefaultButton(QMessageBox::Close);

        endMessage.exec();
        exit(0);
    }
}

void tcpclient::stop()
{
    if (this->socket->isOpen())
    {
        this->socket->close();
        qDebug() << "Socket closed...";
    }
}

tcpclient& tcpclient::getInstance()
{
    if( tcpclient::instance == nullptr )
    {
       tcpclient::instance = new tcpclient;
    }
    return *tcpclient::instance;
}

void tcpclient::destroyInstance()
{
    if( tcpclient::instance != nullptr )
    {
        delete tcpclient::instance;
    }
   tcpclient::instance = nullptr;
}

