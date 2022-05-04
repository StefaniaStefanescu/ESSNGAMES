#include "RequestImage.h"
#include "Utile.h"
#include "DB.h"

RequestImage::RequestImage()
{
	this->denumire = nullptr;
	this->raspuns = nullptr;
}

RequestImage::RequestImage(string sentence)
{
	vector<string> sentences = Utile::split(sentence, '/');
	this->denumire = sentences[1];
}

void RequestImage::gestionare_request()
{
	this->raspuns = DB::create_Instance()->pathImage(this->denumire);

}

string RequestImage::gestionare_raspuns()
{
	return this->raspuns;
}
