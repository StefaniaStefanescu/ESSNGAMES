#include "refistereduser.h"

RefisteredUser::RefisteredUser(QString usern,QString passwd,QString reg,QString count,QString em,QString birth):CUser(usern,passwd),
  region(reg),country(count),email(em),birthdate(birth)
{
}

bool RefisteredUser::sendCredentials()
{
    //aici sparg sirul de caractere si trimit catre server pentru verificare
    //posibil sa am nevoie de ele ca fiind bool
    //o sa afisez un mesaj de eroare daca e cazul
    QString bara{"/"};
    QString unu{"2"};
    QString credentials;
    credentials.reserve(username.length()+unu.length()+bara.length()+bara.length()+bara.length()+bara.length()+bara.length()+bara.length()+password.length()+
                        region.length()+country.length()+email.length()+birthdate.length());
    credentials.append(unu);
    credentials.append(bara);
    credentials.append(username);
    credentials.append(bara);
    credentials.append(password);
     credentials.append(bara);
    credentials.append(country);
     credentials.append(bara);
    credentials.append(region);
     credentials.append(bara);
    credentials.append(email);
     credentials.append(bara);
    credentials.append(birthdate);
    //send to server
    //get answer
    //return answer

    return true;
}

bool RefisteredUser::verifyconfirmation(QString passwd)
{
    if(this->password==passwd){
        return true;
    }
    return false;
}
