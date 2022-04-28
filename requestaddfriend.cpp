#include "requestaddfriend.h"


RequestAddFriend::RequestAddFriend(QString me, QString username)
{
  fr.append("2");
  fr.append("/");
  fr.append(me);
  fr.append("/");
  fr.append(username);
  fr.append("/");

}

bool RequestAddFriend::_request()
{
    //if_server  send fr..
    QString data=tcpclient::getInstance().getData(fr);
    //qDebug()<<data;

    if(data=="OK"){
     return true;
    }
    return false;
    QString raspuns="OK";
    if(raspuns=="OK")
    {
        return true;
    }
    return false;
    //else
}
