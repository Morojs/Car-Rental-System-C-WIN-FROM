#ifndef RETOURVOITURE_H
#define RETOURVOITURE_H

#include<iostream>
#include "Location.h"

using namespace std;

class RetourVoiture {
	static int cpt;
	private:
		int id_Retour;
		string date_Retour;
		Location location;

	public:

		RetourVoiture(Location location , string Date_R);

		void setLocation(Location location){this->location = location;}

		Location getLocation(){return location;}
		
		void setDate_Retour(string Date_R){date_Retour = Date_R;}
		
		string getDate_Retour(){return date_Retour;}
		
};

#endif
