#include "Location.h"

Location::Location(Connexion & cnx) : con(cnx){
	 this->con=cnx;
}
Location::Location(Client client,Voiture voiture,Connexion &cnx):con(cnx) {
	this->con=cnx;
	this->client=client;
	this->voiture=voiture;
}
Location::Location(Client client , Voiture voiture , SAString Date_L , SAString Date_D , SAString Date_F , int duree,Connexion &cnx):con(cnx){
	  this->con=cnx;
	  this->client=client;
	  this->voiture=voiture;
	  this->duree=duree;
	  //
	  this->date_Debut=Date_D;
	  this->date_Fin=Date_F;
}

//
void Location::Ajouter(const SAString &sCmd){
		// 
	/*
     Appel (exécution) d'une procédure stockée (fonction) 
	*/
	this->con.getCommande().setConnection(&this->con.getConnexion());
	this->con.getCommande().setCommandText(sCmd);
    this->con.getCommande().Param(1).setAsString() = this->client.getCin();
	this->con.getCommande().Param(2).setAsString() = this->voiture.getMatricule();
	this->con.getCommande().Param(3).setAsInt64()  = this->duree;
	this->con.getCommande().Param(4).setAsString()  = this->date_Debut;
	this->con.getCommande().Param(5).setAsString()  = this->date_Fin;
    this->con.getCommande().Execute();

}

//MODIFICATION
void Location::Modifier(const SAString &sCmd){
	this->con.getCommande().setConnection(&this->con.getConnexion());
	this->con.getCommande().setCommandText(sCmd);
    this->con.getCommande().Param(1).setAsString() = this->client.getCin();
	this->con.getCommande().Param(2).setAsString() = this->voiture.getMatricule();
	this->con.getCommande().Param(3).setAsInt64()  = this->duree;
	this->con.getCommande().Param(4).setAsString()  = this->date_Debut;
	this->con.getCommande().Param(5).setAsString()  = this->date_Fin;
    this->con.getCommande().Execute();
}
// LA SUPPRESSION 
void Location::Supprimer(const SAString &sCmd){
	this->con.getCommande().setConnection(&this->con.getConnexion());
	this->con.getCommande().setCommandText(sCmd);
	this->con.getCommande().Param(1).setAsString() = this->client.getCin();
	this->con.getCommande().Param(2).setAsString() = this->voiture.getMatricule();
    this->con.getCommande().Execute();
}