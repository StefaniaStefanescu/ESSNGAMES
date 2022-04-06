#pragma once
#include "IRequest.h"
class RequestTop :public IRequest
{
	string denumire_joc;
	string raspuns;
public:
	RequestTop();
	RequestTop(string sentence);
	void gestionare_request();
	string gestionare_raspuns();
};

