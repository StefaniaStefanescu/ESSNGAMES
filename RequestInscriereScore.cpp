#include "RequestInscriereScore.h"
#include "Utile.h"
#include "DB.h"

RequestInscriereScore::RequestInscriereScore()
{
	this->username = nullptr;
	this->score = nullptr;
	this->denumire_joc = nullptr;
	this->raspuns = nullptr;
}

RequestInscriereScore::RequestInscriereScore(string sentence)
{
	vector<string> sentences = Utile::split(sentence, '/');
	this->username = sentences[1];
	this->denumire_joc = sentences[2];
	this->score = sentences[3];
}

void RequestInscriereScore::gestionare_request()
{
	bool var = DB::create_Instance()->InscriereScore(this->username, this->denumire_joc, this->score);
	if (var)
	{
		this->raspuns = "OK";
	}
	else
	{
		this->raspuns = "NOK";
	}
}

string RequestInscriereScore::gestionare_raspuns()
{
	return this->raspuns;
}
