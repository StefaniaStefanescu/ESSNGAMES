#include "RequestDeleteFriend.h"
#include "Utile.h"
#include "DB.h"

RequestDeleteFriend::RequestDeleteFriend()
{
	this->host = nullptr;
	this->prieten = nullptr;
	this->raspuns = nullptr;
}

RequestDeleteFriend::RequestDeleteFriend(string sentence)
{
	vector<string> sentences = Utile::split(sentence, '/');
	this->host = sentences[1];
	this->prieten = sentences[2];
}

void RequestDeleteFriend::gestionare_request()
{
	bool var = DB::create_Instance()->deleteFriend(this->host, this->prieten);
	if (var)
	{
		this->raspuns = "OK";
	}
	else
	{
		this->raspuns = "NOK";
	}
}

string RequestDeleteFriend::gestionare_raspuns()
{
	return this->raspuns;
}
