#pragma once
#include "IRequest.h"
class RequestInsertChat :public IRequest
{
	string username;
	string mesaj;
	string raspuns;
public:
	RequestInsertChat();
	RequestInsertChat(string sentence);
	void gestionare_request();
	string gestionare_raspuns();
};

