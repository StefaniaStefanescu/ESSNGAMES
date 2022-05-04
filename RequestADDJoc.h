#pragma once
#include "IRequest.h"
class RequestADDJoc :public IRequest
{
	string denumire;
	string descriere;
	string path;
	string raspuns;
public:
	RequestADDJoc();
	RequestADDJoc(string sentence);
	void gestionare_request();
	string gestionare_raspuns();
};

