#include "RequestInsertChat.h"
#include "Utile.h"
#include "DB.h"

RequestInsertChat::RequestInsertChat()
{
	this->username = nullptr;
	this->mesaj = nullptr;
	this->raspuns = nullptr;
}

RequestInsertChat::RequestInsertChat(string sentence)
{
	vector<string> sentences = Utile::split(sentence, '/');
	this->username = sentences[1];
	this->mesaj = sentences[2];
}

void RequestInsertChat::gestionare_request()
{
	this->raspuns = DB::create_Instance()->InsertChat(this->username, this->mesaj);
}

string RequestInsertChat::gestionare_raspuns()
{
	return this->raspuns;
}
