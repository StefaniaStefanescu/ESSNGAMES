#include "requestalltops.h"

RequestAllTops::RequestAllTops()
{

}

bool RequestAllTops::_request()
{
    return true;
}

QString RequestAllTops::_req()
{
    return tcpclient::getInstance().getData("7/");
}
