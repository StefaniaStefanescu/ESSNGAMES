#include "chatw.h"
#include "ui_chatw.h"
#include"requestallchat.h"
#include"requestsendmessage.h"
chatw::chatw(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chatw)
{
    ui->setupUi(this);
    QString str;
    QStringList list;
    RequestAllChat req;
    str=req.Chat();
    list=str.split("/");
    foreach(QString item, list)
     {   if(item!="777"&item!=" ")
        {
            ui->chatlist->addItem(item);
        }
     }
    connect(&tcpclient::getInstance(),SIGNAL(realtimemessage(QString)),this,SLOT(addlivemessage(QString)));

}

chatw::~chatw()
{
    delete ui;
}

void chatw::on_sendpb_clicked()
{
    QString mesaj=ui->message->text();
    ui->message->clear();
    if(mesaj==""){
        return;
    }
    RequestSendMessage msg(mesaj);
    QString mymsg=msg.mymessage();

}

void chatw::addlivemessage(QString message)
{
    QStringList mes=message.split("/");
    ui->chatlist->addItem(mes[1]);
}

