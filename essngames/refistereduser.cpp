#include "refistereduser.h"

RefisteredUser::RefisteredUser(QString usern,QString passwd):CUser(usern,passwd)
{

}

void RefisteredUser::sendCredentials(QString credentialsString)
{
    //aici sparg sirul de caractere si trimit catre server pentru verificare
    //posibil sa am nevoie de ele ca fiind bool
    //o sa afisez un mesaj de eroare daca e cazul

}

bool RefisteredUser::verifyconfirmation(QString passwd)
{
    if(this->password==passwd){
        return true;
    }
    return false;
}
