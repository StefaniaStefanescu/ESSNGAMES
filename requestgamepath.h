#ifndef REQUESTGAMEPATH_H
#define REQUESTGAMEPATH_H

#include "irequest.h"

class RequestGamePath : public IRequest
{

public:
    RequestGamePath();
    ~RequestGamePath(){};
    bool _request();
    QString req(QString game);
};

#endif // REQUESTGAMEPATH_H
