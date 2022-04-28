#include "requesttop.h"

RequestTop::RequestTop(QString game)
{
  ngame.append("6/");
  ngame.append(game);
}

bool RequestTop::_request()
{
    //primesc un string cu username si scor
    return true;
}

QString RequestTop::_req()
{

    QString data=tcpclient::getInstance().getData(ngame);
    return data;

}
