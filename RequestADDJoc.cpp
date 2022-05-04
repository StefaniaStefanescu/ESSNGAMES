#include "RequestADDJoc.h"
#include "Utile.h"
#include "DB.h"

RequestADDJoc::RequestADDJoc()
{
	this->denumire = nullptr;
	this->descriere = nullptr;
	this->path = nullptr;
	this->raspuns = nullptr;
}

RequestADDJoc::RequestADDJoc(string sentence)
{
	vector<string> sentences = Utile::split(sentence, '/');
	this->denumire = sentences[1];
	this->descriere = sentences[2];
	this->path = sentences[3];
}

void RequestADDJoc::gestionare_request()
{
	bool var = DB::create_Instance()->addJoc(this->denumire, this->descriere, this->path);
	if (var)
	{
		this->raspuns = "OK";
	}
	else
	{
		this->raspuns = "NOK";
	}
}

string RequestADDJoc::gestionare_raspuns()
{
	return this->raspuns;
}
