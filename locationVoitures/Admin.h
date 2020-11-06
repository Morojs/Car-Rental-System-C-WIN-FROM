#pragma once

#include "Connexion.h"
#include "FLocation.h"
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
	/// Description résumée de Admin
	/// </summary>
	public ref class Admin : public System::Windows::Forms::Form
	{
		// CONNEXION
	Connexion * con;
	public:
		Admin(void)
		{
			
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
		msclr::interop::marshal_context context;
		//FICHIER DE CONFIGURATION APP.CONFIG  : POUR L'AUTHENTIFICATION POSTGRES ("ON VA CONVERTIR System::String to std::string by marshal lib")
		std::string  connectionString=context.marshal_as<std::string>(System::Configuration::ConfigurationManager::AppSettings["connectionString"]);
		std::string user=context.marshal_as<std::string>(System::Configuration::ConfigurationManager::AppSettings["user"]);
		std::string password=context.marshal_as<std::string>(System::Configuration::ConfigurationManager::AppSettings["password"]);

		const char* p_c_str_connectionString = connectionString.c_str();
		const char* p_c_str_postgresUser = user.c_str();
		const char* p_c_str_postgrespwd = password.c_str();
		this->con=new Connexion(p_c_str_connectionString,p_c_str_postgresUser,p_c_str_postgrespwd);
		this->con->Connecter();
			
		}
		void viderClient(){
			id_client->Text="";
			txtnomclient->Text="";
			txtprenomclient->Text="";
			txtadresseclient->Text="";
			txttelephoneclient->Text="";
		}
	   void viderChampsVoiture(){
		    txtmatricule->Text="";
			txtmodele->Text="";
			txtnbrstock->Text="";
			txttarif->Text="";
		}
	   int voitureNullValues(){
		    return txtmatricule->Text=="" || txtmodele->Text=="" || txtnbrstock->Text== "" || txttarif->Text=="" ? 1 : 0;
	   }
		int clientNullValues(){
			return id_client->Text=="" || txtnomclient->Text=="" || txtprenomclient->Text=="" || txtadresseclient->Text=="" || txttelephoneclient->Text=="" ? 1 : 0;
		}
		void fillListVoitures(){
			  Voiture voiture(*this->con);
			if(voiture.rowCount()!=0)
			{
			   for(int i=0;i<voiture.rowCount();i++){
		  	        /*MessageBoxA(NULL,to_string(i).c_str(), "CLIENT" , MB_OK | MB_ICONQUESTION);*/
					this->dataGridView2->Rows->Insert(i,gcnew String(voiture.getAll()[i][0].c_str()),
						                                gcnew String(voiture.getAll()[i][1].c_str()),
														gcnew String(voiture.getAll()[i][2].c_str()),
														gcnew String(voiture.getAll()[i][3].c_str()),
														gcnew String(voiture.getAll()[i][4].c_str()));
			   }
			}
		}
		void fillListClient(){
		    Client client(*this->con);
			if(client.rowCount()!=0)
			{
			   for(int i=0;i<client.rowCount();i++){
		  	        /*MessageBoxA(NULL,to_string(i).c_str(), "CLIENT" , MB_OK | MB_ICONQUESTION);*/
					this->dataGridView1->Rows->Insert(i,gcnew String(client.getAll()[i][0].c_str()),
						                                gcnew String(client.getAll()[i][1].c_str()),
														gcnew String(client.getAll()[i][2].c_str()),
														gcnew String(client.getAll()[i][3].c_str()),
														gcnew String(client.getAll()[i][4].c_str()));
			   }
			}
		}
	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~Admin()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::TabPage^  tabControle;
	protected: 

	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  id_client;
	private: System::Windows::Forms::TextBox^  txtadresseclient;


	private: System::Windows::Forms::TextBox^  txttelephoneclient;

	private: System::Windows::Forms::TextBox^  txtprenomclient;

	private: System::Windows::Forms::TextBox^  txtnomclient;

	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::DataGridView^  dataGridView1;




	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  viderVoiture;
	private: System::Windows::Forms::Button^  modVoiture;
	private: System::Windows::Forms::Button^  suppVoiture;
	private: System::Windows::Forms::Button^  ajoutVoiture;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
private: System::Windows::Forms::TextBox^  txtmatricule;

	private: System::Windows::Forms::TextBox^  txttarif;
	private: System::Windows::Forms::TextBox^  txtnbrstock;

	private: System::Windows::Forms::TextBox^  txtmodele;
private: System::Windows::Forms::DataGridView^  dataGridView2;
private: System::Windows::Forms::PictureBox^  pictureBox1;
private: System::Windows::Forms::TabControl^  tabControl1;
private: System::Windows::Forms::ComboBox^  combomarque;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Matricule;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Modele;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Marque;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  stock;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Tarif;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column4;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column5;
private: System::Windows::Forms::MenuStrip^  menuStrip1;
private: System::Windows::Forms::ToolStripMenuItem^  lOCATIONToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  pENALISATIONToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  rETOURVOITUREToolStripMenuItem;



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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Admin::typeid));
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabControle = (gcnew System::Windows::Forms::TabPage());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->id_client = (gcnew System::Windows::Forms::TextBox());
			this->txtadresseclient = (gcnew System::Windows::Forms::TextBox());
			this->txttelephoneclient = (gcnew System::Windows::Forms::TextBox());
			this->txtprenomclient = (gcnew System::Windows::Forms::TextBox());
			this->txtnomclient = (gcnew System::Windows::Forms::TextBox());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->combomarque = (gcnew System::Windows::Forms::ComboBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->Matricule = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Modele = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Marque = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->stock = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Tarif = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->viderVoiture = (gcnew System::Windows::Forms::Button());
			this->modVoiture = (gcnew System::Windows::Forms::Button());
			this->suppVoiture = (gcnew System::Windows::Forms::Button());
			this->ajoutVoiture = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->txtmatricule = (gcnew System::Windows::Forms::TextBox());
			this->txttarif = (gcnew System::Windows::Forms::TextBox());
			this->txtnbrstock = (gcnew System::Windows::Forms::TextBox());
			this->txtmodele = (gcnew System::Windows::Forms::TextBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->lOCATIONToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pENALISATIONToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->rETOURVOITUREToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tabControl1->SuspendLayout();
			this->tabControle->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView2))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabControle);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0), true));
			this->tabControl1->Location = System::Drawing::Point(0, 52);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(972, 478);
			this->tabControl1->TabIndex = 0;
			// 
			// tabControle
			// 
			this->tabControle->BackColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->tabControle->Controls->Add(this->button4);
			this->tabControle->Controls->Add(this->dataGridView1);
			this->tabControle->Controls->Add(this->button3);
			this->tabControle->Controls->Add(this->button2);
			this->tabControle->Controls->Add(this->button1);
			this->tabControle->Controls->Add(this->label5);
			this->tabControle->Controls->Add(this->label4);
			this->tabControle->Controls->Add(this->label3);
			this->tabControle->Controls->Add(this->label2);
			this->tabControle->Controls->Add(this->label1);
			this->tabControle->Controls->Add(this->id_client);
			this->tabControle->Controls->Add(this->txtadresseclient);
			this->tabControle->Controls->Add(this->txttelephoneclient);
			this->tabControle->Controls->Add(this->txtprenomclient);
			this->tabControle->Controls->Add(this->txtnomclient);
			this->tabControle->Location = System::Drawing::Point(4, 26);
			this->tabControle->Name = L"tabControle";
			this->tabControle->Padding = System::Windows::Forms::Padding(3);
			this->tabControle->Size = System::Drawing::Size(964, 448);
			this->tabControle->TabIndex = 0;
			this->tabControle->Text = L"ESPACE CLIENT";
			this->tabControle->Click += gcnew System::EventHandler(this, &Admin::tabControle_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->button4->Location = System::Drawing::Point(491, 182);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(125, 50);
			this->button4->TabIndex = 14;
			this->button4->Text = L"ANNULER";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &Admin::button4_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllHeaders;
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {this->Column1, 
				this->Column2, this->Column3, this->Column4, this->Column5});
			this->dataGridView1->Location = System::Drawing::Point(8, 277);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView1->Size = System::Drawing::Size(953, 150);
			this->dataGridView1->TabIndex = 13;
			this->dataGridView1->Click += gcnew System::EventHandler(this, &Admin::dataGridView1_Click);
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"CIN CLEINT ";
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"NOM";
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"PRENOM";
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"TELEPHONE";
			this->Column4->Name = L"Column4";
			this->Column4->ReadOnly = true;
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Adresse";
			this->Column5->Name = L"Column5";
			this->Column5->ReadOnly = true;
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::GhostWhite;
			this->button3->Location = System::Drawing::Point(491, 68);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(125, 50);
			this->button3->TabIndex = 12;
			this->button3->Text = L"MODIFIER";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &Admin::button3_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::GhostWhite;
			this->button2->Location = System::Drawing::Point(491, 124);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(125, 50);
			this->button2->TabIndex = 11;
			this->button2->Text = L"SUPPRIMER";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Admin::button2_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::GhostWhite;
			this->button1->Location = System::Drawing::Point(491, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(125, 50);
			this->button1->TabIndex = 10;
			this->button1->Text = L"AJOUTER";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Admin::button1_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label5->Location = System::Drawing::Point(20, 13);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(49, 20);
			this->label5->TabIndex = 9;
			this->label5->Text = L"CIN :";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label4->Location = System::Drawing::Point(23, 188);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(85, 20);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Adresse :";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label3->Location = System::Drawing::Point(23, 144);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(103, 20);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Telephone :";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label2->Location = System::Drawing::Point(21, 101);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(80, 20);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Prenom :";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label1->Location = System::Drawing::Point(23, 54);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(55, 20);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Nom :";
			// 
			// id_client
			// 
			this->id_client->Location = System::Drawing::Point(132, 7);
			this->id_client->Multiline = true;
			this->id_client->Name = L"id_client";
			this->id_client->Size = System::Drawing::Size(207, 26);
			this->id_client->TabIndex = 4;
			// 
			// txtadresseclient
			// 
			this->txtadresseclient->Location = System::Drawing::Point(132, 182);
			this->txtadresseclient->Multiline = true;
			this->txtadresseclient->Name = L"txtadresseclient";
			this->txtadresseclient->Size = System::Drawing::Size(326, 26);
			this->txtadresseclient->TabIndex = 3;
			// 
			// txttelephoneclient
			// 
			this->txttelephoneclient->Location = System::Drawing::Point(132, 138);
			this->txttelephoneclient->Multiline = true;
			this->txttelephoneclient->Name = L"txttelephoneclient";
			this->txttelephoneclient->Size = System::Drawing::Size(207, 26);
			this->txttelephoneclient->TabIndex = 2;
			// 
			// txtprenomclient
			// 
			this->txtprenomclient->Location = System::Drawing::Point(132, 95);
			this->txtprenomclient->Multiline = true;
			this->txtprenomclient->Name = L"txtprenomclient";
			this->txtprenomclient->Size = System::Drawing::Size(207, 26);
			this->txtprenomclient->TabIndex = 1;
			// 
			// txtnomclient
			// 
			this->txtnomclient->Location = System::Drawing::Point(132, 51);
			this->txtnomclient->Multiline = true;
			this->txtnomclient->Name = L"txtnomclient";
			this->txtnomclient->Size = System::Drawing::Size(207, 26);
			this->txtnomclient->TabIndex = 0;
			// 
			// tabPage2
			// 
			this->tabPage2->BackColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->tabPage2->Controls->Add(this->combomarque);
			this->tabPage2->Controls->Add(this->pictureBox1);
			this->tabPage2->Controls->Add(this->dataGridView2);
			this->tabPage2->Controls->Add(this->viderVoiture);
			this->tabPage2->Controls->Add(this->modVoiture);
			this->tabPage2->Controls->Add(this->suppVoiture);
			this->tabPage2->Controls->Add(this->ajoutVoiture);
			this->tabPage2->Controls->Add(this->label6);
			this->tabPage2->Controls->Add(this->label7);
			this->tabPage2->Controls->Add(this->label8);
			this->tabPage2->Controls->Add(this->label9);
			this->tabPage2->Controls->Add(this->label10);
			this->tabPage2->Controls->Add(this->txtmatricule);
			this->tabPage2->Controls->Add(this->txttarif);
			this->tabPage2->Controls->Add(this->txtnbrstock);
			this->tabPage2->Controls->Add(this->txtmodele);
			this->tabPage2->Location = System::Drawing::Point(4, 26);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(964, 448);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"ESPACE VOITURE";
			// 
			// combomarque
			// 
			this->combomarque->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->combomarque->FormattingEnabled = true;
			this->combomarque->Items->AddRange(gcnew cli::array< System::Object^  >(5) {L"FORD FIESTA", L"PEUGEOT", L"RENAULT CLIO", 
				L"RENAULT DACIA", L"RENAULT MEGANE"});
			this->combomarque->Location = System::Drawing::Point(187, 118);
			this->combomarque->Name = L"combomarque";
			this->combomarque->Size = System::Drawing::Size(207, 25);
			this->combomarque->Sorted = true;
			this->combomarque->TabIndex = 31;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(577, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(386, 257);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 30;
			this->pictureBox1->TabStop = false;
			// 
			// dataGridView2
			// 
			this->dataGridView2->AllowUserToAddRows = false;
			this->dataGridView2->AllowUserToDeleteRows = false;
			this->dataGridView2->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView2->BackgroundColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {this->Matricule, 
				this->Modele, this->Marque, this->stock, this->Tarif});
			this->dataGridView2->Location = System::Drawing::Point(3, 257);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->ReadOnly = true;
			this->dataGridView2->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView2->Size = System::Drawing::Size(955, 188);
			this->dataGridView2->TabIndex = 29;
			this->dataGridView2->Click += gcnew System::EventHandler(this, &Admin::dataGridView2_Click);
			// 
			// Matricule
			// 
			this->Matricule->HeaderText = L"Matricule";
			this->Matricule->Name = L"Matricule";
			this->Matricule->ReadOnly = true;
			// 
			// Modele
			// 
			this->Modele->HeaderText = L"Modele";
			this->Modele->Name = L"Modele";
			this->Modele->ReadOnly = true;
			// 
			// Marque
			// 
			this->Marque->HeaderText = L"Marque";
			this->Marque->Name = L"Marque";
			this->Marque->ReadOnly = true;
			// 
			// stock
			// 
			this->stock->HeaderText = L"Nombre en Stock";
			this->stock->Name = L"stock";
			this->stock->ReadOnly = true;
			// 
			// Tarif
			// 
			this->Tarif->HeaderText = L"Tarif";
			this->Tarif->Name = L"Tarif";
			this->Tarif->ReadOnly = true;
			// 
			// viderVoiture
			// 
			this->viderVoiture->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->viderVoiture->Location = System::Drawing::Point(429, 189);
			this->viderVoiture->Name = L"viderVoiture";
			this->viderVoiture->Size = System::Drawing::Size(129, 47);
			this->viderVoiture->TabIndex = 28;
			this->viderVoiture->Text = L"ANNULER";
			this->viderVoiture->UseVisualStyleBackColor = false;
			this->viderVoiture->Click += gcnew System::EventHandler(this, &Admin::viderVoiture_Click);
			// 
			// modVoiture
			// 
			this->modVoiture->BackColor = System::Drawing::Color::GhostWhite;
			this->modVoiture->Location = System::Drawing::Point(429, 72);
			this->modVoiture->Name = L"modVoiture";
			this->modVoiture->Size = System::Drawing::Size(129, 55);
			this->modVoiture->TabIndex = 27;
			this->modVoiture->Text = L"MODIFIER";
			this->modVoiture->UseVisualStyleBackColor = false;
			this->modVoiture->Click += gcnew System::EventHandler(this, &Admin::modVoiture_Click);
			// 
			// suppVoiture
			// 
			this->suppVoiture->BackColor = System::Drawing::Color::GhostWhite;
			this->suppVoiture->Location = System::Drawing::Point(429, 133);
			this->suppVoiture->Name = L"suppVoiture";
			this->suppVoiture->Size = System::Drawing::Size(129, 50);
			this->suppVoiture->TabIndex = 26;
			this->suppVoiture->Text = L"SUPPRIMER";
			this->suppVoiture->UseVisualStyleBackColor = false;
			this->suppVoiture->Click += gcnew System::EventHandler(this, &Admin::suppVoiture_Click);
			// 
			// ajoutVoiture
			// 
			this->ajoutVoiture->BackColor = System::Drawing::Color::GhostWhite;
			this->ajoutVoiture->Location = System::Drawing::Point(429, 13);
			this->ajoutVoiture->Name = L"ajoutVoiture";
			this->ajoutVoiture->Size = System::Drawing::Size(129, 53);
			this->ajoutVoiture->TabIndex = 25;
			this->ajoutVoiture->Text = L"AJOUTER";
			this->ajoutVoiture->UseVisualStyleBackColor = false;
			this->ajoutVoiture->Click += gcnew System::EventHandler(this, &Admin::ajoutVoiture_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label6->Location = System::Drawing::Point(24, 32);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(92, 20);
			this->label6->TabIndex = 24;
			this->label6->Text = L"Matricule :";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label7->Location = System::Drawing::Point(27, 207);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(55, 20);
			this->label7->TabIndex = 23;
			this->label7->Text = L"Tarif :";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label8->Location = System::Drawing::Point(27, 163);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(154, 20);
			this->label8->TabIndex = 22;
			this->label8->Text = L"Nombre en stock :";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label9->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label9->Location = System::Drawing::Point(25, 120);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(79, 20);
			this->label9->TabIndex = 21;
			this->label9->Text = L"Marque :";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label10->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label10->Location = System::Drawing::Point(27, 73);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(77, 20);
			this->label10->TabIndex = 20;
			this->label10->Text = L"Modele :";
			// 
			// txtmatricule
			// 
			this->txtmatricule->Location = System::Drawing::Point(187, 32);
			this->txtmatricule->Multiline = true;
			this->txtmatricule->Name = L"txtmatricule";
			this->txtmatricule->Size = System::Drawing::Size(207, 26);
			this->txtmatricule->TabIndex = 19;
			// 
			// txttarif
			// 
			this->txttarif->Location = System::Drawing::Point(187, 201);
			this->txttarif->Multiline = true;
			this->txttarif->Name = L"txttarif";
			this->txttarif->Size = System::Drawing::Size(207, 26);
			this->txttarif->TabIndex = 18;
			// 
			// txtnbrstock
			// 
			this->txtnbrstock->Location = System::Drawing::Point(187, 157);
			this->txtnbrstock->Multiline = true;
			this->txtnbrstock->Name = L"txtnbrstock";
			this->txtnbrstock->Size = System::Drawing::Size(207, 26);
			this->txtnbrstock->TabIndex = 17;
			// 
			// txtmodele
			// 
			this->txtmodele->Location = System::Drawing::Point(187, 73);
			this->txtmodele->Multiline = true;
			this->txtmodele->Name = L"txtmodele";
			this->txtmodele->Size = System::Drawing::Size(207, 26);
			this->txtmodele->TabIndex = 15;
			// 
			// menuStrip1
			// 
			this->menuStrip1->AccessibleRole = System::Windows::Forms::AccessibleRole::MenuBar;
			this->menuStrip1->BackColor = System::Drawing::SystemColors::Menu;
			this->menuStrip1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->lOCATIONToolStripMenuItem, 
				this->pENALISATIONToolStripMenuItem, this->rETOURVOITUREToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(971, 28);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// lOCATIONToolStripMenuItem
			// 
			this->lOCATIONToolStripMenuItem->Name = L"lOCATIONToolStripMenuItem";
			this->lOCATIONToolStripMenuItem->Size = System::Drawing::Size(92, 24);
			this->lOCATIONToolStripMenuItem->Text = L"LOCATION";
			this->lOCATIONToolStripMenuItem->Click += gcnew System::EventHandler(this, &Admin::lOCATIONToolStripMenuItem_Click);
			// 
			// pENALISATIONToolStripMenuItem
			// 
			this->pENALISATIONToolStripMenuItem->Name = L"pENALISATIONToolStripMenuItem";
			this->pENALISATIONToolStripMenuItem->Size = System::Drawing::Size(121, 24);
			this->pENALISATIONToolStripMenuItem->Text = L"PENALISATION";
			// 
			// rETOURVOITUREToolStripMenuItem
			// 
			this->rETOURVOITUREToolStripMenuItem->Name = L"rETOURVOITUREToolStripMenuItem";
			this->rETOURVOITUREToolStripMenuItem->Size = System::Drawing::Size(139, 24);
			this->rETOURVOITUREToolStripMenuItem->Text = L"RETOUR VOITURE";
			// 
			// Admin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->ClientSize = System::Drawing::Size(971, 531);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->MaximizeBox = false;
			this->Name = L"Admin";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Admin";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Admin::Admin_FormClosing);
			this->Load += gcnew System::EventHandler(this, &Admin::Admin_Load);
			this->tabControl1->ResumeLayout(false);
			this->tabControle->ResumeLayout(false);
			this->tabControle->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView2))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void Admin_Load(System::Object^  sender, System::EventArgs^  e) {
				 //string etat=this->con->status() ? "True" : "false";
				 this->fillListClient();
				 this->fillListVoitures();
       }
      private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		 
			if(clientNullValues()==1)
			{
			  MessageBoxA(NULL,"Impossible d'insérer la valeur NULL veuillez remplir tous les champs requis", "CLIENT" ,  MB_ICONERROR | MB_ICONERROR);
			  return;
			}

	    // Conversion d'une chaine de caracteres : std::string to const char* en CLR C++
		  
		   msclr::interop::marshal_context context;
          		   
		   std::string std_cin= context.marshal_as<std::string>(id_client->Text);
		   std::string std_nom= context.marshal_as<std::string>(txtnomclient->Text);
		   std::string std_prenom= context.marshal_as<std::string>(txtprenomclient->Text);
		   std::string std_adresse= context.marshal_as<std::string>(txtadresseclient->Text);
		   std::string std_telephone= context.marshal_as<std::string>(txttelephoneclient->Text);

	       const char* p_c_str_cin = std_cin.c_str();
		   const char* p_c_str_nom = std_nom.c_str();
		   const char* p_c_str_prenom = std_prenom.c_str();
		   const char* p_c_str_adresse = std_adresse.c_str();
		   const char* p_c_str_telephone = std_telephone.c_str();
		   

			Client existeClient(context.marshal_as<std::string>(id_client->Text).c_str(),*this->con);
			if (existeClient.existe()> 0 ) 
			{
				 MessageBoxA(NULL,"le client existe déjà", "CLIENT" ,  MB_ICONERROR | MB_ICONERROR);
			     return;
			}
				 Client client(SAString(p_c_str_cin),SAString(p_c_str_nom),SAString(p_c_str_prenom),SAString(p_c_str_adresse),std::stoi(p_c_str_telephone),*this->con);
			     client.Ajouter("call ajouter_client(:1,:2,:3,:4,:5);");
		         MessageBoxA(NULL,"l'operation a été bien effectué", "CLIENT" , MB_OK | MB_ICONQUESTION);
			     dataGridView1->Rows->Clear();
			     this->fillListClient();
				 this->viderClient();
		 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			 	if(clientNullValues()==1)
			{
			  MessageBoxA(NULL,"Impossible d'insérer la valeur NULL veuillez remplir tous les champs requis", "CLIENT" ,  MB_ICONERROR | MB_ICONERROR);
			  return;
			}

	      // Conversion d'une chaine de caracteres : std::string to const char* en CLR C++

		   msclr::interop::marshal_context context;
          		   
		   std::string std_cin= context.marshal_as<std::string>(id_client->Text);
		   std::string std_nom= context.marshal_as<std::string>(txtnomclient->Text);
		   std::string std_prenom= context.marshal_as<std::string>(txtprenomclient->Text);
		   std::string std_adresse= context.marshal_as<std::string>(txtadresseclient->Text);
		   std::string std_telephone= context.marshal_as<std::string>(txttelephoneclient->Text);

	       const char* p_c_str_cin = std_cin.c_str();
		   const char* p_c_str_nom = std_nom.c_str();
		   const char* p_c_str_prenom = std_prenom.c_str();
		   const char* p_c_str_adresse = std_adresse.c_str();
		   const char* p_c_str_telephone = std_telephone.c_str();

		    Client existeClient(context.marshal_as<std::string>(id_client->Text).c_str(),*this->con);
		    if (existeClient.existe() == 0 ) 
			{
				 MessageBoxA(NULL,"le client n'existe pas pour la modification ( le CIN DU CLIENT EST OBLIGATOIRE)", "CLIENT" ,  MB_ICONERROR | MB_ICONERROR);
			     return;
			}
		    Client client(SAString(p_c_str_cin),SAString(p_c_str_nom),SAString(p_c_str_prenom),SAString(p_c_str_adresse),std::stoi(p_c_str_telephone),*this->con);
			client.Modifier("call modifier_client(:1,:2,:3,:4,:5);");
		    MessageBoxA(NULL,"Modification effectuée", "CLIENT" , MB_OK | MB_ICONQUESTION);
			dataGridView1->Rows->Clear();
			this->fillListClient();
			viderClient();
		 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		    if(this->id_client->Text=="")
			{
			  MessageBoxA(NULL,"CIN : champs requis", "CLIENT" , MB_ICONERROR | MB_ICONERROR);
			  return;
			}

			msclr::interop::marshal_context context;
		    std::string std_cin= context.marshal_as<std::string>(id_client->Text);
	        const char* p_c_str_cin = std_cin.c_str();
		
			Client existeClient(context.marshal_as<std::string>(id_client->Text).c_str(),*this->con);
		    if (existeClient.existe() == 0 ) 
			{
				 MessageBoxA(NULL,"le client n'existe pas pour la suppression ( le CIN DU CLIENT EST OBLIGATOIRE)", "CLIENT" ,  MB_ICONERROR | MB_ICONERROR);
			     return;
			}
		  
		    Client client(SAString(p_c_str_cin),*this->con);
			client.Supprimer("call supprimer_client(:1);");
		    MessageBoxA(NULL,"l'operation a été bien effectué", "CLIENT" , MB_OK | MB_ICONQUESTION);
			dataGridView1->Rows->Clear();
			this->fillListClient();
			viderClient();
		 }
private: System::Void tabControle_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->viderClient();
		 }
private: System::Void ajoutVoiture_Click(System::Object^  sender, System::EventArgs^  e) {
			 //AJOUT VOITURE
			 
			if(voitureNullValues()==1)
			{
			  MessageBoxA(NULL,"Impossible d'insérer la valeur NULL veuillez remplir tous les champs requis", "Voiture" ,  MB_ICONERROR | MB_ICONERROR);
			  return;
			}

	    // Conversion d'une chaine de caracteres : std::string to const char* en CLR C++
		  
		   msclr::interop::marshal_context context;
          		   
		   std::string std_matricule= context.marshal_as<std::string>(txtmatricule->Text);
		   std::string std_modele= context.marshal_as<std::string>(txtmodele->Text);
		   std::string std_marque= context.marshal_as<std::string>(combomarque->Text);
		   
		   std::string   std_nbrStock= context.marshal_as<std::string>(txtnbrstock->Text);
		   std::string   std_tarif= context.marshal_as<std::string>(txttarif->Text);

	       const char* p_c_str_matricule = std_matricule.c_str();
		   const char* p_c_str_modele = std_modele.c_str();
		   const char* p_c_str_marque = std_marque.c_str();
	        

			Voiture existeVoiture(context.marshal_as<std::string>(txtmatricule->Text).c_str(),*this->con);
			MessageBoxA(NULL,to_string(existeVoiture.existe()).c_str(), "Voiture" , MB_OK | MB_ICONQUESTION);
			if (existeVoiture.existe()> 0 ) 
			{
				 MessageBoxA(NULL,"la voiture existe déjà", "VOITURE" ,  MB_ICONERROR | MB_ICONERROR);
			     return;
			}
				 Voiture voiture(SAString(p_c_str_matricule),SAString(p_c_str_modele),SAString(p_c_str_marque),
					 std::stoi(std_nbrStock),
					 std::stof(std_tarif),
					  *this->con);
			     voiture.Ajouter("call ajouter_voiture(:1,:2,:3,:4,:5);");
		         MessageBoxA(NULL,"l'operation a été bien effectué", "VOITURE" , MB_OK | MB_ICONQUESTION);
			     dataGridView2->Rows->Clear();
			     this->fillListVoitures();
				 this->viderChampsVoiture();


		 }
private: System::Void suppVoiture_Click(System::Object^  sender, System::EventArgs^  e) {
			if(this->txtmatricule->Text=="")
			{
			  MessageBoxA(NULL,"Matricule : champs requis pour la suppression", "Voiture" , MB_ICONERROR | MB_ICONERROR);
			  return;
			}

			msclr::interop::marshal_context context;
		    std::string std_matricule= context.marshal_as<std::string>(txtmatricule->Text);
	        const char* p_c_str_matricule = std_matricule.c_str();
		
			Voiture existeVoiture(context.marshal_as<std::string>(txtmatricule->Text).c_str(),*this->con);
		    if (existeVoiture.existe() == 0 ) 
			{
				 MessageBoxA(NULL,"la voiture n'existe pas pour la suppression", "VOITURE" ,  MB_ICONERROR | MB_ICONERROR);
			     return;
			}
		  
		    Voiture voiture(SAString(p_c_str_matricule),*this->con);
			voiture.Supprimer("call supprimer_voiture(:1);");
		    MessageBoxA(NULL,"l'operation a été bien effectué", "VOITURE" , MB_OK | MB_ICONQUESTION);
			dataGridView2->Rows->Clear();
			this->fillListVoitures();
			viderChampsVoiture();
		 }
private: System::Void viderVoiture_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->viderChampsVoiture();
		 }
private: System::Void modVoiture_Click(System::Object^  sender, System::EventArgs^  e) {


			  //AJOUT VOITURE
			 
			if(voitureNullValues()==1)
			{
			  MessageBoxA(NULL,"Impossible d'insérer la valeur NULL veuillez remplir tous les champs requis", "Voiture" ,  MB_ICONERROR | MB_ICONERROR);
			  return;
			}

	    // Conversion d'une chaine de caracteres : std::string to const char* en CLR C++
		  
		   msclr::interop::marshal_context context;
          		   
		   std::string std_matricule= context.marshal_as<std::string>(txtmatricule->Text);
		   std::string std_modele= context.marshal_as<std::string>(txtmodele->Text);
		   std::string std_marque= context.marshal_as<std::string>(combomarque->Text);
		   
		   std::string   std_nbrStock= context.marshal_as<std::string>(txtnbrstock->Text);
		   std::string   std_tarif= context.marshal_as<std::string>(txttarif->Text);

	       const char* p_c_str_matricule = std_matricule.c_str();
		   const char* p_c_str_modele = std_modele.c_str();
		   const char* p_c_str_marque = std_marque.c_str();
	        

			Voiture existeVoiture(context.marshal_as<std::string>(txtmatricule->Text).c_str(),*this->con);
			MessageBoxA(NULL,to_string(existeVoiture.existe()).c_str(), "Voiture" , MB_OK | MB_ICONQUESTION);
			if (existeVoiture.existe()==0 ) 
			{
				 MessageBoxA(NULL,"la voiture n'existe pas existe pour la modification", "VOITURE" ,  MB_ICONERROR | MB_ICONERROR);
			     return;
			}
				 Voiture voiture(SAString(p_c_str_matricule),SAString(p_c_str_modele),SAString(p_c_str_marque),
                     std::stoi(std_nbrStock),
					 std::stof(std_tarif),
					  *this->con);
			     voiture.Modifier("call modifier_voiture(:1,:2,:3,:4,:5);");
		         MessageBoxA(NULL,"l'operation a été bien effectué", "VOITURE" , MB_OK | MB_ICONQUESTION);
			     dataGridView2->Rows->Clear();
			     this->fillListVoitures();
				 this->viderChampsVoiture();

		 }
private: System::Void dataGridView1_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(this->dataGridView1->SelectedRows->Count > 0 ) {
			     int index=this->dataGridView1->SelectedRows[0]->Index;
				 id_client->Text=dataGridView1->Rows[index]->Cells[0]->Value->ToString();
			     txtnomclient->Text=dataGridView1->Rows[index]->Cells[1]->Value->ToString();;
			     txtprenomclient->Text=dataGridView1->Rows[index]->Cells[2]->Value->ToString();;
			     txtadresseclient->Text=dataGridView1->Rows[index]->Cells[3]->Value->ToString();;
			     txttelephoneclient->Text=dataGridView1->Rows[index]->Cells[4]->Value->ToString();;
			 }
			 
		 }
private: System::Void dataGridView2_Click(System::Object^  sender, System::EventArgs^  e) {
			  if(this->dataGridView2->SelectedRows->Count > 0 ) {
			     int index=this->dataGridView2->SelectedRows[0]->Index;
				 txtmatricule->Text=dataGridView2->Rows[index]->Cells[0]->Value->ToString();
			     txtmodele->Text=dataGridView2->Rows[index]->Cells[1]->Value->ToString();
				 combomarque->Text=dataGridView2->Rows[index]->Cells[2]->Value->ToString();
			     txtnbrstock->Text=dataGridView2->Rows[index]->Cells[3]->Value->ToString();
			     txttarif->Text=dataGridView2->Rows[index]->Cells[4]->Value->ToString();
			 }
		 }
private: System::Void lOCATIONToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 locationVoitures::FLocation^ location=gcnew FLocation();
		     location->Show();
		 }
private: System::Void Admin_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		 }
};
}
