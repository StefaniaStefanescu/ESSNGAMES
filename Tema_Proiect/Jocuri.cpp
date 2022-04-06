#include "Jocuri.h"

Jocuri::Jocuri()
{
	this->denumire = nullptr;
	this->descriere = nullptr;
}

void Jocuri::adaugare_scor_nou(User* u, int scor)
{
	scoruri.push_back(make_pair(u, scor));
}

void Jocuri::update_scor(User* u, int scor)
{
	for (auto i : scoruri)
	{
		if (*i.first == *u)
		{
			i.second = scor;
		}
	}
}

Jocuri::Jocuri(string denumire, string descriere)
{
	this->denumire = denumire;
	this->descriere = descriere;
}
