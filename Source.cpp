#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <mysql.h>
#include <sstream>
#include "DB.h"
#include "Utile.h"
#include <vector>
#include "IRequest.h"
#include <SFML/Network.hpp>
using namespace std;
using namespace sf;

int main()
{

	TcpListener listener;
	SocketSelector selector;
	vector<TcpSocket*>clients;

	listener.listen(2001);
	selector.add(listener);

	while (true)
	{
		// <header...><192.168.12.sursa,1292.444.3 destiinatie><sentence>
		if (selector.wait())				//astept sa se primeasca un semnal (orice) pe portul meu
		{
			if (selector.isReady(listener))  //asculta daca e gata de o conexiune noua
			{
				TcpSocket* socket = new TcpSocket;   //retine conexiunea
				listener.accept(*socket);			//ping-ul (s-a dus un mesaj si asteapta sa primeasca raspuns inapoi)
				clients.push_back(socket);
				selector.add(*socket);				//il baga in vectorul selectorului de sockets ca sa il recunoasca la o conectare ulterioara.
			}
			else                                    //daca nu e o conexiune noua
			{
				for (int i = 0; i < clients.size(); i++)
				{
					if (selector.isReady(*clients[i]))		//verifica daca asta e socket-ul de la care a primit mesajul/pachetul	
					{	
						char buffer[1024];
						size_t received = 0;
						clients[i]->receive(buffer, sizeof(buffer), received);
						cout << "Primit: "<< buffer<<endl;
						string sentence(buffer);
						//decriptare cu functia din Utile;
						if (sentence == "Logout")
						{
							clients.erase(clients.begin()+i);
							break;
							
						}
 						IRequest* request = IRequest::Factory::getRequest(sentence);
						request->gestionare_request();
						string raspuns = request->gestionare_raspuns();
						//criptare cu functia din Utile;
						cout <<"Raspuns: "<< raspuns<<endl;
						if (Utile::split(sentence, '/')[0] == "10")
						{
							for (int j = 0; j < clients.size(); j++)
							{
								if (i != j)
								{
									clients[j]->send(raspuns.c_str(), raspuns.size());
								}
							}
						}
						clients[i]->send(raspuns.c_str(),raspuns.size());
					}
				}
			}
		}
	}
	for (vector<TcpSocket*>::iterator it = clients.begin(); it != clients.end(); it++)		
		delete* it;

	return 0;

}
