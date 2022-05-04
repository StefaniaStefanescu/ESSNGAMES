#define _CRT_SECURE_NO_WARNINGS 
#include "DB.h"
#include "User.h"
#include <string>
#include <utility>
#include <tuple>
#include <ctime>
#include <fstream>
#include "IException.h"
DB* DB::instance = nullptr;

bool DB::registerUser(string username, string  password, string country, string region, string email, string  birth_date)
{
	// 0/Eli/Rock/Romania/Iasi/elisisi@yahoo.com/02-03-2001
	//INSERT INTO Users (username, password, country, region, email, birthDate) VALUES ("Eli","Rock","Romania","Iasi","elisisi@yahoo.com","02-03-2001");
	string query = "INSERT INTO users (username, password, country, region, email, birthDate) VALUES (\"" +
		username + "\",\"" + password + "\",\"" + country + "\",\"" + region + "\",\"" + email + "\",\"" + birth_date + "\");";
	const char* q = query.c_str();
	qstate = mysql_query(conn, q);  //executa query-ul
	try
	{
		if (!qstate)
		{
			res = mysql_store_result(conn);
			return true;
		}
		else
		{
			cout << "Query failed: " << mysql_error(conn) << endl;
			throw IException::Factory::err_Register();
		}
	}
	catch (IException* e)
	{
		time_t now = time(0);
		char* dt = ctime(&now);
		string eroare(dt);
		eroare += " -> ";
		eroare += e->print();
		ofstream myfile;
		myfile.open("Erori.txt", ios_base::app);
		myfile << eroare;
		myfile.close();
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
	try
	{
		if (!qstate)
		{
			res = mysql_store_result(conn);
			return true;
		}
		else
		{
			cout << "Query failed: " << mysql_error(conn) << endl;
			throw IException::Factory::err_Register();
		}
	}
	catch (IException* e)
	{
		time_t now = time(0);
		char* dt = ctime(&now);
		string eroare(dt);
		eroare += " -> ";
		eroare += e->print();
		ofstream myfile;
		myfile.open("Erori.txt", ios_base::app);
		myfile << eroare;
		myfile.close();
		return false;
	}
}

bool DB::addFriend(string host, string prieten)
{
	// 2/elisisiala/stefaniastefanescu
	//INSERT INTO Friends (username1, username2) VALUES ("elisisiala","stefaniastefanescu");
	string query2 = "SELECT * FROM Friends;";
	const char* q2 = query2.c_str();
	int qstate2 = mysql_query(conn, q2);  //executa query-ul
	try
{
		if (!qstate2)
	{
		res = mysql_store_result(conn);
		row = mysql_fetch_row(res);
		vector<pair<string, string>> perechi_prieteni;
		while (row)
		{
			perechi_prieteni.push_back(make_pair(row[0], row[1]));
			row = mysql_fetch_row(res);
		}
		for (int i = 0; i < perechi_prieteni.size(); i++)
		{
			if (perechi_prieteni[i].first == host && perechi_prieteni[i].second == prieten)
			{
				return false;
			}
			
		}
		
	}
	else
	{
		cout << "Query failed: " << mysql_error(conn) << endl;
		throw IException::Factory::err_GetAllFriends();
	}
	string query = "INSERT INTO Friends (username1, username2) VALUES (\"" +
		host + "\",\"" + prieten + "\");";
	const char* q = query.c_str();
	qstate = mysql_query(conn, q);  //executa query-ul
		if (!qstate)
		{
			res = mysql_store_result(conn);
			string query1 = "INSERT INTO Friends (username1, username2) VALUES (\"" +
				prieten + "\",\"" + host + "\");";
			const char* q1 = query1.c_str();
			int qstate1 = mysql_query(conn, q1);  //executa query-ul
			if (!qstate1)
			{
				res = mysql_store_result(conn);
				return true;
			}
			else
			{
				cout << "Query failed: " << mysql_error(conn) << endl;
				throw IException::Factory::err_ADDFriend();
			}
		}
		else
		{
			cout << "Query failed: " << mysql_error(conn) << endl;
			throw IException::Factory::err_ADDFriend();
		}
	}
	catch (IException* e)
	{
		time_t now = time(0);
		char* dt = ctime(&now);
		string eroare(dt);
		eroare += " -> ";
		eroare += e->print();
		ofstream myfile;
		myfile.open("Erori.txt", ios_base::app);
		myfile << eroare;
		myfile.close();
		return false;
	}
}

bool DB::deleteFriend(string host, string prieten)
{
	// 3/elisisiala/stefaniastefanescu
	//DELETE FROM Friends WHERE username1=\"" + host + "\" AND username2=\"" + prieten + "\";";

	string query = "DELETE FROM Friends WHERE username1=\"" + host + "\" AND username2=\"" + prieten + "\";";
	const char* q = query.c_str();
	qstate = mysql_query(conn, q);  //executa query-ul
	try
	{
		if (!qstate)
		{
			res = mysql_store_result(conn);
			string query1 = "DELETE FROM Friends WHERE username1=\"" + prieten + "\" AND username2=\"" + host + "\";";
			const char* q1 = query1.c_str();
			int qstate1 = mysql_query(conn, q1);  //executa query-ul
			if (!qstate1)
			{
				res = mysql_store_result(conn);
				return true;
			}
			else
			{
				cout << "Query failed: " << mysql_error(conn) << endl;
				throw IException::Factory::err_DeleteFriend();
			}
		}
		else
		{
			cout << "Query failed: " << mysql_error(conn) << endl;
			throw IException::Factory::err_DeleteFriend();
		}
	}
	catch (IException* e)
	{
		time_t now = time(0);
		char* dt = ctime(&now);
		string eroare(dt);
		eroare += " -> ";
		eroare += e->print();
		ofstream myfile;
		myfile.open("Erori.txt", ios_base::app);
		myfile << eroare;
		myfile.close();
		return false;
	}
}

bool DB::InscriereScore(string username, string denumire_joc, string score)
{
	// 8/elisisiala/Tanks/56
	//INSERT INTO Scor (username, denumire_joc, score) VALUES ("elisisiala","Tanks","56");
	string query = "INSERT INTO Scor (username, denumire_joc, score) VALUES (\"" +
		username + "\",\"" + denumire_joc + "\",\"" + score + "\");";
	const char* q = query.c_str();
	qstate = mysql_query(conn, q);  //executa query-ul
	try
	{
		if (!qstate)
		{
			res = mysql_store_result(conn);
			return true;
		}
		else
		{
			cout << "Query failed: " << mysql_error(conn) << endl;
			throw IException::Factory::err_InscriereScore();
		}
	}
	catch (IException* e)
	{
		time_t now = time(0);
		char* dt = ctime(&now);
		string eroare(dt);
		eroare += " -> ";
		eroare += e->print();
		ofstream myfile;
		myfile.open("Erori.txt", ios_base::app);
		myfile << eroare;
		myfile.close();
		return false;
	}
}

string DB::getallFriends(string host)
{
	// 4/elisisiala
	string query = "SELECT username2 FROM Friends WHERE username1=\""+host+"\";";
	const char* q = query.c_str();
	qstate = mysql_query(conn, q);  //executa query-ul
	try
	{
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
			string raspuns = " /";
			//raspuns += to_string(prieteni.size());  //asta de scos. trimit fara nr total de pr.
			for (auto i : prieteni)
			{
				raspuns += i + "/";
			}
			return raspuns;
		}
		else
		{
			cout << "Query failed: " << mysql_error(conn) << endl;
			throw IException::Factory::err_GetAllFriends();
		}
	}
	catch (IException* e)
	{
		time_t now = time(0);
		char* dt = ctime(&now);
		string eroare(dt);
		eroare += " -> ";
		eroare += e->print();
		ofstream myfile;
		myfile.open("Erori.txt", ios_base::app);
		myfile << eroare;
		myfile.close();
		return "NOK";
	}
}

string DB::denumireJoc(string denumire) //imi da descrierea jocului cu denumirea transmisa.
{
	// 5/Tanks
	string query = "SELECT descriere FROM Jocuri WHERE denumire=\"" + denumire + "\";";
	const char* q = query.c_str();
	qstate = mysql_query(conn, q);  //executa query-ul
	try
	{
		if (!qstate)
		{
			res = mysql_store_result(conn);
			row = mysql_fetch_row(res);
			if(row)
			{
				string raspuns = "";
				raspuns = row[0];
				raspuns += "/";
				return raspuns;
			}
			else
			{
				return "NOK";
			}
		}
		else
		{
			cout << "Query failed: " << mysql_error(conn) << endl;
			throw IException::Factory::err_JocDescriere();
		}
	}
	catch (IException* e)
	{
		time_t now = time(0);
		char* dt = ctime(&now);
		string eroare(dt);
		eroare += " -> ";
		eroare += e->print();
		ofstream myfile;
		myfile.open("Erori.txt", ios_base::app);
		myfile << eroare;
		myfile.close();
		return "NOK";
	}
}


string DB::topScore(string denumire_joc)
{
	// 6/Tanks
	string query = "SELECT DISTINCT TOP 10 username, score FROM Scor WHERE denumire_joc=\"" + denumire_joc + "\" ORDER BY score DESC;";
	const char* q = query.c_str();
	qstate = mysql_query(conn, q);  //executa query-ul
	try
	{
		if (!qstate)
		{
			res = mysql_store_result(conn);
			row = mysql_fetch_row(res);
			vector<pair<string,string>> scoruri;
			while (row)
			{
				
				scoruri.push_back(make_pair(row[0], row[1]));
				row = mysql_fetch_row(res);
			}
			string raspuns = "";
			raspuns += to_string(scoruri.size());
			for (int i = 0; i < scoruri.size(); i++)
			{
				raspuns += "/";
				raspuns += scoruri[i].first;
				raspuns += "/";
				raspuns += scoruri[i].second;
			}
			raspuns += "/";
			return raspuns;
		}
		else
		{
			cout << "Query failed: " << mysql_error(conn) << endl;
			throw IException::Factory::err_Top();
		}
	}
	catch (IException* e)
	{
		time_t now = time(0);
		char* dt = ctime(&now);
		string eroare(dt);
		eroare += " -> ";
		eroare += e->print();
		ofstream myfile;
		myfile.open("Erori.txt", ios_base::app);
		myfile << eroare;
		myfile.close();
		return "NOK";
	}
}

string DB::allTopsScore()
{
	// 7
	string query = "SELECT DISTINCT top 10 username, score FROM Scor ORDER BY score DESC;";
	const char* q = query.c_str();
	qstate = mysql_query(conn, q);  //executa query-ul
	try
	{
		if (!qstate)
		{
			res = mysql_store_result(conn);
			row = mysql_fetch_row(res);
			vector<pair<string, string>> scoruri;
			while (row)
			{
				scoruri.push_back(make_pair(row[0], row[1]));
				row = mysql_fetch_row(res);
			}
			string raspuns = "";
			raspuns += to_string(scoruri.size());
			for (int i = 0; i < scoruri.size(); i++)
			{
				raspuns += "/";
				raspuns += scoruri[i].first;
				raspuns += "/";
				raspuns += scoruri[i].second;
			}
			raspuns += "/";
			return raspuns;
		}
		else
		{
			cout << "Query failed: " << mysql_error(conn) << endl;
			throw IException::Factory::err_AllTops();
		}
	}
	catch (IException* e)
	{
		time_t now = time(0);
		char* dt = ctime(&now);
		string eroare(dt);
		eroare += " -> ";
		eroare += e->print();
		ofstream myfile;
		myfile.open("Erori.txt", ios_base::app);
		myfile << eroare;
		myfile.close();
		return "NOK";
	}
}

string DB::chat()
{
	// 9/
	string query = "SELECT * FROM Chat;";
	const char* q = query.c_str();
	qstate = mysql_query(conn, q);  //executa query-ul
	try
	{
		if (!qstate)
		{
			res = mysql_store_result(conn);	
			row = mysql_fetch_row(res);
			vector<tuple<string, string, string>> infos;
			while (row)
			{
				infos.push_back(make_tuple(row[0],row[1],row[2]));
				row = mysql_fetch_row(res);
			}
			string raspuns = " /";
			for (auto i : infos)
			{
				raspuns +=get<0>(i) + ": ";
				raspuns += get<1>(i) + " -> ";
				raspuns += get<2>(i) + "/";
			}
			return raspuns;
		}
		else
		{
			cout << "Query failed: " << mysql_error(conn) << endl;
			throw IException::Factory::err_SelectChat();
		}
	}
	catch (IException* e)
	{
		time_t now = time(0);
		char* dt = ctime(&now);
		string eroare(dt);
		eroare += " -> ";
		eroare += e->print();
		ofstream myfile;
		myfile.open("Erori.txt", ios_base::app);
		myfile << eroare;
		myfile.close();
		return "NOK";
	}
}

string DB::pathJoc(string denumire)
{
	// 10/Tanks
	string query = "SELECT path FROM Jocuri WHERE denumire=\"" + denumire + "\";";
	const char* q = query.c_str();
	qstate = mysql_query(conn, q);  //executa query-ul
	try
	{
		if (!qstate)
		{
			res = mysql_store_result(conn);
			row = mysql_fetch_row(res);
			if (row)
			{
				string raspuns = "";
				raspuns = row[0];
				raspuns += "/";
				return raspuns;
			}
			else
				return "NOK";
		}
		else
		{
			cout << "Query failed: " << mysql_error(conn) << endl;
			throw IException::Factory::err_PathJoc();
		}
	}
	catch (IException* e)
	{
		time_t now = time(0);
		char* dt = ctime(&now);
		string eroare(dt);
		eroare += " -> ";
		eroare += e->print();
		ofstream myfile;
		myfile.open("Erori.txt", ios_base::app);
		myfile << eroare;
		myfile.close();
		return "NOK";
	}
}

bool DB::SchimbaParola(string username, string nouaparola)
{
	// 12/elisisiala/nouaparola
	//UPDATE Users SET password = "nouaparola" WHERE username="elisisiala";
	string query = "UPDATE Users SET password = \"" + nouaparola + "\" WHERE username=\"" + username + "\";";
	const char* q = query.c_str();
	qstate = mysql_query(conn, q);  //executa query-ul
	try
	{
		if (!qstate)
		{
			res = mysql_store_result(conn);
			return true;
		}
		else
		{
			cout << "Query failed: " << mysql_error(conn) << endl;
			throw IException::Factory::err_SchimbaParola();
		}
	}
	catch (IException* e)
	{
		time_t now = time(0);
		char* dt = ctime(&now);
		string eroare(dt);
		eroare += " -> ";
		eroare += e->print();
		ofstream myfile;
		myfile.open("Erori.txt", ios_base::app);
		myfile << eroare;
		myfile.close();
		return false;
	}
}

string DB::getDenumiriJoc()
{
	// 12
	string query = "SELECT denumire FROM Jocuri;";
	const char* q = query.c_str();
	qstate = mysql_query(conn, q);  //executa query-ul
	try
	{
		if (!qstate)
		{
			res = mysql_store_result(conn);
			row = mysql_fetch_row(res);
			vector<string> denumiri;
			while (row)
			{
				denumiri.push_back(row[0]);
				row = mysql_fetch_row(res);
			}
			string raspuns = "";
			raspuns += to_string(denumiri.size());
			for (auto i : denumiri)
			{
				raspuns += "/" + i;
			}
			return raspuns;
		}
		else
		{
			cout << "Query failed: " << mysql_error(conn) << endl;
			throw IException::Factory::err_DenumiriJoc();
		}
	}
	catch (IException* e)
	{
		time_t now = time(0);
		char* dt = ctime(&now);
		string eroare(dt);
		eroare += " -> ";
		eroare += e->print();
		ofstream myfile;
		myfile.open("Erori.txt", ios_base::app);
		myfile << eroare;
		myfile.close();
		return "NOK";
	}
}

bool DB::addJoc(string denumire, string descriere, string path)
{
	// 13/mario5/e un joc frumos/path-ul
	//INSERT INTO Friends (username1, username2) VALUES ("elisisiala","stefaniastefanescu");
	string query = "INSERT INTO Jocuri (denumire, descriere, path) VALUES (\"" + denumire + "\",\"" + descriere + "\",\"" + path + "\");";
	const char* q = query.c_str();
	qstate = mysql_query(conn, q);  //executa query-ul
	try
	{
		if (!qstate)
		{
			res = mysql_store_result(conn);
			return true;
		}
		else
		{
			cout << "Query failed: " << mysql_error(conn) << endl;
			throw IException::Factory::err_ADDJoc();
		}
	}
	catch (IException* e)
	{
		time_t now = time(0);
		char* dt = ctime(&now);
		string eroare(dt);
		eroare += " -> ";
		eroare += e->print();
		ofstream myfile;
		myfile.open("Erori.txt", ios_base::app);
		myfile << eroare;
		myfile.close();
		return false;
	}
}

string DB::InsertChat(string username, string mesaj)
{
	// 10/elisisiala/mesaj/Sat Jan  8 20:07:41 2011
	//INSERT INTO Chat (username, mesaj, time) VALUES ("elisisiala","mesaj","Sat Jan  8 20:07:41 2011");
	time_t now = time(0);
	char* dt = ctime(&now);
	string timp(dt);
	string query = "INSERT INTO Chat (username, mesaj, time) VALUES (\"" +
		username + "\",\"" + mesaj + "\",\"" + timp + "\");";
	const char* q = query.c_str();
	qstate = mysql_query(conn, q);  //executa query-ul
	try
	{
		if (!qstate)
		{
			res = mysql_store_result(conn);
			string raspuns = "777/";
			raspuns += username + ": " + mesaj + " -> " + timp;
			return raspuns;
		}
		else
		{
			cout << "Query failed: " << mysql_error(conn) << endl;
			throw IException::Factory::err_InsertChat();
		}
	}
	catch (IException* e)
	{
		time_t now = time(0);
		char* dt = ctime(&now);
		string eroare(dt);
		eroare += " -> ";
		eroare += e->print();
		ofstream myfile;
		myfile.open("Erori.txt", ios_base::app);
		myfile << eroare;
		myfile.close();
		return "NOK";
	}
}
