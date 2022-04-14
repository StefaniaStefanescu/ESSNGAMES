#include "requestgamedescription.h"


RequestGameDescription::RequestGameDescription(QString game):ngame(game)
{

}

bool RequestGameDescription::_request()
{
   //if server allows I can show the description , otherwise I can't
  return true;
}
