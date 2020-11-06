#ifndef CLIENT_H
#define CLIENT_H
#include "Connexion.h"
#include<iostream>
using namespace System::Collections;
using namespace std;

class Client
{       int jmax,imax;
        string ** list;
		SAString cin,nom,prenom,adresse,id_Client;
		int telephone;
		Connexion & con;
	public:
		Client();
		Client(Connexion &);
		Client(SAString,Connexion &);
		Client(SAString,SAString,SAString,SAString,int,Connexion &);
	    string ** getAll();
		//
		~ Client();
		Client & operator=(const Client &);
		SAString getCin() { return this->cin;}

	    Client & getClientById();
		int rowCount();
		int existe();
		void Ajouter(const SAString &);
		void Modifier(const SAString &);
		void Supprimer(const SAString &);
		
};

#endif