#ifndef VOITURE_H
#define VOITURE_H

#include "Connexion.h";
#include<iostream>
using namespace std;

class Voiture{
	private:
		int jmax,imax;
        string ** list;
		SAString matricule,modele,marque;
		int nbr_Stock;
		float tarif;
		Connexion & con;
	public:
		Voiture();
	    Voiture(Connexion &);
		Voiture(SAString,Connexion &);

		Voiture(SAString ,SAString,SAString,int,float,Connexion &);
		 

		SAString getMatricule() { return this->matricule;}
		SAString getMarque() { return this->marque;}
		Voiture & getVoitureById();
		//
		Voiture & operator=(const Voiture &);
		string ** getAll();
		void Ajouter(const SAString &);
		void Modifier(const SAString &);
		void Supprimer(const SAString &);
		int rowCount();
		int existe();
};

#endif
