#pragma once
#include "IRequest.h"
class RequestDeleteFriend :public IRequest
{
	string host;
	string prieten;
	string raspuns;
public:
	RequestDeleteFriend();
	RequestDeleteFriend(string sentence);
	void gestionare_request();
	string gestionare_raspuns();
};

