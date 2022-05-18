#ifndef REQUESTMYFRIENDS_H
#define REQUESTMYFRIENDS_H

#include "irequest.h"

class RequestMyFriends : public IRequest
{
private:
    QString mine;
public:
    RequestMyFriends();
    ~RequestMyFriends(){};
    bool _request();
    QString _req();
};

#endif // REQUESTMYFRIENDS_H
