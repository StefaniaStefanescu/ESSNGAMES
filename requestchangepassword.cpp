#include "requestchangepassword.h"

RequestChangePassword::RequestChangePassword(QString username,QString email,QString newpassword)
{
    tosend.append("12/");
    tosend.append(username);
    tosend.append("/");
    tosend.append(newpassword);
    tosend.append("/");
}

bool RequestChangePassword::_request()
{
    QString raspuns=tcpclient::getInstance().getData(tosend);
    if(raspuns=="OK"){
        return true;
    }else return false;
}
