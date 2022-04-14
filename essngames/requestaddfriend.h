#ifndef REQUESTADDFRIEND_H
#define REQUESTADDFRIEND_H

#include "irequest.h"

class RequestAddFriend : public IRequest
{
protected:
    QString fr;
public:
    RequestAddFriend(QString username);
    ~RequestAddFriend(){};
    bool _request();

};

#endif // REQUESTADDFRIEND_H
