#include "requestallchat.h"

RequestAllChat::RequestAllChat():prot("9/")
{

}

bool RequestAllChat::_request()
{
    return true;
}

QString RequestAllChat::Chat()
{
    return tcpclient::getInstance().getData(prot);
}
