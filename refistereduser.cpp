#include "refistereduser.h"
#include"requestregister.h"
RefisteredUser::RefisteredUser(QString usern,QString passwd,QString reg,QString count,QString em,QString birth):CUser(usern,passwd),
  region(reg),country(count),email(em),birthdate(birth)
{
}

bool RefisteredUser::sendCredentials()
{
    //aici sparg sirul de caractere si trimit catre server pentru verificare
    //posibil sa am nevoie de ele ca fiind bool
    //o sa afisez un mesaj de eroare daca e cazul

    RequestRegister req(username,password,country,region,email,birthdate);
    return req._request();
}

bool RefisteredUser::verifyconfirmation(QString passwd)
{
    if(this->password==passwd){
        return true;
    }
    return false;
}
