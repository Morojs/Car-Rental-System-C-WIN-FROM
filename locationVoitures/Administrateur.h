#ifndef ADMINISTRATEUR_H
#define ADMINISTRATEUR_H

#include "Connexion.h"
#include<iostream>
using namespace std;

class Administrateur
{
       SAString  login;
	   SAString  password;
	   Connexion & cnx;
	public:

	Administrateur(SAString,SAString,Connexion &);
	int existe(const SAString &sCmd);
	~Administrateur();
    string getLogin() { return login; }
    string getPassword() { return password; }
};

#endif