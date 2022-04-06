#pragma once
#include <iostream>
#include <vector>
using namespace std;
class User
{
	string username;
	string password;
	string country;
	string region;
	string email;
	string birth_date;
	vector<User*> friends;
public:
	User();
	User(string username, string  password, string country, string region, string email, string  birth_date);
	string get_username() { return this->username; }
	string get_password() { return this->password; }
	string get_country() { return this->country; }
	string get_region() { return this->region; }
	string get_email() { return this->email; }
	string get_birth_date() { return this->birth_date; }
	vector<User*> get_friends() { return this->friends; }
	void add_friend(User* u);
	void delete_friend(User* u);
	User* operator[](string username);
	bool operator== (User& user);

};

