#ifndef REQUESTDELETEFRIEND_H
#define REQUESTDELETEFRIEND_H

#include "irequest.h"

class RequestDeleteFriend : public IRequest
{
protected:
    QString fr;
public:
    RequestDeleteFriend(QString me,QString username);
    ~RequestDeleteFriend(){};
     bool _request();
};

#endif // REQUESTDELETEFRIEND_H
