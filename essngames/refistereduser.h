#ifndef REFISTEREDUSER_H
#define REFISTEREDUSER_H

#include "cuser.h"

class RefisteredUser : public CUser
{
  //nu am nevoie sa retin nimic la registered user
public:
    RefisteredUser(QString usern,QString passwd);
    ~RefisteredUser();
    void sendCredentials(QString credentialsString);
    bool verifyconfirmation(QString passwd);
};

#endif // REFISTEREDUSER_H
