#pragma once
#include "IRequest.h"
class RequestJocDescriere :public IRequest
{
	string denumire;
	string raspuns;
public:
	RequestJocDescriere();
	RequestJocDescriere(string sentence);
	void gestionare_request();
	string gestionare_raspuns();

};

