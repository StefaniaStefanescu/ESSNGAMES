#ifndef REQUESTREGISTER_H
#define REQUESTREGISTER_H

#include "irequest.h"

class RequestRegister : public IRequest
{
protected:
    QString creds;
public:
    RequestRegister(QString credentials);
    ~RequestRegister(){};
    bool _request();
};

#endif // REQUESTREGISTER_H
