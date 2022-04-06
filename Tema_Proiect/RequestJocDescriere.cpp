#include "RequestJocDescriere.h"
#include "Utile.h"
#include "DB.h"

RequestJocDescriere::RequestJocDescriere()
{
	this->denumire = nullptr;
	this->raspuns = nullptr;
}

RequestJocDescriere::RequestJocDescriere(string sentence)
{
	vector<string> sentences = Utile::split(sentence, '/');
	this->denumire = sentences[1];
}

void RequestJocDescriere::gestionare_request()
{
	this->raspuns = DB::create_Instance()->denumireJoc(this->denumire);

}

string RequestJocDescriere::gestionare_raspuns()
{
	return this->raspuns;
}
