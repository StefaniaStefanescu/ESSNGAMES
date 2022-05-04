#include "IRequest.h"
#include "Utile.h"
#include "RequestLogin.h"
#include "RequestRegister.h"
#include "RequestADDFriend.h"
#include "RequestAllTops.h"
#include "RequestGetAllFriends.h"
#include "RequestJocDescriere.h"
#include "RequestTop.h"
#include "RequestDeleteFriend.h"
#include "RequestInscriereScore.h"
#include "RequestChat.h"
#include "RequestJoaca.h"
#include "RequestSchimbaParola.h"
#include "RequestDenumiriJoc.h"
#include "RequestADDJoc.h"
#include "RequestInsertChat.h"

IRequest* IRequest::Factory::getRequest(string sentence)
{
	string key = Utile::split(sentence, '/')[0];
	if (key == "0")
	{
		return new RequestRegister(sentence);
	}
	else if (key == "1")
	{
		return new RequestLogin(sentence);
	}
	else if (key == "2")
	{
		return new RequestADDFriend(sentence);
	}
	else if (key == "3")
	{
		return new RequestDeleteFriend(sentence);
	}
	else if (key == "4")
	{
		return new RequestGetAllFriends(sentence);
	}
	else if (key == "5")
	{
		return new RequestJocDescriere(sentence);
	}
	else if (key == "6")
	{
		return new RequestTop(sentence);
	}
	else if (key == "7")
	{
		return new RequestAllTops(sentence);
	}
	else if (key == "8")
	{
		return new RequestInscriereScore(sentence);
	}
	else if (key == "9") //incarcare chat
	{
		return new RequestChat(sentence);
	}
	else if (key == "10")
	{
		return new RequestInsertChat(sentence);
	}
	else if (key == "11")
	{
		return new RequestJoaca(sentence);
	}
	else if (key == "12")
	{
		return new RequestSchimbaParola(sentence);
	}
	else if (key == "13")
	{
		return new RequestDenumiriJoc(sentence);
	}
	else if (key == "14")
	{
		return new RequestADDJoc(sentence);
	}
}
