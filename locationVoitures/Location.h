#ifndef LOCATION_H
#define LOCATION_H
#include<iostream>
#include "Client.h"
#include "Voiture.h"
#include "Connexion.h"
using namespace std;

class Location{
	  int jmax,imax;
      string ** list;
	  Connexion & con;	
	  int id_Location,duree;
	  SAString date_Location,date_Debut,date_Fin;
	  Client client;
	  Voiture voiture;
	public:
		Location();
		Location(Connexion &);
		Location(Client,Voiture,Connexion &);
		Location(Client,Voiture,SAString,SAString,SAString,int,Connexion &);
		string ** getAll();
		int getTheLastId();
	    //
		~ Location();
		void Ajouter(const SAString &);
		void Modifier(const SAString &);
		void Supprimer(const SAString &);
		int rowCount();
		int existe();
};

#endif
