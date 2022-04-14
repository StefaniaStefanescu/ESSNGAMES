#ifndef IREQUEST_H
#define IREQUEST_H

#include "socket.h"
class IRequest
{
public:
    IRequest();
    virtual bool _request()=0;
protected:
    Socket msocket;
};

#endif // IREQUEST_H
