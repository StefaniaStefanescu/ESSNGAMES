#include "requestregister.h"

RequestRegister::RequestRegister(QString credentials):creds(credentials)
{

}

bool RequestRegister::_request()
{
    // 1/username/password
    // 2/username/pass/reg/...
    QString data=tcpclient::getInstance().getData(creds);
    //qDebug()<<data;

    if(data=="OK"){
     return true;
    }else{
      CExceptie exc;
      exc.RegisterError();
      return false;
    }

}
