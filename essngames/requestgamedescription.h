#ifndef REQUESTGAMEDESCRIPTION_H
#define REQUESTGAMEDESCRIPTION_H

#include "irequest.h"

class RequestGameDescription : public IRequest
{
protected:
    QString ngame;
public:
    RequestGameDescription(QString game);
    ~RequestGameDescription(){};
    bool _request();
};

#endif // REQUESTGAMEDESCRIPTION_H
