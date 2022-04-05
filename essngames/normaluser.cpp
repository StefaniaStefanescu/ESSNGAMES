#include "normaluser.h"

NormalUser::NormalUser(QString usern, QString passwd):CUser(usern,passwd)
{
}

void NormalUser::sendCredentials(QString credentialsString)
{

}

bool NormalUser::verifyconfirmation(QString passwd)
{
    return true;
}
