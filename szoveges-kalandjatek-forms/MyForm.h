#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include "ReadStory.h"

namespace $safeprojectname$ {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/// <summary>
	/// Summary for MyForm
	/// </summary>
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

	private: System::Windows::Forms::Label^ storyLabel;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;

	protected:

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
			this->storyLabel = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// storyLabel
			// 
			this->storyLabel->AutoSize = true;
			this->storyLabel->Location = System::Drawing::Point(56, 67);
			this->storyLabel->MaximumSize = System::Drawing::Size(650, 0);
			this->storyLabel->Name = L"storyLabel";
			this->storyLabel->Size = System::Drawing::Size(606, 32);
			this->storyLabel->TabIndex = 1;
			this->storyLabel->Text = L"Itt lesz a sztori leírása. Megpróbálok minél hosszabb szöveget írni, hogy megláss"
				L"uk, jó-e a többsoros változathoz ez a tool!";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(105, 379);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(319, 379);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 3;
			this->button2->Text = L"button2";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(531, 379);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 4;
			this->button3->Text = L"button3";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(782, 453);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->storyLabel);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(800, 500);
			this->MinimumSize = System::Drawing::Size(800, 500);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: 
		System::String^ btn1Action, ^ btn2Action, ^ btn3Action;

		System::String^ modifyText(System::String^ action, int btnId) {

		nextStory^ text = gcnew nextStory("_start.game");

		storyLabel->Text = text->baseText;
		button1->Text = text->btn1Text;
		button2->Text = text->btn2Text;
		button3->Text = text->btn3Text;

		switch (btnId)
		{
		case 1:
			return text->btn1Action;
			break;
		case 2:
			return text->btn2Action;
			break;
		case 3:
			return text->btn3Action;
			break;
		default:
			return L"_start";
			break;
		}
	}

#pragma region onClicks
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		modifyText(btn1Action, 1);
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		modifyText(btn2Action, 2);
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		modifyText(btn3Action, 3);
	}
#pragma endregion


};
}
