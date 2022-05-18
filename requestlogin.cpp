#include "requestlogin.h"
#include<QDebug>

RequestLogin::RequestLogin(QString credentials):creds(credentials)
{

}

bool RequestLogin::_request()
{
    //send creds to server
    QString data=tcpclient::getInstance().getData(creds);
    //qDebug()<<data;

    if(data=="OK"){
     return true;
    }
    else{
        CExceptie exc;
        exc.LoginError();
    }
    return false;
}
