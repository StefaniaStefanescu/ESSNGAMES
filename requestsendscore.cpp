#include "requestsendscore.h"

RequestSendScore::RequestSendScore(QString gamee, int scoree):
game(gamee),score(scoree)
{

}

bool RequestSendScore::_request()
{
    QString str("8/");
    str.append((tcpclient::getInstance().getUsername()));
    str.append("/");
    str.append(game);
    str.append("/");
    str.append(score);
    str.append("/");
    QString data=tcpclient::getInstance().getData(str);
    if(data=="OK"){
        return true;
    }
    return false;

}
