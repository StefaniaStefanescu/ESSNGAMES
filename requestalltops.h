#ifndef REQUESTALLTOPS_H
#define REQUESTALLTOPS_H

#include "irequest.h"

class RequestAllTops : public IRequest
{
public:
    RequestAllTops();
    ~RequestAllTops(){};
    bool _request();
    QString _req();
};

#endif // REQUESTALLTOPS_H
