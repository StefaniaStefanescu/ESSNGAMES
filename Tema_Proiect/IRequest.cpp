#include "IRequest.h"
#include "RequestLogin.h"
#include "RequestRegister.h"
#include "RequestADDFriend.h"
#include "RequestAllTops.h"
#include "RequestGetAllFriends.h"
#include "RequestJocDescriere.h"
#include "RequestTop.h"
#include "RequestDeleteFriend.h"

IRequest* IRequest::Factory::getRequest(string sentence)
{

	switch (sentence[0])
	{
	case '0':
		return new RequestRegister(sentence);
	case '1':
		return new RequestLogin(sentence);
	case '2':
		return new RequestADDFriend(sentence);
	case '3':
		return new RequestDeleteFriend(sentence);
	case '4':
		return new RequestGetAllFriends(sentence);
	case '5':
		return new RequestJocDescriere(sentence);
	case '6':
		return new RequestAllTops(sentence);
	case '7':
		return new RequestTop(sentence);
	default:
		break;
	}
}
