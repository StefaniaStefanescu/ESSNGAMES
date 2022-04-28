#include "requestdeletefriend.h"


RequestDeleteFriend::RequestDeleteFriend(QString me, QString username)
{
    fr.append("3");
    fr.append("/");
    fr.append(me);
    fr.append("/");
    fr.append(username);
    fr.append("/");

}

bool RequestDeleteFriend::_request()
{
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
