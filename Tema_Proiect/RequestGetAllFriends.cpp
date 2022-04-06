#include "RequestGetAllFriends.h"
#include "Utile.h"
#include "DB.h"

RequestGetAllFriends::RequestGetAllFriends()
{
	this->host = nullptr;
	this->raspuns = nullptr;
}

RequestGetAllFriends::RequestGetAllFriends(string sentence)
{
	vector<string> sentences = Utile::split(sentence, '/');
	this->host = sentences[1];
}

void RequestGetAllFriends::gestionare_request()
{
	this->raspuns = DB::create_Instance()->getallFriends(this->host);

}

string RequestGetAllFriends::gestionare_raspuns()
{
	return this->raspuns;
}
