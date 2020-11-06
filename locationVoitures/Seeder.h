#ifndef SEEDER_H
#define SEEDER_H

#include <iostream>
#include "Connexion.h"
#include<SQLAPI.h>

using namespace std;

class Seeder {
	 const char *pSQL[8];
	 Connexion cnx;
public : 
	   Seeder(Connexion);
	   ~Seeder();
	  int callback(void *, int, char **, char **);
	  void Create();
};

#endif