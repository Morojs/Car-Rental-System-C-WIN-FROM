#ifndef PENALISATION_H
#define PENALISATION_H

#include<iostream>
#include "RetourVoiture.h"
using namespace std;

class Penalisation {
	static int cpt;
	private:
		int id_Penalisation;
		string etat,raison;
		float montant;
		RetourVoiture retourVoiture;
	public:

		Penalisation(RetourVoiture retourVoiture , string Etat , int Montant , string Raison);

		void setRetourVoiture(RetourVoiture retourVoiture){this->retourVoiture = retourVoiture;}

		RetourVoiture getRetourVoiture(){return this->retourVoiture;}
		
		void setEtat(string Etat){etat = Etat;}
		
		string getEtat(){return etat;}
		
		void setMontant(int Montant){montant = Montant;}
		
		int getMontant(){return montant;}
		
		void setRaison(string Raison){raison = Raison;}
		
		string getRaison(){return raison;}		
};

#endif
