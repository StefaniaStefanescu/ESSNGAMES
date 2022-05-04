#pragma once
#include "IRequest.h"
class RequestChat :public IRequest
{
	string raspuns;
public:
	RequestChat();
	RequestChat(string sentence);
	void gestionare_request();
	string gestionare_raspuns();
};

