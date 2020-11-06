#pragma once

#include "Connexion.h"
#include "Administrateur.h"
#include "Admin.h"
#include <msclr\marshal_cppstd.h>

namespace locationVoitures {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Configuration;

	/// <summary>
	/// Description résumée de login
	/// </summary>
	public ref class login : public System::Windows::Forms::Form 
	{
	
	public:
		login(void)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
		}
	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~login()
		{
			if (components)
			{
				delete components;
			}
		}
	
	//
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Button^  btnConnecter;
	protected: 



	private: System::Windows::Forms::TextBox^  txtpwd;

	private: System::Windows::Forms::TextBox^  txtlogin;
	private: System::Windows::Forms::PictureBox^  pictureBox3;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: Microsoft::VisualBasic::PowerPacks::ShapeContainer^  shapeContainer1;
	private: Microsoft::VisualBasic::PowerPacks::LineShape^  lineShape1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::LinkLabel^  linkLabel1;



	
	protected: 
	private: 
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container ^components;
	
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(login::typeid));
			
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->btnConnecter = (gcnew System::Windows::Forms::Button());
			this->txtpwd = (gcnew System::Windows::Forms::TextBox());
			this->txtlogin = (gcnew System::Windows::Forms::TextBox());
			this->shapeContainer1 = (gcnew Microsoft::VisualBasic::PowerPacks::ShapeContainer());
			this->lineShape1 = (gcnew Microsoft::VisualBasic::PowerPacks::LineShape());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::GhostWhite;
			this->panel1->Controls->Add(this->linkLabel1);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->pictureBox3);
			this->panel1->Controls->Add(this->pictureBox2);
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Controls->Add(this->btnConnecter);
			this->panel1->Controls->Add(this->txtpwd);
			this->panel1->Controls->Add(this->txtlogin);
			this->panel1->Controls->Add(this->shapeContainer1);
			this->panel1->Location = System::Drawing::Point(-5, -2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(635, 300);
			this->panel1->TabIndex = 0;
			// 
			// linkLabel1
			// 
			this->linkLabel1->ActiveLinkColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->linkLabel1->AutoSize = true;
			this->linkLabel1->Location = System::Drawing::Point(532, 281);
			this->linkLabel1->Name = L"linkLabel1";
			this->linkLabel1->Size = System::Drawing::Size(96, 13);
			this->linkLabel1->TabIndex = 12;
			this->linkLabel1->TabStop = true;
			this->linkLabel1->Text = L"CONFIGURATION";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label3->ForeColor = System::Drawing::Color::DarkGray;
			this->label3->Location = System::Drawing::Point(399, 180);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(70, 13);
			this->label3->TabIndex = 11;
			this->label3->Text = L"PASSWORD";
			this->label3->Visible = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label1->ForeColor = System::Drawing::Color::DarkGray;
			this->label1->Location = System::Drawing::Point(399, 133);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(68, 13);
			this->label1->TabIndex = 10;
			this->label1->Text = L"USERNAME";
			this->label1->Visible = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(330, 11);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(285, 17);
			this->label2->TabIndex = 9;
			this->label2->Text = L"GESTION DE LOCATION DE VOITURE";
			this->label2->Visible = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(338, 121);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(40, 36);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox3->TabIndex = 7;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(338, 168);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(40, 36);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 6;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(329, 320);
			this->pictureBox1->TabIndex = 5;
			this->pictureBox1->TabStop = false;
			// 
			// btnConnecter
			// 
			this->btnConnecter->BackColor = System::Drawing::Color::Goldenrod;
			this->btnConnecter->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->btnConnecter->Location = System::Drawing::Point(519, 219);
			this->btnConnecter->Name = L"btnConnecter";
			this->btnConnecter->Size = System::Drawing::Size(96, 31);
			this->btnConnecter->TabIndex = 4;
			this->btnConnecter->Text = L"Se Connecter";
			this->btnConnecter->UseVisualStyleBackColor = false;
			this->btnConnecter->Click += gcnew System::EventHandler(this, &login::btnConnecter_Click);
			// 
			// txtpwd
			// 
			this->txtpwd->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->txtpwd->Location = System::Drawing::Point(393, 172);
			this->txtpwd->Multiline = true;
			this->txtpwd->Name = L"txtpwd";
			this->txtpwd->PasswordChar = '*';
			this->txtpwd->Size = System::Drawing::Size(229, 28);
			this->txtpwd->TabIndex = 1;
			// 
			// txtlogin
			// 
			this->txtlogin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::World, 
				static_cast<System::Byte>(0)));
			this->txtlogin->Location = System::Drawing::Point(393, 125);
			this->txtlogin->Multiline = true;
			this->txtlogin->Name = L"txtlogin";
			this->txtlogin->Size = System::Drawing::Size(229, 28);
			this->txtlogin->TabIndex = 0;
			// 
			// shapeContainer1
			// 
			this->shapeContainer1->Location = System::Drawing::Point(0, 0);
			this->shapeContainer1->Margin = System::Windows::Forms::Padding(0);
			this->shapeContainer1->Name = L"shapeContainer1";
			this->shapeContainer1->Shapes->AddRange(gcnew cli::array< Microsoft::VisualBasic::PowerPacks::Shape^  >(1) {this->lineShape1});
			this->shapeContainer1->Size = System::Drawing::Size(635, 300);
			this->shapeContainer1->TabIndex = 8;
			this->shapeContainer1->TabStop = false;
			// 
			// lineShape1
			// 
			this->lineShape1->BorderColor = System::Drawing::Color::Coral;
			this->lineShape1->Name = L"lineShape1";
			this->lineShape1->X1 = 333;
			this->lineShape1->X2 = 609;
			this->lineShape1->Y1 = 33;
			this->lineShape1->Y2 = 33;
			// 
			// login
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(629, 297);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->MaximizeBox = false;
			this->Name = L"login";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"login";
			this->Load += gcnew System::EventHandler(this, &login::login_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void login_Load(System::Object^  sender, System::EventArgs^  e){
			    
			 }
	private: System::Void btnConnecter_Click(System::Object^  sender, System::EventArgs^  e){
			 
    SAConnection con;
    try
    { 
		
		// Conversion d'une chaine de caracteres : std::string to const char* en CLR C++
		 msclr::interop::marshal_context context;

		 //FICHIER DE CONFIGURATION APP.CONFIG  : POUR L'AUTHENTIFICATION POSTGRES ("ON VA CONVERTIR System::String to std::string by marshal lib")
		std::string  connectionString=context.marshal_as<std::string>(System::Configuration::ConfigurationManager::AppSettings["connectionString"]);
		std::string user=context.marshal_as<std::string>(System::Configuration::ConfigurationManager::AppSettings["user"]);
		std::string password=context.marshal_as<std::string>(System::Configuration::ConfigurationManager::AppSettings["password"]);

		const char* p_c_str_connectionString = connectionString.c_str();
		const char* p_c_str_postgresUser = user.c_str();
		const char* p_c_str_postgrespwd = password.c_str();

		// AUTHENTIFICATION ADMIN
         std::string std_login= context.marshal_as<std::string>(txtlogin->Text);
		 std::string std_pwd= context.marshal_as<std::string>(txtpwd->Text);

	     const char* p_c_str_login = std_login.c_str();
		 const char* p_c_str_pwd = std_pwd.c_str();
		 // INITIALISATION D'OBJET CONNEXION POUR L'AUTHENTIFICATION POSTGRES
		Connexion cnx(p_c_str_connectionString,p_c_str_postgresUser,p_c_str_postgrespwd);
		cnx.Connecter();
		//
		//AUTHENTIFICATION ADMINISTRATEUR
		Administrateur administrateur(p_c_str_login,p_c_str_pwd,cnx);
		if(administrateur.existe("select existe(:1,:2);")>0){
	    //AFFICHER LE FORMULAIRE ADMIN AVEC LA METHODE .SHOW SI L'UTILISATEUR EXISTE
		   locationVoitures::Admin^ admin=gcnew Admin();
		   admin->Show();
		   cnx.Deconnecter();
		   this->Hide();
		}
		else {
			// ELSE AFFICHER LE MESSAGE D'ERREUR
		   string Erreur="CET UTILISATEUR N'EXISTE PAS : RESULTAT = "+to_string(administrateur.existe("select existe(:1,:2);"));
		   MessageBoxA(NULL,Erreur.c_str(), "ERREUR D'AUTHENTIFICATION" , MB_ICONERROR | MB_ICONQUESTION);
		}
		
    } 
    catch(SAException & x) 
    { 
        try
        { 
		// SAConnection :: Rollback ()
        // peut également lever une exception
        // (si une erreur réseau par exemple),
        // nous serons prêts
            con.Rollback (); 
        } 
        catch(SAException &) 
        { 
			 
        } 
        // Afficher le message d'erreur
		MessageBoxA(NULL, (const char*)x.ErrText(), "ERREUR" , ERROR | MB_ICONQUESTION);
     } 
     }
};
}
