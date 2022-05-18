#ifndef IUSER_H
#define IUSER_H
#include"cexceptie.h"

class IUser
{
public:
    IUser();
    ~IUser();
    virtual bool sendCredentials()=0;
    virtual bool addFriend(QString username)=0;
    virtual bool deleteFriend(QString username)=0;
    virtual void LogOut()=0;
    virtual bool verifyconfirmation(QString passwd)=0;


};

#endif // IUSER_H
