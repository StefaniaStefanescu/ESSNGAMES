#include "requestgametop.h"



RequestGameTop::RequestGameTop(QString game)
{
    ngame.append("6/");
    ngame.append(game);
    ngame.append("/");
}

bool RequestGameTop::_request()
{

    return true;
}

QString RequestGameTop::req()
{
    return tcpclient::getInstance().getData(ngame);
}
