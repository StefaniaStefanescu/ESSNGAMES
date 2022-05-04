#include "RequestSchimbaParola.h"
#include "Utile.h"
#include "DB.h"

RequestSchimbaParola::RequestSchimbaParola()
{
	this->username = nullptr;
	this->nouaparola = nullptr;
	this->raspuns = nullptr;
}

RequestSchimbaParola::RequestSchimbaParola(string sentence)
{
	vector<string> sentences = Utile::split(sentence, '/');
	this->username = sentences[1];
	this->nouaparola = sentences[2];
}

void RequestSchimbaParola::gestionare_request()
{
	bool var = DB::create_Instance()->SchimbaParola(this->username, this->nouaparola);
	if (var)
	{
		this->raspuns = "OK";
	}
	else
	{
		this->raspuns = "NOK";
	}
}

string RequestSchimbaParola::gestionare_raspuns()
{
	return this->raspuns;
}
