#pragma once
#include "IRequest.h"
class RequestJoaca :public IRequest
{
	string denumire;
	string raspuns;
public:
	RequestJoaca();
	RequestJoaca(string sentence);
	void gestionare_request();
	string gestionare_raspuns();

};

