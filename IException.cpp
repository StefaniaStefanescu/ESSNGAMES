#include "IException.h"
#include "errRegister.h"
#include "errLogin.h"
#include "errADDFriend.h"
#include "errDeleteFriend.h"
#include "errAllTops.h"
#include "errTop.h"
#include "errGetAllFriends.h"
#include "errJocDescriere.h"
#include "errInscriereScore.h"
#include "errInsertChat.h"
#include "errSelectChat.h"
#include "errPathJoc.h"
#include "errSchimbaParola.h"
#include "errDenumiriJoc.h"
#include "errADDJoc.h"
#include "errPathImage.h"

IException* IException::Factory::err_Register()
{
    return new errRegister();
}

IException* IException::Factory::err_Login()
{
    return new errLogin();
}

IException* IException::Factory::err_ADDFriend()
{
    return new errADDFriend();
}

IException* IException::Factory::err_DeleteFriend()
{
    return new errDeleteFriend();
}

IException* IException::Factory::err_GetAllFriends()
{
    return new errGetAllFriends();
}

IException* IException::Factory::err_Top()
{
    return new errTop();
}
IException* IException::Factory::err_AllTops()
{
    return new errAllTops();
}

IException* IException::Factory::err_JocDescriere()
{
    return new errJocDescriere();
}

IException* IException::Factory::err_InscriereScore()
{
    return new errInscriereScore();
}

IException* IException::Factory::err_InsertChat()
{
    return new errInsertChat();
}

IException* IException::Factory::err_SelectChat()
{
    return new errSelectChat();
}

IException* IException::Factory::err_PathJoc()
{
    return new errPathJoc();
}

IException* IException::Factory::err_SchimbaParola()
{
    return new errSchimbaParola();
}

IException* IException::Factory::err_DenumiriJoc()
{
    return new errDenumiriJoc();
}

IException* IException::Factory::err_ADDJoc()
{
    return new errADDJoc();
}

IException* IException::Factory::err_PathImage()
{
    return new errPathImage();
}