#ifndef FACTURE_H
#define FACTURE_H

#include<iostream>
#include "Location.h"


using namespace std;

class Facture{
	static int cpt;
	private:
		int id_Facture;
		string statut,date_Facture;
		float montant;
		Location location;
	public:

		Facture();

		Facture(Location location , string Statut, string Date_F , int Montant);

		void setLocation(Location location){this->location = location;}

		Location getLocation(){return this->location;}

		void setStatut(string Statut){statut = Statut;}
		
		string getStatut(){return statut;}
		
		void setDate_Facture(string date_F){date_Facture = date_F;}
		
		string getDate_Facture(){return date_Facture;}
		
		void setMontant(int Montant){montant = Montant;}
		
		int getMontant(){return montant;}
		
};

#endif