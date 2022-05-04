#include "RequestLogout.h"
#include "Utile.h"
#include "DB.h"

RequestLogout::RequestLogout()
{
	this->log = nullptr;
	this->raspuns = nullptr;
}

RequestLogout::RequestLogout(string sentence)
{
	vector<string> sentences = Utile::split(sentence, '/');
	this->log = sentences[1];
}

void RequestLogout::gestionare_request()
{
	bool var = DB::create_Instance()->logoutUser(this->log);
	if (var)
	{
		this->raspuns = "OK";
	}
	else
	{
		this->raspuns = "NOK";
	}
}

string RequestLogout::gestionare_raspuns()
{
	return this->raspuns;
}
