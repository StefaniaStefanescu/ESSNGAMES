#ifndef REQUESTSENDMESSAGE_H
#define REQUESTSENDMESSAGE_H

#include "irequest.h"

class RequestSendMessage : public IRequest
{
private:
    QString tosend;
public:
    RequestSendMessage(QString message);
    ~RequestSendMessage(){};
    bool _request();
    QString mymessage();

};

#endif // REQUESTSENDMESSAGE_H
