#include "requestlogout.h"

RequestLogout::RequestLogout()
{

}

bool RequestLogout::_request()
{
   QString ans=tcpclient::getInstance().getData("Logout");
   return true;
}
