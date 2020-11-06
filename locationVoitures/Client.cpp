#include "Client.h"

Client::Client(void):con(con){
}
Client::Client(Connexion &cnx):con(cnx){
	/* Allocation du tableau 2D */
	this->jmax=5;
	this->imax=this->rowCount();
	this->list=new string*[imax];
	// Initialisation 2d array
	for(int i = 0; i < imax; ++i)
		this->list[i] = new string[jmax];
	this->con=cnx;
}
Client::Client(SAString Cin,Connexion & cnx):con(cnx){
	 this->cin=Cin;
	 this->con=cnx;
}
Client::Client(SAString Cin,SAString Nom,SAString Prenom,SAString Adresse,int Telephone,Connexion & cnx):con(cnx){
	 this->cin=Cin;
	 this->nom=Nom;
	 this->prenom=Prenom;
	 this->adresse=Adresse;
	 this->telephone=Telephone;
	 this->con=cnx;
}

void Client::Ajouter(const SAString &sCmd){
		// 
	/*
     Appel (exécution) d'une procédure stockée (fonction) 
	*/
	
	this->con.getCommande().setConnection(&this->con.getConnexion());
	this->con.getCommande().setCommandText(sCmd);
	this->con.getCommande().Param(1).setAsString() = this->cin;
    this->con.getCommande().Param(2).setAsString() = this->nom;
	this->con.getCommande().Param(3).setAsString() = this->prenom;
	this->con.getCommande().Param(4).setAsString() = this->adresse;
	this->con.getCommande().Param(5).setAsUInt64()  = this->telephone;
    this->con.getCommande().Execute();

}

//MODIFICATION
void Client::Modifier(const SAString &sCmd){
	this->con.getCommande().setConnection(&this->con.getConnexion());
	this->con.getCommande().setCommandText(sCmd);
	this->con.getCommande().Param(1).setAsString() = this->cin;
    this->con.getCommande().Param(2).setAsString() = this->nom;
	this->con.getCommande().Param(3).setAsString() = this->prenom;
	this->con.getCommande().Param(4).setAsString() = this->adresse;
	this->con.getCommande().Param(5).setAsUInt64()  = this->telephone;
    this->con.getCommande().Execute();
}
// LA SUPPRESSION 
void Client::Supprimer(const SAString &sCmd){
	this->con.getCommande().setConnection(&this->con.getConnexion());
	this->con.getCommande().setCommandText(sCmd);
	this->con.getCommande().Param(1).setAsString() =this->cin;
    this->con.getCommande().Execute();
}
//Nombre de lignes
int Client::rowCount(){
	  /*
     Appel (exécution) d'une procédure stockée (fonction) 
	*/
	this->con.getCommande().setConnection(&this->con.getConnexion());
	this->con.getCommande().setCommandText("select RowsCountClient();");
    this->con.getCommande().Execute();
	int row=0;
	while(this->con.getCommande().FetchNext()){
		row = this->con.getCommande().Field("RowsCountClient").asLong();
	}
	return row > 0 ? row : 0;
}

string ** Client::getAll(){
	   
		this->con.getCommande().setConnection(&this->con.getConnexion());
        this->con.getCommande().setCommandText("Select * from client order by nom");

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
// VERIFICATION DE L'EXISTENCE DU CLIENT
int Client::existe(){
	/*
     Appel (exécution) d'une procédure stockée (fonction) 
	*/
	this->con.getCommande().setConnection(&this->con.getConnexion());
	this->con.getCommande().setCommandText("select existeClient(:1)");
	this->con.getCommande().Param(1).setAsString()=this->cin;
    this->con.getCommande().Execute();
	int row=0;
	while(this->con.getCommande().FetchNext()){
		row = this->con.getCommande().Field("existeclient").asLong();
	}
	return row;
};

Client & Client::operator=(const Client & client){
	 this->id_Client=client.id_Client;
	 this->nom=client.nom;
	 this->prenom=client.prenom;
	 this->adresse=client.adresse;
	 this->telephone=client.telephone;
     // LIST MUST BE DELETED :: ?
	 return *this;
}

Client & Client::getClientById(){
	this->con.getCommande().setConnection(&this->con.getConnexion());
	this->con.getCommande().setCommandText("select * from get_client(:1)");
	this->con.getCommande().Param(1).setAsString()=this->cin;
    this->con.getCommande().Execute();
	int row=0;
	while(this->con.getCommande().FetchNext()){
		 this->cin=this->con.getCommande().Field(1).asInt64();
		 this->nom=this->con.getCommande().Field(2).asString();
		 this->prenom=this->con.getCommande().Field(3).asString();
		 this->adresse=this->con.getCommande().Field(4).asInt64();
		 this->telephone=this->con.getCommande().Field(5).asLong();
	}
	return *this;
}
Client::~Client(){
	   
}