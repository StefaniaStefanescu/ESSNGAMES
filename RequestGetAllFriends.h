#pragma once
#include "IRequest.h"
class RequestGetAllFriends :public IRequest
{
	string host;
	string raspuns;
public:
	RequestGetAllFriends();
	RequestGetAllFriends(string sentence);
	void gestionare_request();
	string gestionare_raspuns();
};

