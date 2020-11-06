#include "Voiture.h"
#include<string>

Voiture::Voiture():con(con){
	this->nbr_Stock=0;
	this->tarif=0;
}
//
Voiture::Voiture(Connexion &cnx):con(cnx){
	/* Allocation du tableau 2D */
	this->jmax=5;
	this->imax=this->rowCount();
	this->list=new string*[imax];
	// Initialisation 2d array
	for(int i = 0; i < imax; ++i)
		this->list[i] = new string[jmax];
	this->con=cnx;
}
Voiture::Voiture(SAString matricule,Connexion & cnx):con(cnx){
	 this->matricule=matricule;
	 this->con=cnx;
}
Voiture::Voiture(SAString matricule,SAString modele,SAString marque,int nbr_stock,float tarif,Connexion & cnx):con(cnx){
	
	 this->matricule=matricule;
	 this->modele=modele;
	 this->marque=marque;
	 this->nbr_Stock=nbr_stock;
	 this->tarif=tarif;
	 this->con=cnx;
}
void Voiture::Ajouter(const SAString &sCmd){
		// 
	/*
     Appel (exécution) d'une procédure stockée (fonction) 
	*/
	
	this->con.getCommande().setConnection(&this->con.getConnexion());
	this->con.getCommande().setCommandText(sCmd);
	this->con.getCommande().Param(1).setAsString() = this->matricule;
    this->con.getCommande().Param(2).setAsString() = this->modele;
	this->con.getCommande().Param(3).setAsString() = this->marque;
	this->con.getCommande().Param(4).setAsLong() =this->nbr_Stock;
	this->con.getCommande().Param(5).setAsLong()  = this->tarif;
    this->con.getCommande().Execute();
}
//MODIFICATION
void Voiture::Modifier(const SAString &sCmd){
	this->con.getCommande().setConnection(&this->con.getConnexion());
	this->con.getCommande().setCommandText(sCmd);
	this->con.getCommande().Param(1).setAsString()  = this->matricule;
    this->con.getCommande().Param(2).setAsString()  = this->modele;
	this->con.getCommande().Param(3).setAsString()  = this->marque;
	this->con.getCommande().Param(4).setAsInt64()  = this->nbr_Stock;
	this->con.getCommande().Param(5).setAsLong()   = this->tarif;
    this->con.getCommande().Execute();
}
// LA SUPPRESSION 
void Voiture::Supprimer(const SAString &sCmd){
	this->con.getCommande().setConnection(&this->con.getConnexion());
	this->con.getCommande().setCommandText(sCmd);
	this->con.getCommande().Param(1).setAsString() =this->matricule;
    this->con.getCommande().Execute();
}

//Nombre de lignes
int Voiture::rowCount(){
	  /*
     Appel (exécution) d'une procédure stockée (fonction) 
	*/
	this->con.getCommande().setConnection(&this->con.getConnexion());
	this->con.getCommande().setCommandText("select RowsCountVoiture();");
    this->con.getCommande().Execute();
	int row=0;
	while(this->con.getCommande().FetchNext()){
		row = this->con.getCommande().Field("RowsCountvoiture").asLong();
	}
	return row > 0 ? row : 0;
}

string ** Voiture::getAll(){
	   
		this->con.getCommande().setConnection(&this->con.getConnexion());
        this->con.getCommande().setCommandText("Select * from voiture order by matricule");

// this instructs the library to allocate a buffer for 100 rows
// and, using respective native API, request data from server in pages of 100 rows
        this->con.getCommande().setOption("PreFetchRows") = "100";
        this->con.getCommande().Execute();
		int cpt=0;
        while(this->con.getCommande().FetchNext())
        {
           // process result set row by row as usual
			for(int i=0;i<jmax;i++)
			{
			  string col = this->con.getCommande().Field(i+1).asString();
			  //MessageBoxA(NULL,col.c_str(), "CLIENT" , MB_OK | MB_ICONQUESTION);
		      this->list[cpt][i]=col;
			}
			cpt++;
		}
		cpt=0;
     return this->list;
}
// VERIFICATION DE L'EXISTENCE DE VOITURE
int Voiture::existe(){
	/*
     Appel (exécution) d'une procédure stockée (fonction) 
	*/
	this->con.getCommande().setConnection(&this->con.getConnexion());
	this->con.getCommande().setCommandText("select existeVoiture(:1)");
	this->con.getCommande().Param(1).setAsString()=this->matricule;
    this->con.getCommande().Execute();
	int row=0;
	while(this->con.getCommande().FetchNext()){
		row = this->con.getCommande().Field("existevoiture").asLong();
	}
	return row;
};

Voiture & Voiture::operator=(const Voiture & voiture){
	this->matricule=voiture.matricule;
	this->modele=voiture.modele;
	this->marque=voiture.marque;
	this->nbr_Stock=voiture.nbr_Stock;
	this->tarif=voiture.tarif;
	//LIST MUST BE DELETED :: ?? 
	return *this;
}

Voiture & Voiture::getVoitureById(){
	this->con.getCommande().setConnection(&this->con.getConnexion());
	this->con.getCommande().setCommandText("select * from get_voiture(:1)");
	this->con.getCommande().Param(1).setAsString()=this->matricule;
    this->con.getCommande().Execute();
	int row=0;
	while(this->con.getCommande().FetchNext()){
		 this->matricule=this->con.getCommande().Field(1).asString();
		 this->modele=this->con.getCommande().Field(2).asString();
		 this->marque=this->con.getCommande().Field(3).asString();
		 this->nbr_Stock=this->con.getCommande().Field(4).asInt64();
		 this->tarif=this->con.getCommande().Field(5).asLong();
	}
	return *this;
}