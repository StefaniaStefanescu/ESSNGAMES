#include "RequestRegister.h"
#include "Utile.h"
#include "DB.h"

RequestRegister::RequestRegister()
{
	this->username = nullptr;
	this->password = nullptr;
	this->country = nullptr;
	this->region = nullptr;
	this->email = nullptr;
	this->birth_date = nullptr;
	this->raspuns = nullptr;
}

RequestRegister::RequestRegister(string sentence)
{
	vector<string> sentences = Utile::split(sentence, '/');
	this->username = sentences[1];
	this->password = sentences[2];
	this->country = sentences[3];
	this->region = sentences[4];
	this->email = sentences[5];
	this->birth_date= sentences[6];
}

void RequestRegister::gestionare_request()
{
	bool var = DB::create_Instance()->registerUser(this->username, this->password, this->country, this->region, this->email, this->birth_date);
	if (var)
	{
		this->raspuns = "OK";
	}
	else
	{
		this->raspuns = "NOK";
	}
}

string RequestRegister::gestionare_raspuns()
{
	return this->raspuns;
}
