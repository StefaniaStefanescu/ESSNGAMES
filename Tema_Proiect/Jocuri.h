#pragma once
#include <iostream>
#include <vector>
#include "User.h"
using namespace std;
class Jocuri
{
	string denumire;
	string descriere;
	vector<pair<User*, int>> scoruri;

public:
	Jocuri();
	Jocuri(string denumire, string descriere);
	string get_denumire() { return this->denumire; }
	string get_descriere() { return this->descriere; }
	vector<pair<User*, int>> get_scoruri() { return this->scoruri; }
	void adaugare_scor_nou(User* u, int scor);
	void update_scor(User* u, int scor);
};

