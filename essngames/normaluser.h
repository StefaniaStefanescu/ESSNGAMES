#ifndef NORMALUSER_H
#define NORMALUSER_H

#include "cuser.h"

class NormalUser : public CUser
{
public:
    NormalUser(QString usern,QString passwd);
    ~NormalUser(){};
    void sendCredentials(QString credentialsString);
    bool verifyconfirmation(QString passwd);
};

#endif // NORMALUSER_H
