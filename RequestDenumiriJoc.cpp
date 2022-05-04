#include "RequestDenumiriJoc.h"
#include "Utile.h"
#include "DB.h"

RequestDenumiriJoc::RequestDenumiriJoc()
{
	this->raspuns = nullptr;
}

RequestDenumiriJoc::RequestDenumiriJoc(string sentence)
{

}

void RequestDenumiriJoc::gestionare_request()
{
	this->raspuns = DB::create_Instance()->getDenumiriJoc();

}

string RequestDenumiriJoc::gestionare_raspuns()
{
	return this->raspuns;
}
