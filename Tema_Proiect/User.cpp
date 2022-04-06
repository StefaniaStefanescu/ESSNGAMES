#include "User.h"

User::User()
{
	this->username = nullptr;
	this->password = nullptr;
	this->country = nullptr;
	this->region = nullptr;
	this->email = nullptr;
	this->birth_date = nullptr;
}
User::User(string username, string  password, string country, string region, string email, string  birth_date)
{
	this->username = username;
	this->password = password;
	this->country = country;
	this->region = region;
	this->email = email;
	this->birth_date = birth_date;
}

void User::add_friend(User* u)
{
	this->friends.push_back(u);
}

void User::delete_friend(User* u)
{
	int idx = 0;
	for (int i = 0; i < friends.size(); i++)
	{
		if (*u == *this->friends[i])
		{
			idx = i;
		}
	}
	this->friends.erase(this->friends.begin() + idx);
}

User* User::operator[](string username)
{
	for (auto i : this->friends)
	{
		if (i->get_username() == username)
		{
			return i;
		}
	}
	return nullptr;
}

bool User::operator==(User& user)
{
	if (this->username == user.get_username() && this->password == user.get_password())
	{
		return true;
	}
	return false;
}
