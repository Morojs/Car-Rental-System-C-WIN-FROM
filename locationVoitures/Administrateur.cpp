#include "Administrateur.h"


/*
FAQ : Erreur C2758: 'Administrateur::cnx' : doit être initialisé(e) dans la liste des initialiseurs base/membre du constructeur
Must be initialized in constructor base/member? [duplicate]
pour plus d'informations voir :
https://stackoverflow.com/questions/15461081/must-be-initialized-in-constructor-base-member
https://www.cprogramming.com/tutorial/initialization-lists-c++.html
*/
Administrateur::Administrateur(SAString login,SAString password,Connexion & con):cnx(con) {
	this->login=login;
	this->password=password;
	// overide = operateur
	this->cnx=con;
};

// VERIFICATION DE L'EXISTENCE DE L'ADMINISTRATEUR
int Administrateur::existe(const SAString &sCmd){
	if(this->cnx.ExecuterProcExiste(sCmd,this->login,this->password)>0)
        return 1;

	return -1;
};
Administrateur::~Administrateur(){}
