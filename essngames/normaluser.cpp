#include "normaluser.h"

NormalUser::NormalUser(QString usern, QString passwd):CUser(usern,passwd)
{
}

bool NormalUser::sendCredentials()
{
  QString bara{"/"};
  QString unu{"1"};
  QString credentials;
  credentials.reserve(username.length()+unu.length()+bara.length()+bara.length()+password.length());
  credentials.append(unu);
  credentials.append(bara);
  credentials.append(username);
  credentials.append(bara);
  credentials.append(password);
  //send to server

  return true;
}

bool NormalUser::verifyconfirmation(QString passwd)
{
    if(this->password==passwd)
    {
        return true;
    }
    return false;
}
