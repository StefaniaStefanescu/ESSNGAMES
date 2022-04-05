#ifndef IUSER_H
#define IUSER_H
#include"cexceptie.h"

class IUser
{
public:
    IUser();
    ~IUser();
    virtual void sendCredentials(QString credentialsString)=0;
    virtual void addFriend(QString username)=0;
    virtual void deleteFriend(QString username)=0;
    virtual void LogOut()=0;
    virtual bool verifyconfirmation(QString passwd)=0;


};

#endif // IUSER_H
