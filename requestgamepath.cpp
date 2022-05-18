#include "requestgamepath.h"

RequestGamePath::RequestGamePath()
{
}

bool RequestGamePath::_request()
{
    return true;
}

QString RequestGamePath::req(QString game)
{
    QString ngame;
    ngame.append("11/");
    ngame.append(game);
     ngame.append("/");
    return tcpclient::getInstance().getData(ngame);
}
