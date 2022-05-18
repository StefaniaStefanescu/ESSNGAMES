#include "requestlogout.h"

RequestLogout::RequestLogout()
{

}

bool RequestLogout::_request()
{
   QString ans=tcpclient::getInstance().getData("15/Logout/");
   return true;
}
