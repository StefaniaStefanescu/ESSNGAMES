#include "requestdeletefriend.h"


RequestDeleteFriend::RequestDeleteFriend(QString username):fr(username)
{

}

bool RequestDeleteFriend::_request()
{
    return true;
}
