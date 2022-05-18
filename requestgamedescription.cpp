#include "requestgamedescription.h"


RequestGameDescription::RequestGameDescription(QString game)
{
  ngame.append("5/");
  ngame.append(game);
  ngame.append("/");
}

//primesc un string cu descrierea si modific in functie de ea pt un return
bool RequestGameDescription::_request()
{
   //if server allows I can show the description , otherwise I can't
    //if_server  send game
    //raspunsul o sa fie un string pe care il returnez in functie

        return true; 
}

QString RequestGameDescription::_req()
{
    QString data=tcpclient::getInstance().getData(ngame);
    return data;
}
