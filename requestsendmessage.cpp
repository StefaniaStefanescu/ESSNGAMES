#include "requestsendmessage.h"


RequestSendMessage::RequestSendMessage(QString message)
{
    tosend.append("10/");
    tosend.append(tcpclient::getInstance().getUsername());
    tosend.append("/");
    tosend.append(message);
    tosend.append("/");
}

bool RequestSendMessage::_request()
{

     return true;

}

QString RequestSendMessage::mymessage()
{
    return tcpclient::getInstance().getData(tosend);
}
