#include <iostream>
#include <mysql.h>
#include <sstream>
#include "DB.h"
#include <vector>
#include "IRequest.h"
using namespace std;


int main()
{
	
	//receive sentence
	string sentence;
	IRequest* request = IRequest::Factory::getRequest(sentence);
	request->gestionare_request();

	string raspuns=request->gestionare_raspuns();
	//send sentence

	return 0;

}
