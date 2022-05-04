#ifndef CUSER_H
#define CUSER_H

#include "iuser.h"

class CUser : public IUser
{
protected:
    QString username;
    QString password;

public:
    CUser(QString usern,QString passwd);
    ~CUser();
    bool addFriend(QString username);
    bool deleteFriend(QString username);
    virtual bool sendCredentials()=0;
    void LogOut();
    virtual bool verifyconfirmation(QString passwd)=0;
};

#endif // CUSER_H
