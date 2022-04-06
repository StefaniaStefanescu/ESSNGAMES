#include "Utile.h"

vector<string> Utile::split(string word, char delimiter)
{
	string aux = "";
	vector<string>cuvinte;
	for (int i = 0; i < (int)word.size(); i++)
	{
		if (word[i] != delimiter)
		{
			aux += word[i];
		}
		else
		{
			cuvinte.push_back(word);
			aux = "";
		}
	}
	return cuvinte;
}
