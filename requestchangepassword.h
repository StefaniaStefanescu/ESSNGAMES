#ifndef REQUESTCHANGEPASSWORD_H
#define REQUESTCHANGEPASSWORD_H

#include "irequest.h"

class RequestChangePassword : public IRequest
{
private:
    QString tosend;
public:
    RequestChangePassword(QString username,QString email,QString newpassword);
    ~RequestChangePassword(){};
    bool _request();
};

#endif // REQUESTCHANGEPASSWORD_H
