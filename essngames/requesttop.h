#ifndef REQUESTTOP_H
#define REQUESTTOP_H

#include "irequest.h"

class RequestTop : public IRequest
{
protected:
    QString ngame;
public:
    RequestTop(QString game);
    ~RequestTop();
    bool _request();
};

#endif // REQUESTTOP_H
