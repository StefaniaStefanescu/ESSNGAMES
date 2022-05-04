#include "RequestChat.h"
#include "Utile.h"
#include "DB.h"

RequestChat::RequestChat()
{
	this->raspuns = nullptr;
}

RequestChat::RequestChat(string sentence)
{
	vector<string> sentences = Utile::split(sentence, '/');
}

void RequestChat::gestionare_request()
{
	this->raspuns = DB::create_Instance()->chat();
}

string RequestChat::gestionare_raspuns()
{
	return this->raspuns;
}
