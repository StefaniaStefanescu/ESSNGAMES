#pragma once
#include "IRequest.h"
class RequestAllTops :public IRequest
{
	string raspuns;
public:
	RequestAllTops();
	RequestAllTops(string sentence);
	void gestionare_request();
	string gestionare_raspuns();
};

