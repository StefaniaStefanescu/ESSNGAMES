#ifndef REQUESTGAMEIMAGE_H
#define REQUESTGAMEIMAGE_H

#include "irequest.h"

class RequestGameImage : public IRequest
{
private:
    QString ngame;
public:
    RequestGameImage(QString game);
    ~RequestGameImage(){};
    bool _request();
    QString req();
};

#endif // REQUESTGAMEIMAGE_H
