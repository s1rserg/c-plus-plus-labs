#pragma once
#include <cmath>
#include "Function.h"
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace DataVisualization::Charting;
	using namespace System::Windows::Forms;

	public ref class Form1 : public Form
	{
	public:
		Form1(void)
		{
			f = new Function;
			x = new vector<double>;
			y = new vector<double>;
			InitializeComponent();
		}

	protected:
		~Form1()
		{
			if (components)
			{
				delete components;
			}
			delete f;
		}

	private:
		System::Windows::Forms::TextBox^ textBoxX1;
		System::Windows::Forms::TextBox^ textBoxX2;
		System::Windows::Forms::Label^ labelX1;
		System::Windows::Forms::Label^ labelX2;
		System::Windows::Forms::Label^ labelStep;
		System::Windows::Forms::TextBox^ textBoxStep;
		System::Windows::Forms::Label^ functionLabel;

		System::Windows::Forms::Button^ buttonCalc;
		System::Windows::Forms::Label^ labelSolution;
	private: System::Windows::Forms::TextBox^ solutionTB;

		DataVisualization::Charting::Chart^ chart1;
		System::Windows::Forms::Label^ graphLabel;

		System::ComponentModel::Container^ components;

		Function* f;
		vector<double>* x;
		vector<double>* y;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBoxX1 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxX2 = (gcnew System::Windows::Forms::TextBox());
			this->labelX1 = (gcnew System::Windows::Forms::Label());
			this->labelX2 = (gcnew System::Windows::Forms::Label());
			this->labelStep = (gcnew System::Windows::Forms::Label());
			this->textBoxStep = (gcnew System::Windows::Forms::TextBox());
			this->functionLabel = (gcnew System::Windows::Forms::Label());
			this->buttonCalc = (gcnew System::Windows::Forms::Button());
			this->labelSolution = (gcnew System::Windows::Forms::Label());
			this->solutionTB = (gcnew System::Windows::Forms::TextBox());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->graphLabel = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// textBoxX1
			// 
			this->textBoxX1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->textBoxX1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxX1->Location = System::Drawing::Point(155, 127);
			this->textBoxX1->Name = L"textBoxX1";
			this->textBoxX1->Size = System::Drawing::Size(100, 32);
			this->textBoxX1->TabIndex = 1;
			// 
			// textBoxX2
			// 
			this->textBoxX2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->textBoxX2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxX2->Location = System::Drawing::Point(155, 204);
			this->textBoxX2->Name = L"textBoxX2";
			this->textBoxX2->Size = System::Drawing::Size(100, 32);
			this->textBoxX2->TabIndex = 2;
			// 
			// labelX1
			// 
			this->labelX1->AutoSize = true;
			this->labelX1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelX1->Location = System::Drawing::Point(24, 130);
			this->labelX1->Name = L"labelX1";
			this->labelX1->Size = System::Drawing::Size(105, 23);
			this->labelX1->TabIndex = 4;
			this->labelX1->Text = L"Ввести x1:";
			// 
			// labelX2
			// 
			this->labelX2->AutoSize = true;
			this->labelX2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelX2->Location = System::Drawing::Point(24, 207);
			this->labelX2->Name = L"labelX2";
			this->labelX2->Size = System::Drawing::Size(105, 23);
			this->labelX2->TabIndex = 5;
			this->labelX2->Text = L"Ввести x2:";
			// 
			// labelStep
			// 
			this->labelStep->AutoSize = true;
			this->labelStep->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelStep->Location = System::Drawing::Point(24, 285);
			this->labelStep->Name = L"labelStep";
			this->labelStep->Size = System::Drawing::Size(125, 23);
			this->labelStep->TabIndex = 6;
			this->labelStep->Text = L"Ввести крок:";
			// 
			// textBoxStep
			// 
			this->textBoxStep->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->textBoxStep->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxStep->Location = System::Drawing::Point(155, 282);
			this->textBoxStep->Name = L"textBoxStep";
			this->textBoxStep->Size = System::Drawing::Size(100, 32);
			this->textBoxStep->TabIndex = 7;
			// 
			// functionLabel
			// 
			this->functionLabel->AutoSize = true;
			this->functionLabel->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->functionLabel->Location = System::Drawing::Point(24, 34);
			this->functionLabel->Name = L"functionLabel";
			this->functionLabel->Size = System::Drawing::Size(274, 23);
			this->functionLabel->TabIndex = 8;
			this->functionLabel->Text = L"y(x) = abs((abs((x-2)+1))/(x-2))";
			// 
			// buttonCalc
			// 
			this->buttonCalc->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->buttonCalc->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonCalc->Location = System::Drawing::Point(57, 363);
			this->buttonCalc->Name = L"buttonCalc";
			this->buttonCalc->Size = System::Drawing::Size(129, 49);
			this->buttonCalc->TabIndex = 9;
			this->buttonCalc->Text = L"Обрахувати";
			this->buttonCalc->UseVisualStyleBackColor = false;
			this->buttonCalc->Click += gcnew System::EventHandler(this, &Form1::buttonCalc_Click);
			// 
			// labelSolution
			// 
			this->labelSolution->AutoSize = true;
			this->labelSolution->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelSolution->Location = System::Drawing::Point(271, 86);
			this->labelSolution->Name = L"labelSolution";
			this->labelSolution->Size = System::Drawing::Size(85, 23);
			this->labelSolution->TabIndex = 11;
			this->labelSolution->Text = L"Рішення";
			// 
			// solutionTB
			// 
			this->solutionTB->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->solutionTB->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->solutionTB->Location = System::Drawing::Point(275, 112);
			this->solutionTB->MaximumSize = System::Drawing::Size(400, 300);
			this->solutionTB->MinimumSize = System::Drawing::Size(400, 300);
			this->solutionTB->Multiline = true;
			this->solutionTB->Name = L"solutionTB";
			this->solutionTB->ReadOnly = true;
			this->solutionTB->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->solutionTB->Size = System::Drawing::Size(400, 300);
			this->solutionTB->TabIndex = 13;
			// 
			// chart1
			// 
			this->chart1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->chart1->Location = System::Drawing::Point(705, 112);
			this->chart1->Name = L"chart1";
			this->chart1->Size = System::Drawing::Size(458, 300);
			this->chart1->TabIndex = 14;
			// 
			// graphLabel
			// 
			this->graphLabel->AutoSize = true;
			this->graphLabel->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->graphLabel->Location = System::Drawing::Point(701, 86);
			this->graphLabel->Name = L"graphLabel";
			this->graphLabel->Size = System::Drawing::Size(266, 23);
			this->graphLabel->TabIndex = 15;
			this->graphLabel->Text = L"Графік (по точкам у рішенні)";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->ClientSize = System::Drawing::Size(1197, 471);
			this->Controls->Add(this->graphLabel);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->solutionTB);
			this->Controls->Add(this->labelSolution);
			this->Controls->Add(this->buttonCalc);
			this->Controls->Add(this->functionLabel);
			this->Controls->Add(this->textBoxStep);
			this->Controls->Add(this->labelStep);
			this->Controls->Add(this->labelX2);
			this->Controls->Add(this->labelX1);
			this->Controls->Add(this->textBoxX2);
			this->Controls->Add(this->textBoxX1);
			this->Name = L"Form1";
			this->Text = L"Function Calculator";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		bool scanInfo();
		Void buttonCalc_Click(System::Object^ sender, System::EventArgs^ e);
		Void chart1_Paint();
};
}
