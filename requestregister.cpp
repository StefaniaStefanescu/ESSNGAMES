#include "requestregister.h"

RequestRegister::RequestRegister(QString user,QString pass,QString Country,QString Region,QString Email,QString Birth)
{
    QString bara{"/"};
    QString unu{"0"};
   //username,password,country,region,email,birthdate
    creds.append(unu);
    creds.append(bara);
    creds.append(user);
    creds.append(bara);
    creds.append(pass);
    creds.append(bara);
    creds.append(Country);
    creds.append(bara);
    creds.append(Region);
    creds.append(bara);
    creds.append(Email);
    creds.append(bara);
    creds.append(Birth);
    creds.append(bara);
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
