#pragma once
#include "IRequest.h"
class RequestADDFriend :public IRequest
{
	string host;
	string prieten;
	string raspuns;
public:
	RequestADDFriend();
	RequestADDFriend(string sentence);
	void gestionare_request();
	string gestionare_raspuns();
};

