#include "Connexion.h"
#include<string>
#include<cstring>

Connexion::Connexion(){}
Connexion::Connexion(SAString odbc,SAString user,SAString password){
   
   this->odbc=odbc;
   this->user=user;
   this->pwd=password;
}
Connexion & Connexion::operator=(const Connexion & con){
	  this->odbc=con.odbc;
	  this->user=con.user;
	  this->pwd=con.pwd;
	  return *this;
}

void Connexion::Connecter(){
	   try{
			con.Connect(this->odbc,this->user,this->pwd,SA_ODBC_Client);
	   }catch(SAException & x){
		   
        // print error message
	       MessageBoxA(NULL, (const char*)x.ErrText(), "CLIENT" ,  MB_ICONERROR | MB_ICONERROR);
	   }
} 
void Connexion::Deconnecter(){
      con.Disconnect();
} 

Connexion::~Connexion(){}

int Connexion::ExecuterProcExiste(const SAString &sCmd,const SAString &param1,const SAString &param2){
	/*
     Appel (exécution) d'une procédure stockée (fonction) 
	*/
	cmd.setConnection(&this->con);
	cmd.setCommandText(sCmd);
	cmd.Param(1).setAsString() = param1;
    cmd.Param(2).setAsString() = param2;
    cmd.Execute();
	int row=0;
	while(cmd.FetchNext()){
		row = cmd.Field("existe").asLong();
	}
	return row;
}

SACommand & Connexion::getCommande(){
	//
	return this->cmd;
}
SAConnection & Connexion::getConnexion(){
	//
	return this->con;
}
bool Connexion::status(){
   return this->con.isConnected();
}
