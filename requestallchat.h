#ifndef REQUESTALLCHAT_H
#define REQUESTALLCHAT_H

#include "irequest.h"

class RequestAllChat : public IRequest
{
private:
    QString prot;
public:
    RequestAllChat();
    ~RequestAllChat(){};
    bool _request();
    QString Chat();
};

#endif // REQUESTALLCHAT_H
