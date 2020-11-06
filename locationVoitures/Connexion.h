#ifndef CONNEXION_H
#define CONNEXION_H
/*


---------------------------------------
ODBC ET POSTGRESQL : win32 bit. 
https://www.sqlapi.com/ApiDoc/odbc/ 
---------------------------------------


*/
#include<iostream>
#include<SQLAPI.h>

using namespace std;

class Connexion 
{  
	SAConnection con; 
	SACommand cmd;
    SAString  odbc,user,pwd;
public:
	Connexion();
    Connexion(SAString,SAString,SAString);
	void Connecter();
	void Deconnecter();
	
	// EXEC LA FONCTION D'EXISTENCE
	int ExecuterProcExiste(const SAString &sCmd,const SAString &param1="",const SAString &param2="");
	~Connexion();
	SAConnection & getConnexion();
	SACommand & getCommande();
	Connexion & operator=(const Connexion &);
	string getODBC(){return this->odbc;}
	//
	bool status();
};

#endif