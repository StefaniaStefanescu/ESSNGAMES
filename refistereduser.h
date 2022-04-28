#ifndef REFISTEREDUSER_H
#define REFISTEREDUSER_H

#include "cuser.h"

class RefisteredUser : public CUser
{
  //nu am nevoie sa retin nimic la registered user
private:
    QString region;
    QString country;
    QString email;
    QString birthdate;
public:
    RefisteredUser(QString usern,QString passwd,QString reg,QString count,QString em,QString birth);
    ~RefisteredUser();
    bool sendCredentials();
    bool verifyconfirmation(QString passwd);
};

#endif // REFISTEREDUSER_H
