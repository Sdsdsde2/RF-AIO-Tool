#pragma once
#include <Windows.h>
#include "Memory.h"
#include "Scanner.h"
#include <fstream>
#include <string.h>
#include <stdio.h>
#define dwBegin 0x400000
#define dwEnd 0xFFFFFFF
namespace Carat {
	// wahts u need? I cant design it if the code isnt in the other, but if it is in the other one it has errors
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary> nope
	/// Summary for MyForm
	/// </summary>
	// same name that why
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected:
	private: System::Windows::Forms::Button^  button2;


	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;


	private: System::Windows::Forms::DateTimePicker^  dateTimePicker1;
	private: System::Windows::Forms::TabControl^  tabControl1;


	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::TabPage^  tabPage4;
	private: System::Windows::Forms::Button^  button15;
	private: System::Windows::Forms::Button^  button16;
	private: System::Windows::Forms::Button^  button13;
	private: System::Windows::Forms::Button^  button14;
	private: System::Windows::Forms::Button^  button12;
	private: System::Windows::Forms::Button^  button11;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button10;
	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::Button^  button17;
	private: System::Windows::Forms::Button^  button18;
	private: System::Windows::Forms::Button^  button23;
	private: System::Windows::Forms::Button^  button24;
	private: System::Windows::Forms::Button^  button21;
	private: System::Windows::Forms::Button^  button22;
	private: System::Windows::Forms::Button^  button19;
	private: System::Windows::Forms::Button^  button20;
	private: System::Windows::Forms::Button^  button29;
	private: System::Windows::Forms::Button^  button30;
	private: System::Windows::Forms::Button^  button27;
	private: System::Windows::Forms::Button^  button28;
	private: System::Windows::Forms::Button^  button25;
	private: System::Windows::Forms::Button^  button26;
	private: System::Windows::Forms::Button^  button31;
	private: System::Windows::Forms::Button^  button32;
	private: System::Windows::Forms::Button^  button36;
	private: System::Windows::Forms::Button^  button35;
	private: System::Windows::Forms::Button^  button34;
	private: System::Windows::Forms::Button^  button33;
	internal: System::Windows::Forms::Panel^  Panel2;
	private:
	internal: System::Windows::Forms::Label^  Label6;
	internal: System::Windows::Forms::Label^  Label2;
	internal: System::Windows::Forms::Label^  Label1;
	internal: System::Windows::Forms::Panel^  Panel1;







	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->button23 = (gcnew System::Windows::Forms::Button());
			this->button24 = (gcnew System::Windows::Forms::Button());
			this->button21 = (gcnew System::Windows::Forms::Button());
			this->button22 = (gcnew System::Windows::Forms::Button());
			this->button19 = (gcnew System::Windows::Forms::Button());
			this->button20 = (gcnew System::Windows::Forms::Button());
			this->button17 = (gcnew System::Windows::Forms::Button());
			this->button18 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->button29 = (gcnew System::Windows::Forms::Button());
			this->button30 = (gcnew System::Windows::Forms::Button());
			this->button27 = (gcnew System::Windows::Forms::Button());
			this->button28 = (gcnew System::Windows::Forms::Button());
			this->button25 = (gcnew System::Windows::Forms::Button());
			this->button26 = (gcnew System::Windows::Forms::Button());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->button16 = (gcnew System::Windows::Forms::Button());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->button31 = (gcnew System::Windows::Forms::Button());
			this->button32 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->button36 = (gcnew System::Windows::Forms::Button());
			this->button35 = (gcnew System::Windows::Forms::Button());
			this->button34 = (gcnew System::Windows::Forms::Button());
			this->button33 = (gcnew System::Windows::Forms::Button());
			this->Panel2 = (gcnew System::Windows::Forms::Panel());
			this->Label6 = (gcnew System::Windows::Forms::Label());
			this->Label2 = (gcnew System::Windows::Forms::Label());
			this->Label1 = (gcnew System::Windows::Forms::Label());
			this->Panel1 = (gcnew System::Windows::Forms::Panel());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->tabPage3->SuspendLayout();
			this->tabPage4->SuspendLayout();
			this->Panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Location = System::Drawing::Point(6, 6);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(104, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Mix Hack";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Location = System::Drawing::Point(6, 6);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(104, 23);
			this->button2->TabIndex = 0;
			this->button2->Text = L"Disable";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Location = System::Drawing::Point(412, 191);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(200, 20);
			this->dateTimePicker1->TabIndex = 6;
			this->dateTimePicker1->Visible = false;
			this->dateTimePicker1->ValueChanged += gcnew System::EventHandler(this, &MyForm::dateTimePicker1_ValueChanged);
			// 
			// tabControl1
			// 
			this->tabControl1->Appearance = System::Windows::Forms::TabAppearance::Buttons;
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Controls->Add(this->tabPage4);
			this->tabControl1->Cursor = System::Windows::Forms::Cursors::Default;
			this->tabControl1->Font = (gcnew System::Drawing::Font(L"Consolas", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tabControl1->Location = System::Drawing::Point(12, 44);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(402, 214);
			this->tabControl1->SizeMode = System::Windows::Forms::TabSizeMode::Fixed;
			this->tabControl1->TabIndex = 7;
			// 
			// tabPage1
			// 
			this->tabPage1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(24)),
				static_cast<System::Int32>(static_cast<System::Byte>(24)));
			this->tabPage1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->tabPage1->Controls->Add(this->button23);
			this->tabPage1->Controls->Add(this->button24);
			this->tabPage1->Controls->Add(this->button21);
			this->tabPage1->Controls->Add(this->button22);
			this->tabPage1->Controls->Add(this->button19);
			this->tabPage1->Controls->Add(this->button20);
			this->tabPage1->Controls->Add(this->button17);
			this->tabPage1->Controls->Add(this->button18);
			this->tabPage1->Controls->Add(this->button1);
			this->tabPage1->Controls->Add(this->button2);
			this->tabPage1->Controls->Add(this->button7);
			this->tabPage1->Controls->Add(this->button5);
			this->tabPage1->Controls->Add(this->button8);
			this->tabPage1->Controls->Add(this->button4);
			this->tabPage1->Controls->Add(this->button6);
			this->tabPage1->Controls->Add(this->button3);
			this->tabPage1->ForeColor = System::Drawing::Color::Red;
			this->tabPage1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->tabPage1->Location = System::Drawing::Point(4, 27);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(394, 183);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Account";
			this->tabPage1->UseVisualStyleBackColor = true;
			this->tabPage1->Click += gcnew System::EventHandler(this, &MyForm::tabPage1_Click);
			// 
			// button23
			// 
			this->button23->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button23->Location = System::Drawing::Point(116, 64);
			this->button23->Name = L"button23";
			this->button23->Size = System::Drawing::Size(104, 23);
			this->button23->TabIndex = 13;
			this->button23->Text = L"Rebirth Any Level";
			this->button23->UseVisualStyleBackColor = true;
			// 
			// button24
			// 
			this->button24->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button24->Location = System::Drawing::Point(116, 64);
			this->button24->Name = L"button24";
			this->button24->Size = System::Drawing::Size(104, 23);
			this->button24->TabIndex = 12;
			this->button24->Text = L"Disable";
			this->button24->UseVisualStyleBackColor = true;
			// 
			// button21
			// 
			this->button21->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button21->Location = System::Drawing::Point(116, 93);
			this->button21->Name = L"button21";
			this->button21->Size = System::Drawing::Size(104, 23);
			this->button21->TabIndex = 11;
			this->button21->Text = L"Name Bypass";
			this->button21->UseVisualStyleBackColor = true;
			// 
			// button22
			// 
			this->button22->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button22->Location = System::Drawing::Point(116, 93);
			this->button22->Name = L"button22";
			this->button22->Size = System::Drawing::Size(104, 23);
			this->button22->TabIndex = 10;
			this->button22->Text = L"Disable";
			this->button22->UseVisualStyleBackColor = true;
			// 
			// button19
			// 
			this->button19->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button19->Location = System::Drawing::Point(116, 35);
			this->button19->Name = L"button19";
			this->button19->Size = System::Drawing::Size(104, 23);
			this->button19->TabIndex = 9;
			this->button19->Text = L"Rebirth";
			this->button19->UseVisualStyleBackColor = true;
			this->button19->Click += gcnew System::EventHandler(this, &MyForm::button19_Click);
			// 
			// button20
			// 
			this->button20->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button20->Location = System::Drawing::Point(116, 35);
			this->button20->Name = L"button20";
			this->button20->Size = System::Drawing::Size(104, 23);
			this->button20->TabIndex = 8;
			this->button20->Text = L"Disable";
			this->button20->UseVisualStyleBackColor = true;
			// 
			// button17
			// 
			this->button17->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button17->Location = System::Drawing::Point(116, 6);
			this->button17->Name = L"button17";
			this->button17->Size = System::Drawing::Size(104, 23);
			this->button17->TabIndex = 7;
			this->button17->Text = L"Suicide Jump";
			this->button17->UseVisualStyleBackColor = true;
			this->button17->Click += gcnew System::EventHandler(this, &MyForm::button17_Click);
			// 
			// button18
			// 
			this->button18->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button18->Location = System::Drawing::Point(116, 6);
			this->button18->Name = L"button18";
			this->button18->Size = System::Drawing::Size(104, 23);
			this->button18->TabIndex = 6;
			this->button18->Text = L"Disable";
			this->button18->UseVisualStyleBackColor = true;
			this->button18->Click += gcnew System::EventHandler(this, &MyForm::button18_Click);
			// 
			// button7
			// 
			this->button7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button7->Location = System::Drawing::Point(6, 93);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(104, 23);
			this->button7->TabIndex = 5;
			this->button7->Text = L"Bonus";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// button5
			// 
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button5->Location = System::Drawing::Point(6, 64);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(104, 23);
			this->button5->TabIndex = 3;
			this->button5->Text = L"Exp";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button8
			// 
			this->button8->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button8->Location = System::Drawing::Point(6, 93);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(104, 23);
			this->button8->TabIndex = 4;
			this->button8->Text = L"Disable";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// button4
			// 
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->Location = System::Drawing::Point(6, 35);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(104, 23);
			this->button4->TabIndex = 1;
			this->button4->Text = L"Carat";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button6
			// 
			this->button6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button6->Location = System::Drawing::Point(6, 64);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(104, 23);
			this->button6->TabIndex = 2;
			this->button6->Text = L"Disable";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// button3
			// 
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Location = System::Drawing::Point(6, 35);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(104, 23);
			this->button3->TabIndex = 0;
			this->button3->Text = L"Disable";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// tabPage2
			// 
			this->tabPage2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(24)),
				static_cast<System::Int32>(static_cast<System::Byte>(24)));
			this->tabPage2->Controls->Add(this->button29);
			this->tabPage2->Controls->Add(this->button30);
			this->tabPage2->Controls->Add(this->button27);
			this->tabPage2->Controls->Add(this->button28);
			this->tabPage2->Controls->Add(this->button25);
			this->tabPage2->Controls->Add(this->button26);
			this->tabPage2->Controls->Add(this->button15);
			this->tabPage2->Controls->Add(this->button16);
			this->tabPage2->Controls->Add(this->button13);
			this->tabPage2->Controls->Add(this->button14);
			this->tabPage2->Controls->Add(this->button12);
			this->tabPage2->Controls->Add(this->button11);
			this->tabPage2->ForeColor = System::Drawing::Color::Red;
			this->tabPage2->ImeMode = System::Windows::Forms::ImeMode::Hiragana;
			this->tabPage2->Location = System::Drawing::Point(4, 27);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(394, 183);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"In Game";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// button29
			// 
			this->button29->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button29->Location = System::Drawing::Point(6, 151);
			this->button29->Name = L"button29";
			this->button29->Size = System::Drawing::Size(100, 23);
			this->button29->TabIndex = 17;
			this->button29->Text = L"Exo Whenever";
			this->button29->UseVisualStyleBackColor = true;
			// 
			// button30
			// 
			this->button30->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button30->Location = System::Drawing::Point(6, 151);
			this->button30->Name = L"button30";
			this->button30->Size = System::Drawing::Size(100, 23);
			this->button30->TabIndex = 16;
			this->button30->Text = L"Disable";
			this->button30->UseVisualStyleBackColor = true;
			// 
			// button27
			// 
			this->button27->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button27->Location = System::Drawing::Point(6, 122);
			this->button27->Name = L"button27";
			this->button27->Size = System::Drawing::Size(100, 23);
			this->button27->TabIndex = 15;
			this->button27->Text = L"Auto Jump";
			this->button27->UseVisualStyleBackColor = true;
			// 
			// button28
			// 
			this->button28->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button28->Location = System::Drawing::Point(6, 122);
			this->button28->Name = L"button28";
			this->button28->Size = System::Drawing::Size(100, 23);
			this->button28->TabIndex = 14;
			this->button28->Text = L"Disable";
			this->button28->UseVisualStyleBackColor = true;
			// 
			// button25
			// 
			this->button25->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button25->Location = System::Drawing::Point(6, 93);
			this->button25->Name = L"button25";
			this->button25->Size = System::Drawing::Size(100, 23);
			this->button25->TabIndex = 13;
			this->button25->Text = L"Unlimited Jump";
			this->button25->UseVisualStyleBackColor = true;
			// 
			// button26
			// 
			this->button26->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button26->Location = System::Drawing::Point(6, 93);
			this->button26->Name = L"button26";
			this->button26->Size = System::Drawing::Size(100, 23);
			this->button26->TabIndex = 12;
			this->button26->Text = L"Disable";
			this->button26->UseVisualStyleBackColor = true;
			// 
			// button15
			// 
			this->button15->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button15->Location = System::Drawing::Point(6, 64);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(100, 23);
			this->button15->TabIndex = 11;
			this->button15->Text = L"Far Jump";
			this->button15->UseVisualStyleBackColor = true;
			this->button15->Click += gcnew System::EventHandler(this, &MyForm::button15_Click);
			// 
			// button16
			// 
			this->button16->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button16->Location = System::Drawing::Point(6, 64);
			this->button16->Name = L"button16";
			this->button16->Size = System::Drawing::Size(100, 23);
			this->button16->TabIndex = 10;
			this->button16->Text = L"Disable";
			this->button16->UseVisualStyleBackColor = true;
			this->button16->Click += gcnew System::EventHandler(this, &MyForm::button16_Click);
			// 
			// button13
			// 
			this->button13->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button13->Location = System::Drawing::Point(6, 35);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(100, 23);
			this->button13->TabIndex = 9;
			this->button13->Text = L"Fast Walk";
			this->button13->UseVisualStyleBackColor = true;
			this->button13->Click += gcnew System::EventHandler(this, &MyForm::button13_Click);
			// 
			// button14
			// 
			this->button14->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button14->Location = System::Drawing::Point(6, 35);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(100, 23);
			this->button14->TabIndex = 8;
			this->button14->Text = L"Disable";
			this->button14->UseVisualStyleBackColor = true;
			this->button14->Click += gcnew System::EventHandler(this, &MyForm::button14_Click);
			// 
			// button12
			// 
			this->button12->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button12->Location = System::Drawing::Point(6, 6);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(100, 23);
			this->button12->TabIndex = 7;
			this->button12->Text = L"Fast Run";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &MyForm::button12_Click);
			// 
			// button11
			// 
			this->button11->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button11->Location = System::Drawing::Point(6, 6);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(100, 23);
			this->button11->TabIndex = 6;
			this->button11->Text = L"Disable";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &MyForm::button11_Click);
			// 
			// tabPage3
			// 
			this->tabPage3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(24)),
				static_cast<System::Int32>(static_cast<System::Byte>(24)));
			this->tabPage3->Controls->Add(this->button31);
			this->tabPage3->Controls->Add(this->button32);
			this->tabPage3->Controls->Add(this->button10);
			this->tabPage3->Controls->Add(this->button9);
			this->tabPage3->ForeColor = System::Drawing::Color::Red;
			this->tabPage3->ImeMode = System::Windows::Forms::ImeMode::Hiragana;
			this->tabPage3->Location = System::Drawing::Point(4, 27);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Size = System::Drawing::Size(394, 183);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Misc";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// button31
			// 
			this->button31->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button31->Location = System::Drawing::Point(6, 35);
			this->button31->Name = L"button31";
			this->button31->Size = System::Drawing::Size(93, 23);
			this->button31->TabIndex = 3;
			this->button31->Text = L"Account Break";
			this->button31->UseVisualStyleBackColor = true;
			// 
			// button32
			// 
			this->button32->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button32->Location = System::Drawing::Point(6, 35);
			this->button32->Name = L"button32";
			this->button32->Size = System::Drawing::Size(93, 23);
			this->button32->TabIndex = 2;
			this->button32->Text = L"Disable";
			this->button32->UseVisualStyleBackColor = true;
			// 
			// button10
			// 
			this->button10->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button10->Location = System::Drawing::Point(6, 6);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(93, 23);
			this->button10->TabIndex = 1;
			this->button10->Text = L"Room Crash";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &MyForm::button10_Click);
			// 
			// button9
			// 
			this->button9->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button9->Location = System::Drawing::Point(6, 6);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(93, 23);
			this->button9->TabIndex = 0;
			this->button9->Text = L"Disable";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm::button9_Click);
			// 
			// tabPage4
			// 
			this->tabPage4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(24)),
				static_cast<System::Int32>(static_cast<System::Byte>(24)));
			this->tabPage4->Controls->Add(this->button36);
			this->tabPage4->Controls->Add(this->button35);
			this->tabPage4->Controls->Add(this->button34);
			this->tabPage4->Controls->Add(this->button33);
			this->tabPage4->ForeColor = System::Drawing::Color::Red;
			this->tabPage4->ImeMode = System::Windows::Forms::ImeMode::Hiragana;
			this->tabPage4->Location = System::Drawing::Point(4, 27);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Size = System::Drawing::Size(394, 183);
			this->tabPage4->TabIndex = 3;
			this->tabPage4->Text = L"Info";
			this->tabPage4->UseVisualStyleBackColor = true;
			// 
			// button36
			// 
			this->button36->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button36->Location = System::Drawing::Point(9, 93);
			this->button36->Name = L"button36";
			this->button36->Size = System::Drawing::Size(108, 23);
			this->button36->TabIndex = 3;
			this->button36->Text = L"Misc Tab";
			this->button36->UseVisualStyleBackColor = true;
			// 
			// button35
			// 
			this->button35->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button35->Location = System::Drawing::Point(9, 64);
			this->button35->Name = L"button35";
			this->button35->Size = System::Drawing::Size(108, 23);
			this->button35->TabIndex = 2;
			this->button35->Text = L"In-Game Tab";
			this->button35->UseVisualStyleBackColor = true;
			// 
			// button34
			// 
			this->button34->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button34->Location = System::Drawing::Point(9, 6);
			this->button34->Name = L"button34";
			this->button34->Size = System::Drawing::Size(108, 23);
			this->button34->TabIndex = 1;
			this->button34->Text = L"Contact Creater";
			this->button34->UseVisualStyleBackColor = true;
			// 
			// button33
			// 
			this->button33->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button33->Location = System::Drawing::Point(9, 35);
			this->button33->Name = L"button33";
			this->button33->Size = System::Drawing::Size(108, 23);
			this->button33->TabIndex = 0;
			this->button33->Text = L"Account Tab";
			this->button33->UseVisualStyleBackColor = true;
			// 
			// Panel2
			// 
			this->Panel2->BackColor = System::Drawing::Color::Black;
			this->Panel2->Controls->Add(this->Label6);
			this->Panel2->Controls->Add(this->Label2);
			this->Panel2->Controls->Add(this->Label1);
			this->Panel2->Location = System::Drawing::Point(0, 0);
			this->Panel2->Name = L"Panel2";
			this->Panel2->Size = System::Drawing::Size(458, 22);
			this->Panel2->TabIndex = 8;
			// 
			// Label6
			// 
			this->Label6->AutoSize = true;
			this->Label6->BackColor = System::Drawing::Color::Black;
			this->Label6->Font = (gcnew System::Drawing::Font(L"Consolas", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Label6->ForeColor = System::Drawing::Color::Red;
			this->Label6->Location = System::Drawing::Point(408, 2);
			this->Label6->Name = L"Label6";
			this->Label6->Size = System::Drawing::Size(14, 15);
			this->Label6->TabIndex = 2;
			this->Label6->Text = L"X";
			// 
			// Label2
			// 
			this->Label2->AutoSize = true;
			this->Label2->BackColor = System::Drawing::Color::Black;
			this->Label2->Font = (gcnew System::Drawing::Font(L"Consolas", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Label2->ForeColor = System::Drawing::Color::White;
			this->Label2->Location = System::Drawing::Point(149, 4);
			this->Label2->Name = L"Label2";
			this->Label2->Size = System::Drawing::Size(147, 14);
			this->Label2->TabIndex = 1;
			this->Label2->Text = L"Made By M0nster#1337";
			// 
			// Label1
			// 
			this->Label1->AutoSize = true;
			this->Label1->BackColor = System::Drawing::Color::Black;
			this->Label1->Font = (gcnew System::Drawing::Font(L"Consolas", 11.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Label1->ForeColor = System::Drawing::Color::White;
			this->Label1->Location = System::Drawing::Point(1, 2);
			this->Label1->Name = L"Label1";
			this->Label1->Size = System::Drawing::Size(112, 18);
			this->Label1->TabIndex = 0;
			this->Label1->Text = L"RF Multi-Hack";
			// 
			// Panel1
			// 
			this->Panel1->BackColor = System::Drawing::Color::DarkRed;
			this->Panel1->Location = System::Drawing::Point(0, 22);
			this->Panel1->Name = L"Panel1";
			this->Panel1->Size = System::Drawing::Size(460, 16);
			this->Panel1->TabIndex = 9;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(24)),
				static_cast<System::Int32>(static_cast<System::Byte>(24)));
			this->ClientSize = System::Drawing::Size(427, 272);
			this->Controls->Add(this->Panel1);
			this->Controls->Add(this->Panel2);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->dateTimePicker1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MyForm";
			this->ShowIcon = false;
			this->Text = L"RF Multihack By M0nster#3769";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage2->ResumeLayout(false);
			this->tabPage3->ResumeLayout(false);
			this->tabPage4->ResumeLayout(false);
			this->Panel2->ResumeLayout(false);
			this->Panel2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
		static Memory *mem = new Memory();
		static Scanner *scan = new Scanner();
		//private: DWORD caratAddy;
		//private: DWORD Jump_Sui_1;
		//private: DWORD Jump_Sui_2;
		//private: DWORD Jump_1;

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		//mem->WriteMemory((VOID*)(0x6046DF), (PBYTE) "\x75", 1);
		//mem->WriteMemory((VOID*)(0x530DBE), (PBYTE) "\x58\x02\x00\x00\x8B\x93\xAC", 7);
		//*(INT64*)0x530DBE = 10016005581342262983;
		//mem->WriteMemory((VOID*)(Jump_1), (PBYTE) "\x00\x00\xA0\x40", 4);
		//mem->WriteMemory((VOID*)(Jump_Sui_1), (PBYTE) "\x3D", 1);
		//mem->WriteMemory((VOID*)(Jump_Sui_2), (PBYTE) "\x3D", 1);			
		//button2->BringToFront();
	}

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		//mem->WriteMemory((VOID*)(0x6046DF), (PBYTE) "\x74", 1);
		//button2->SendToBack();
	}
	private: System::Void linkLabel1_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e) {
		//ShellExecute(0, 0, "http://google.com", 0, 0, SW_SHOW);
	}
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {

		/* if (dateTimePicker1->Value > DateTime(2019, 1, 15))
		{
			*(INT8*)GetModuleHandle("rumblefighter.exe") = 0;

		}
		backgroundWorker1->RunWorkerAsync(); 
		Sleep(1000); */
		//mem->WriteMemory((VOID*)(Jump_1), (PBYTE) "\x00\x00\x80\xBF", 4);
		//mem->WriteMemory((VOID*)(Jump_Sui_1), (PBYTE) "\xFF", 1);
		//->WriteMemory((VOID*)(Jump_Sui_2), (PBYTE) "\xFF", 1);
	}
	private: System::Void backgroundWorker1_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
		//if (dateTimePicker1->Value > DateTime(2017, 7, 20))
		//{
		//	*(INT8*)GetModuleHandle("rumblefighter.exe") = 0;
		//}
		//caratAddy = scan->findPattern(dwBegin, dwEnd, (PBYTE) "\x89\x46\x23\x66\x89\x46\x27", "xxxxxxx");
		//Jump_1 = scan->findPattern(dwBegin, dwEnd, (PBYTE) "\00\x00\xA0\x40\x0A\xD7", "xxxxxx");
		//Jump_Sui_1 = Jump_1 + 0x7;
		//Jump_Sui_2 = Jump_1 + 0xF;
	}
	private: System::Void linkLabel2_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e) {
		//ShellExecute(0, 0, "http://google.com", 0, 0, SW_SHOW);
	}
	private: System::Void dateTimePicker1_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
		// Carat On
		//mem->WriteMemory((VOID*)(0x532E0E), (PBYTE) "\x58\x02\x00\x00\x8B\x93\xAC", 7);
		//*(INT64*)0x532E0E = 10016005581342262983;
		//button4->SendToBack();
	}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	// Carat Off
	//mem->WriteMemory((VOID*)(0x532E0E), (PBYTE) "\x89\x46\x23\x66\x89\x46\x27", 7);
	//*(INT64*)0x532E0E = 10027060651301750409;
	//button3->SendToBack();
}
private: System::Void button10_Click(System::Object^  sender, System::EventArgs^  e) {
	// Crash On
	//mem->WriteMemory((VOID*)(0x4887E4), (PBYTE) "\x88\x47\x03\xC6\x47\x13\x00\xBA", 8);
	//button10->SendToBack();
}
private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {
	// Crash Off
	//mem->WriteMemory((VOID*)(0x4887E4), (PBYTE) "\x88\x47\x07\xC6\x47\x17\x00\xBA", 8);
	//button9->SendToBack();
}
private: System::Void button12_Click(System::Object^  sender, System::EventArgs^  e) {
	// Fast Run On
	//mem->WriteMemory((VOID*)(0x7C463F), (PBYTE) "\x40\x8F\xC2\x75\x3C\xCD", 6);
	//button12->SendToBack();
}
private: System::Void button11_Click(System::Object^  sender, System::EventArgs^  e) {
	// Fast Run Off
	//mem->WriteMemory((VOID*)(0x7C463F), (PBYTE) "\x3F\x8F\xC2\x75\x3C\xCD", 6);
	//button11->SendToBack();
}
private: System::Void button13_Click(System::Object^  sender, System::EventArgs^  e) {
	// Fast Run On
	
}
private: System::Void button14_Click(System::Object^  sender, System::EventArgs^  e) {
	// Fast Run On
	
}
private: System::Void button15_Click(System::Object^  sender, System::EventArgs^  e) {
	//Far Jump On
	//mem->WriteMemory((VOID*)(0x7C464F), (PBYTE) "\x40\xD4\x8E\x73\x00", 5);
	//button15->SendToBack();
}
private: System::Void button16_Click(System::Object^  sender, System::EventArgs^  e) {
	//Far Jump Off
	//mem->WriteMemory((VOID*)(0x7C464F), (PBYTE) "\x3F\xD4\x8E\x73\x00", 5);
	//button16->SendToBack();
}
private: System::Void button17_Click(System::Object^  sender, System::EventArgs^  e) {
	//Suicide Jump On
	//mem->WriteMemory((VOID*)(0x7C9633), (PBYTE) "\xCC\x00\x00\x80\x40\x33", 6);
	//button17->SendToBack();
}
private: System::Void button18_Click(System::Object^  sender, System::EventArgs^  e) {
	//Suicide Jump Off
	//mem->WriteMemory((VOID*)(0x7C9633), (PBYTE) "\x40\x00\x00\x20\x40\x33", 6);
	//button18->SendToBack();
}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
	//Exp On
	mem->WriteMemory((VOID*)(0x532E0E), (PBYTE) "\xC7\x46\x38\x00\x20\x00\x00", 7);
	button5->SendToBack();
}
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
	//Exp Off
	mem->WriteMemory((VOID*)(0x532E0E), (PBYTE) "\x89\x46\x23\x66\x89\x46\x27", 7);
	button6->SendToBack();
}
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
	// Bonus Hack On
	mem->WriteMemory((VOID*)(0x532E0E), (PBYTE) "\x89\x46\x2A\x66\x89\x46\x27", 7);
	button7->SendToBack();
}
private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
	// Bonus Hack Off
	mem->WriteMemory((VOID*)(0x532E0E), (PBYTE) "\x89\x46\x23\x66\x89\x46\x27", 7);
	button8->SendToBack();
}
private: System::Void tabPage1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button19_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}