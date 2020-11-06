#pragma once
#include "Connexion.h"
#include "Client.h"
#include "Voiture.h"
#include <msclr\marshal_cppstd.h>
namespace locationVoitures {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de FLocation
	/// </summary>
	public ref class FLocation : public System::Windows::Forms::Form
	{
		Connexion * con;
	public:
		FLocation(void)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
			msclr::interop::marshal_context context;
		//FICHIER DE CONFIGURATION APP.CONFIG  : POUR L'AUTHENTIFICATION POSTGRES ("ON VA CONVERTIR System::String to std::string via marshal lib")
		std::string  connectionString=context.marshal_as<std::string>(System::Configuration::ConfigurationManager::AppSettings["connectionString"]);
		std::string user=context.marshal_as<std::string>(System::Configuration::ConfigurationManager::AppSettings["user"]);
		std::string password=context.marshal_as<std::string>(System::Configuration::ConfigurationManager::AppSettings["password"]);

		const char* p_c_str_connectionString = connectionString.c_str();
		const char* p_c_str_postgresUser = user.c_str();
		const char* p_c_str_postgrespwd = password.c_str();
		this->con=new Connexion(p_c_str_connectionString,p_c_str_postgresUser,p_c_str_postgrespwd);
		this->con->Connecter();
		}


	    void viderChampsLocation() {
			comboClients->Text="";
			comboVoitures->Text="";
			txtduree->Text="";
			txtdatedebut->Text="";
			txtdatefin->Text="";
		}

		int checkNullValues(){
			return comboClients->Text=="" || comboVoitures->Text=="" || txtduree->Text=="" || txtdatedebut->Text=="" ||   txtdatefin->Text=="" ? 1 : 0 ;
		}

		void fillListVoitures(){
			  Voiture voiture(*this->con);
			if(voiture.rowCount()!=0)
			{
			   for(int i=0;i<voiture.rowCount();i++){
					this->comboVoitures->Items->Insert(i,gcnew String(voiture.getAll()[i][0].c_str()));
			   }
			}
		}
		void fillListClient(){
		    Client client(*this->con);
			if(client.rowCount()!=0)
			{
			   for(int i=0;i<client.rowCount();i++){
					this->comboClients->Items->Insert(i,gcnew String(client.getAll()[i][0].c_str()));
			   }
			}
		}
		void fillListLocation(){
			//
		}
	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~FLocation()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	protected: 



	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Button^  btnannuler;

	private: System::Windows::Forms::Button^  btnsupp;

	private: System::Windows::Forms::Button^  btnmod;

	private: System::Windows::Forms::Button^  btnajout;

	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::MaskedTextBox^  txtdatefin;
	private: System::Windows::Forms::MaskedTextBox^  txtdatedebut;
	private: System::Windows::Forms::TextBox^  txtduree;
	private: System::Windows::Forms::ComboBox^  comboVoitures;
	private: System::Windows::Forms::ComboBox^  comboClients;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
	private: System::Windows::Forms::Label^  txtvoitureinfos;
	private: System::Windows::Forms::Label^  txtclientinfos;

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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->txtvoitureinfos = (gcnew System::Windows::Forms::Label());
			this->txtclientinfos = (gcnew System::Windows::Forms::Label());
			this->btnannuler = (gcnew System::Windows::Forms::Button());
			this->btnsupp = (gcnew System::Windows::Forms::Button());
			this->btnmod = (gcnew System::Windows::Forms::Button());
			this->btnajout = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txtdatefin = (gcnew System::Windows::Forms::MaskedTextBox());
			this->txtdatedebut = (gcnew System::Windows::Forms::MaskedTextBox());
			this->txtduree = (gcnew System::Windows::Forms::TextBox());
			this->comboVoitures = (gcnew System::Windows::Forms::ComboBox());
			this->comboClients = (gcnew System::Windows::Forms::ComboBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->BackgroundColor = System::Drawing::Color::Azure;
			this->dataGridView1->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::None;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {this->Column1, 
				this->Column2, this->Column3});
			this->dataGridView1->Location = System::Drawing::Point(512, 0);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView1->Size = System::Drawing::Size(502, 378);
			this->dataGridView1->TabIndex = 3;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"CIN Client";
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Matricule Voiture";
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Duree";
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::White;
			this->panel1->Controls->Add(this->txtvoitureinfos);
			this->panel1->Controls->Add(this->txtclientinfos);
			this->panel1->Controls->Add(this->btnannuler);
			this->panel1->Controls->Add(this->btnsupp);
			this->panel1->Controls->Add(this->btnmod);
			this->panel1->Controls->Add(this->btnajout);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->txtdatefin);
			this->panel1->Controls->Add(this->txtdatedebut);
			this->panel1->Controls->Add(this->txtduree);
			this->panel1->Controls->Add(this->comboVoitures);
			this->panel1->Controls->Add(this->comboClients);
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(515, 378);
			this->panel1->TabIndex = 2;
			// 
			// txtvoitureinfos
			// 
			this->txtvoitureinfos->AutoSize = true;
			this->txtvoitureinfos->Location = System::Drawing::Point(158, 102);
			this->txtvoitureinfos->Name = L"txtvoitureinfos";
			this->txtvoitureinfos->Size = System::Drawing::Size(10, 13);
			this->txtvoitureinfos->TabIndex = 15;
			this->txtvoitureinfos->Text = L".";
			// 
			// txtclientinfos
			// 
			this->txtclientinfos->AutoSize = true;
			this->txtclientinfos->Location = System::Drawing::Point(158, 43);
			this->txtclientinfos->Name = L"txtclientinfos";
			this->txtclientinfos->Size = System::Drawing::Size(10, 13);
			this->txtclientinfos->TabIndex = 14;
			this->txtclientinfos->Text = L".";
			// 
			// btnannuler
			// 
			this->btnannuler->Location = System::Drawing::Point(333, 267);
			this->btnannuler->Name = L"btnannuler";
			this->btnannuler->Size = System::Drawing::Size(90, 29);
			this->btnannuler->TabIndex = 13;
			this->btnannuler->Text = L"ANNULER";
			this->btnannuler->UseVisualStyleBackColor = true;
			this->btnannuler->Click += gcnew System::EventHandler(this, &FLocation::btnannuler_Click);
			// 
			// btnsupp
			// 
			this->btnsupp->Location = System::Drawing::Point(237, 267);
			this->btnsupp->Name = L"btnsupp";
			this->btnsupp->Size = System::Drawing::Size(90, 29);
			this->btnsupp->TabIndex = 12;
			this->btnsupp->Text = L"SUPPRIMER";
			this->btnsupp->UseVisualStyleBackColor = true;
			this->btnsupp->Click += gcnew System::EventHandler(this, &FLocation::btnsupp_Click);
			// 
			// btnmod
			// 
			this->btnmod->Location = System::Drawing::Point(141, 267);
			this->btnmod->Name = L"btnmod";
			this->btnmod->Size = System::Drawing::Size(90, 29);
			this->btnmod->TabIndex = 11;
			this->btnmod->Text = L"MODIFIER";
			this->btnmod->UseVisualStyleBackColor = true;
			this->btnmod->Click += gcnew System::EventHandler(this, &FLocation::btnmod_Click);
			// 
			// btnajout
			// 
			this->btnajout->Location = System::Drawing::Point(45, 267);
			this->btnajout->Name = L"btnajout";
			this->btnajout->Size = System::Drawing::Size(90, 29);
			this->btnajout->TabIndex = 10;
			this->btnajout->Text = L"AJOUTER";
			this->btnajout->UseVisualStyleBackColor = true;
			this->btnajout->Click += gcnew System::EventHandler(this, &FLocation::btnajout_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(41, 226);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(73, 20);
			this->label5->TabIndex = 9;
			this->label5->Text = L"Date fin :";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(41, 176);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(97, 20);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Date début :";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(41, 131);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(61, 20);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Durée :";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(41, 78);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(68, 20);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Voiture :";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(41, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(57, 20);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Client :";
			// 
			// txtdatefin
			// 
			this->txtdatefin->BackColor = System::Drawing::Color::Gainsboro;
			this->txtdatefin->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtdatefin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->txtdatefin->Location = System::Drawing::Point(153, 222);
			this->txtdatefin->Mask = L"00/00/0000";
			this->txtdatefin->Name = L"txtdatefin";
			this->txtdatefin->Size = System::Drawing::Size(245, 23);
			this->txtdatefin->TabIndex = 4;
			this->txtdatefin->ValidatingType = System::DateTime::typeid;
			// 
			// txtdatedebut
			// 
			this->txtdatedebut->BackColor = System::Drawing::Color::Gainsboro;
			this->txtdatedebut->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtdatedebut->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->txtdatedebut->Location = System::Drawing::Point(153, 173);
			this->txtdatedebut->Mask = L"00/00/0000";
			this->txtdatedebut->Name = L"txtdatedebut";
			this->txtdatedebut->Size = System::Drawing::Size(245, 23);
			this->txtdatedebut->TabIndex = 3;
			this->txtdatedebut->ValidatingType = System::DateTime::typeid;
			// 
			// txtduree
			// 
			this->txtduree->BackColor = System::Drawing::Color::Gainsboro;
			this->txtduree->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtduree->Location = System::Drawing::Point(153, 126);
			this->txtduree->Multiline = true;
			this->txtduree->Name = L"txtduree";
			this->txtduree->Size = System::Drawing::Size(245, 27);
			this->txtduree->TabIndex = 2;
			// 
			// comboVoitures
			// 
			this->comboVoitures->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboVoitures->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->comboVoitures->FormattingEnabled = true;
			this->comboVoitures->Location = System::Drawing::Point(153, 75);
			this->comboVoitures->Name = L"comboVoitures";
			this->comboVoitures->Size = System::Drawing::Size(245, 24);
			this->comboVoitures->TabIndex = 1;
			// 
			// comboClients
			// 
			this->comboClients->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboClients->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->comboClients->FormattingEnabled = true;
			this->comboClients->Location = System::Drawing::Point(153, 16);
			this->comboClients->Name = L"comboClients";
			this->comboClients->Size = System::Drawing::Size(245, 24);
			this->comboClients->TabIndex = 0;
			// 
			// FLocation
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1014, 375);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"FLocation";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FLocation";
			this->Load += gcnew System::EventHandler(this, &FLocation::FLocation_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void FLocation_Load(System::Object^  sender, System::EventArgs^  e) {
				 this->fillListClient();
				 this->fillListVoitures();
			 }
	private: System::Void btnajout_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void btnmod_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void btnsupp_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void btnannuler_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}
