#pragma once
#include "IRequest.h"
class RequestRegister :public IRequest
{
	string username;
	string password;
	string country;
	string region;
	string email;
	string birth_date;
	string raspuns;
public:
	RequestRegister();
	RequestRegister(string sentence);
	void gestionare_request();
	string gestionare_raspuns();

};

