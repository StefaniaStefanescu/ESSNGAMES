#ifndef REQUESTSENDSCORE_H
#define REQUESTSENDSCORE_H

#include "irequest.h"

class RequestSendScore : public IRequest
{
private:
    QString game;
    int score;
public:
    RequestSendScore(QString gamee,int scoree);
    ~RequestSendScore(){};
    bool _request();
};

#endif // REQUESTSENDSCORE_H
