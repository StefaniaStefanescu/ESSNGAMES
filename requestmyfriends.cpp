#include "requestmyfriends.h"

RequestMyFriends::RequestMyFriends()
{
   mine.append("4/");


}

bool RequestMyFriends::_request()
{
    return true;
}

QString RequestMyFriends::_req()
{
    mine.append(tcpclient::getInstance().getUsername());
    mine.append("/");
    QString data=tcpclient::getInstance().getData(mine);
    return data;
}
