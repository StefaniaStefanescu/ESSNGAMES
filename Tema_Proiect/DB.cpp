#include "DB.h"
#include "User.h"
DB* DB::instance = nullptr;

bool DB::registerUser(string username, string  password, string country, string region, string email, string  birth_date)
{
	// 0/Eli/Rock/Romania/Iasi/elisisi@yahoo.com/02-03-2001
	//INSERT INTO Users (username, password, country, region, email, birthDate) VALUES ("Eli","Rock","Romania","Iasi","elisisi@yahoo.com","02-03-2001");
	string query = "INSERT INTO users (username, password, country, region, email, birthDate) VALUES (\"" +
		username + "\",\"" + password + "\",\"" + country + "\",\"" + region + "\",\"" + email + "\",\"" + birth_date + "\");";
	const char* q = query.c_str();
	qstate = mysql_query(conn, q);  //executa query-ul
	if (!qstate)
	{
		res = mysql_store_result(conn);
		return true;
	}
	else
	{
		cout << "Query failed: " << mysql_error(conn) << endl;
		return false;
	}

}

bool DB::loginUser(string username, string  password)
{
	// 1/elisisiala/Rock
	//SELECT Username, Password FROM users WHERE username="Eli" AND password="parola";
	string query = "SELECT username, password FROM Users WHERE username=\"" + username + "\" AND password=\"" + password + "\";";
	const char* q = query.c_str();
	qstate = mysql_query(conn, q);  //executa query-ul
	if (!qstate)
	{
		res = mysql_store_result(conn);
		row = mysql_fetch_row(res);
		if (row)
			return true;
		else
			return false;
	}
	else
	{
		cout << "Query failed: " << mysql_error(conn) << endl;
		return false;
	}
}

bool DB::addFriend(string host, string prieten)
{
	// 2/elisisiala/stefaniastefanescu
	//INSERT INTO Friends (username1, username2) VALUES ("elisisiala","stefaniastefanescu");
	string query = "INSERT INTO Friends (username1, username2) VALUES (\"" +
		host + "\",\"" + prieten + "\");";
	const char* q = query.c_str();
	qstate = mysql_query(conn, q);  //executa query-ul
	if (!qstate)
	{
		res = mysql_store_result(conn);
		return true;
	}
	else
	{
		cout << "Query failed: " << mysql_error(conn) << endl;
		return false;
	}
}

bool DB::deleteFriend(string host, string prieten)
{
	// 2/elisisiala/stefaniastefanescu
	//DELETE FROM Friends WHERE username1=\"" + host + "\" AND username2=\"" + prieten + "\";";
	string query = "DELETE FROM Friends WHERE username1=\"" + host + "\" AND username2=\"" + prieten + "\";";
	const char* q = query.c_str();
	qstate = mysql_query(conn, q);  //executa query-ul
	if (!qstate)
	{
		res = mysql_store_result(conn);
		return true;
	}
	else
	{
		cout << "Query failed: " << mysql_error(conn) << endl;
		return false;
	}
}

string DB::getallFriends(string host)
{
	string query = "SELECT username2 FROM Friends WHERE username1=\""+host+"\";";
	const char* q = query.c_str();
	qstate = mysql_query(conn, q);  //executa query-ul
	if (!qstate)
	{
		res = mysql_store_result(conn);
		row = mysql_fetch_row(res);
		vector<string> prieteni;
		while (row)
		{
			prieteni.push_back(row[0]);
			row = mysql_fetch_row(res);
		}
		string raspuns = "";
		raspuns += to_string(prieteni.size());
		for (auto i : prieteni)
		{
			raspuns += "/" + i;
		}
		return raspuns;
	}
	else
	{
		cout << "Query failed: " << mysql_error(conn) << endl;
		return "0";
	}
}

string DB::denumireJoc(string denumire)
{
	return string();
}


string DB::topScore(string denumire_joc)
{
	return string();
}

string DB::allTopsScore()
{
	return string();
}
