#pragma once
#include <string>
#include <mysql.h>
#include <iostream>
#include <sstream>
using namespace std;
class DB
{
private:
	static DB* instance;
	int qstate;
	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES* res;

	DB()
	{
		conn = mysql_init(0);

		conn = mysql_real_connect(conn, "localhost", "root", "Rockon155!", "essngames", 3306, NULL, 0);
		
	}
public:
	static DB* create_Instance()
	{
		if (!instance)
			instance = new DB();
		return instance;
	}
	bool registerUser(string username, string  password, string country, string region, string email, string  birth_date);
	bool loginUser(string username, string  password);
	bool addFriend(string host, string prieten);
	bool deleteFriend(string host, string prieten);
	string getallFriends(string host);
	string denumireJoc(string denumire);
	string topScore(string denumire_joc);
	string allTopsScore();


};
