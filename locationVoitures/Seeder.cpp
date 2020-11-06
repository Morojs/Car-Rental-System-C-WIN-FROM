#include "Seeder.h"

#include<iostream>
using namespace std;
Seeder::Seeder(Connexion con){
	
this->cnx=con;

// CREATION DE LA BASE DE DONNEES
this->pSQL[0] = "CREATE DATABASE locationVoitures";

// ADMINISTRATEUR
this->pSQL[1] = "CREATE TABLE Administrateur ( \
             login varchar(30) PRIMARY KEY, \
             password varchar(30))";
// VOITURE
this->pSQL[2] = "CREATE TABLE Voiture( \
             matricule varchar(30) PRIMARY KEY, \
             modele varchar(30), \
             marque varchar(30),\
             nbr_Stock int, \
             tarif float)";
// CLIENT
 this->pSQL[3] = "CREATE TABLE Client ( \
              id_client INTEGER PRIMARY KEY AUTOINCREMENT,\
              nom varchar(30), \
              prenom varchar(30),\
              adresse varchar(100),\
              telephone int)";
// LOCATION
 this->pSQL[4] = "CREATE TABLE Location( \
            id_location INTEGER PRIMARY KEY AUTOINCREMENT, \
            client int, \
            voiture varchar(30), \
            duree int, \
            date_debut date, \
            date_fin date, \
            constraint FK_CLEINT foreign key (client) references Client(id_client), \
            constraint FK_VOITURE foreign key (voiture) references Voiture(matricule))";
// FACTURE
  this->pSQL[5] = "CREATE TABLE Facture ( \
             id_facture INTEGER PRIMARY KEY AUTOINCREMENT, \
             status varchar(30), \
             date_facture date, \
             montant float, \
             location int, \
             constraint FK_LOCATION foreign key (location) references Location(id_location))";

  //RETOUR VOITURE
  this->pSQL[6] = "CREATE TABLE RetourVoiture( \
             id_retour INTEGER PRIMARY KEY AUTOINCREMENT,\
             date_Retour date,\
             location int,\
             constraint FK_LOCATION foreign key (location) references Location(id_location))";
//PENALISATION
  this->pSQL[7] = "CREATE TABLE Penalisation( \
             id_penalisation varchar(30), \
             etat varchar(30), \
             raison varchar(30), \
             montant float, \
             retourVoiture int,\
             constraint FK_RETOURVOITURE foreign key (retourVoiture) references Voiture(matricule))";


}
Seeder::~Seeder(){
	delete this->pSQL;
}
int Seeder::callback(void *NotUsed, int argc, char **argv, char **szColName){
	// la fonction de rappel pour afficher les données de sélection dans le tableau
	for(int i = 0; i < argc; i++)
    {
        //// std::cout << szColName[i] << " = " << argv[i] << std::endl;
    }
  ////std::cout << "\n";
  return 0;
}
void Seeder::Create(){
		Connexion con("DRIVER=Devart ODBC Driver for PostgreSQL;Data Source=localhost;Database=pepinieres_app;Use Unicode=True",
		    "postgres",
			"055597596");
		//Surcharge operateur =
		this->cnx=con;
		cnx.Connecter();
		MessageBoxA(NULL, "BIEN CONNECTER", "OK" , MB_OK | MB_ICONQUESTION);
		//SACommand cmd(&cnx.getConnexion());
		this->cnx.getCommande().setConnection(&this->cnx.getConnexion());
  for(int i = 0; i < 7; i++)
  {
	  this->cnx.getCommande().setCommandText(pSQL[i]);
  }
  this->cnx.Deconnecter();
}
