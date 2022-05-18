#ifndef CEXCEPTIE_H
#define CEXCEPTIE_H

#include "iexceptie.h"

class CExceptie : public IExceptie
{
public:
    CExceptie();

    void LoginError();
    void RegisterError();
    void WrongConfirmation();
    void NotAbleToConnect();
    void WaitedforToMuchTime();
    void DisableConnection();
    void AddFriendError();
    void DeleteFriendError();


};

#endif // CEXCEPTIE_H
