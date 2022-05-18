#include "cuser.h"
#include"requestaddfriend.h"
#include"requestdeletefriend.h"
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
   RequestAddFriend requestt(this->username,username);
   return requestt._request();

}

bool CUser::deleteFriend(QString username)
{
   RequestDeleteFriend requestt(this->username,username);
   return requestt._request();
}

void CUser::LogOut()
{
    //inchiderea aplicatiei :)

}
