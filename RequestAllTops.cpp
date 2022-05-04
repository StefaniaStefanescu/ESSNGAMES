#include "RequestAllTops.h"
#include "Utile.h"
#include "DB.h"

RequestAllTops::RequestAllTops()
{
	this->raspuns = nullptr;
}

RequestAllTops::RequestAllTops(string sentence)
{
	
}

void RequestAllTops::gestionare_request()
{
	this->raspuns = DB::create_Instance()->allTopsScore();
}

string RequestAllTops::gestionare_raspuns()
{
	return this->raspuns;
}
