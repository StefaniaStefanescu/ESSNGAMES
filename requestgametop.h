#ifndef REQUESTGAMETOP_H
#define REQUESTGAMETOP_H

#include "irequest.h"

class RequestGameTop : public IRequest
{
private:
    QString ngame;
public:
    RequestGameTop(QString game);
    ~RequestGameTop(){};
    bool _request();
    QString req();
};

#endif // REQUESTGAMETOP_H
