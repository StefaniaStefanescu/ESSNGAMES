#include "RequestTop.h"
#include "Utile.h"
#include "DB.h"

RequestTop::RequestTop()
{
	this->denumire_joc = nullptr;
	this->raspuns = nullptr;
}

RequestTop::RequestTop(string sentence)
{
	vector<string> sentences = Utile::split(sentence, '/');
	this->denumire_joc = sentences[1];
}

void RequestTop::gestionare_request()
{
	this->raspuns= DB::create_Instance()->topScore(this->denumire_joc);
}

string RequestTop::gestionare_raspuns()
{
	return this->raspuns;
}
