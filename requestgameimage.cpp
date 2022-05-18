#include "requestgameimage.h"

RequestGameImage::RequestGameImage(QString game)
{
    ngame.append("13/");
    ngame.append(game);
    ngame.append("/");
}

bool RequestGameImage::_request()
{
    return true;
}

QString RequestGameImage::req()
{
     return tcpclient::getInstance().getData(ngame);
}
