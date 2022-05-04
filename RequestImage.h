#pragma once
#include "IRequest.h"
class RequestImage :public IRequest
{
	string denumire;
	string raspuns;
public:
	RequestImage();
	RequestImage(string sentence);
	void gestionare_request();
	string gestionare_raspuns();

};

