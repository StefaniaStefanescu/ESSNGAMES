#pragma once
#include "IRequest.h"
class RequestSchimbaParola :public IRequest
{
	string username;
	string nouaparola;
	string raspuns;
public:
	RequestSchimbaParola();
	RequestSchimbaParola(string sentence);
	void gestionare_request();
	string gestionare_raspuns();
};

