#pragma once
#include "IRequest.h"
class RequestInscriereScore :public IRequest
{
	string username;
	string denumire_joc;
	string score;
	string raspuns;
public:
	RequestInscriereScore();
	RequestInscriereScore(string sentence);
	void gestionare_request();
	string gestionare_raspuns();
};

