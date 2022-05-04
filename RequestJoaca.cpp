#include "RequestJoaca.h"
#include "Utile.h"
#include "DB.h"

RequestJoaca::RequestJoaca()
{
	this->denumire = nullptr;
	this->raspuns = nullptr;
}

RequestJoaca::RequestJoaca(string sentence)
{
	vector<string> sentences = Utile::split(sentence, '/');
	this->denumire = sentences[1];
}

void RequestJoaca::gestionare_request()
{
	this->raspuns = DB::create_Instance()->pathJoc(this->denumire);

}

string RequestJoaca::gestionare_raspuns()
{
	return this->raspuns;
}
