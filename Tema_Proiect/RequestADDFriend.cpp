#include "RequestADDFriend.h"
#include "Utile.h"
#include "DB.h"

RequestADDFriend::RequestADDFriend()
{
	this->host = nullptr;
	this->prieten = nullptr;
	this->raspuns = nullptr;
}

RequestADDFriend::RequestADDFriend(string sentence)
{
	vector<string> sentences = Utile::split(sentence, '/');
	this->host = sentences[1];
	this->prieten = sentences[2];
}

void RequestADDFriend::gestionare_request()
{
	bool var = DB::create_Instance()->addFriend(this->host, this->prieten);
	if (var)
	{
		this->raspuns = "OK";
	}
	else
	{
		this->raspuns = "NOK";
	}
}

string RequestADDFriend::gestionare_raspuns()
{
	return this->raspuns;
}
