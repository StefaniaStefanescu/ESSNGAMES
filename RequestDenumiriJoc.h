#pragma once
#include "IRequest.h"
class RequestDenumiriJoc :public IRequest
{
	string raspuns;
public:
	RequestDenumiriJoc();
	RequestDenumiriJoc(string sentence);
	void gestionare_request();
	string gestionare_raspuns();

};

