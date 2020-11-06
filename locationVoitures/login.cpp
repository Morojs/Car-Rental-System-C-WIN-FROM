#include "login.h"
#include<SQLAPI.h>   
#include<WinUser.h>
#include "Connexion.h"
using namespace System;
using namespace System::Windows::Forms;

// START POINT
int main(array<String^>^ args){
	 //

	 Application::EnableVisualStyles();
	 Application::SetCompatibleTextRenderingDefault(false);
	 locationVoitures::login form;
	 Application::Run(%form);
	 return 0;
}