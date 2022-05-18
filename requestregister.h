#ifndef REQUESTREGISTER_H
#define REQUESTREGISTER_H

#include "irequest.h"


class RequestRegister : public IRequest
{
protected:
    QString creds;
public:
    RequestRegister(QString usern,QString passwd,QString reg,QString count,QString em,QString birth);
    ~RequestRegister(){};
    bool _request();
};

#endif // REQUESTREGISTER_H
