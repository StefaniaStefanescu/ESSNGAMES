#include "cuser.h"

CUser::CUser(QString usern, QString passwd)
{
    this->username=usern;
    this->password=passwd;
}

CUser::~CUser()
{

}

bool CUser::addFriend(QString username)
{
    //cauta serverul si sterge prietenul din baza de date
    //in functie de ceea ce returneaza aceasta functie butonul add efectueaza operatia
    return true;
}

bool CUser::deleteFriend(QString username)
{
    //cauta serverul si sterge prietenul din baza de date
    //in functie de ceea ce returneaza aceasta functie butonul delete efectueaza operatia
    return true;
}

void CUser::LogOut()
{
    //inchiderea aplicatiei :)

}
