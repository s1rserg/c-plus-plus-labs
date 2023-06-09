#include "pch.h"
#include "Form1.h"

using namespace CppCLRWinFormsProject;

bool Form1::scanInfo() {
	textBoxX1->BackColor = Color::White;
	textBoxX2->BackColor = Color::White;
	textBoxStep->BackColor = Color::White;
	solutionTB->Text = "";

	try {
		f->setX1(Convert::ToDouble(textBoxX1->Text));
	}
	catch (const FormatException^) {
		solutionTB->Text += "Некоректні символи в x1\r\n";
		textBoxX1->BackColor = Color::Red;
		return false;
	}

	try {
		f->setX2(Convert::ToDouble(textBoxX2->Text));
	}
	catch (const FormatException^) {
		solutionTB->Text += "Некоректні символи в x2\r\n";
		textBoxX2->BackColor = Color::Red;
		return false;
	}

	try {
		f->setStep(Convert::ToDouble(textBoxStep->Text));
	}
	catch (const FormatException^) {
		solutionTB->Text += "Некоректні символи в кроці";
		textBoxStep->BackColor = Color::Red;
		return false;
	}

	if ((f->getX1() > f->getX2() && f->getStep() > 0) ||
		(f->getX1() < f->getX2() && f->getStep() < 0)) {
		solutionTB->Text += "Будь ласка, змініть місцями x1 та x2 або змініть крок на протилежний\r\n";
		return false;
	}
	if (f->getStep() != 0 && (abs(f->getX1() - f->getX2()) / f->getStep()) > 1001) {
		solutionTB->Text += "Будь ласка, введіть область і крок, що передбачають менше 1000 обчислень значення функції\r\n";
		return false;
	}
	return true;
}

Void Form1::buttonCalc_Click(System::Object^ sender, System::EventArgs^ e) {
	x->clear();
	y->clear();
	chart1->ChartAreas->Clear();
	chart1->Series->Clear();
	if (!scanInfo()) return;
	solutionTB->Text = "x: f(x)\r\n";
	double x1 = f->getX1(), x2 = f->getX2();
	if (x1 == x2) {
		try {
			double val = f->value(x1);
			solutionTB->Text += Convert::ToString(x1) + ": " + val + "\r\n";
			x->push_back(x1);
			y->push_back(val);
		}
		catch (const char* s) {
			solutionTB->Text += gcnew String(s);
		}
		return;
	}

	if (f->getStep() == 0) {
		try {
			double val = f->value(x1);
			solutionTB->Text += Convert::ToString(x1) + ": " + val + "\r\n";
			x->push_back(x1);
			y->push_back(val);
		}
		catch (const char* s) {
			solutionTB->Text += gcnew String(s);
		}
		try {
			double val = f->value(x2);
			solutionTB->Text += Convert::ToString(x2) + ": " + val + "\r\n";
			x->push_back(x2);
			y->push_back(val);
		}
		catch (const char* s) {
			solutionTB->Text += gcnew String(s);
		}
		return;
	}

	if (x1 < x2) {
		for (double i = x1; i < x2; i += f->getStep()) {
			try {
				double val = f->value(i);
				solutionTB->Text += Convert::ToString(i) + ": " + val + "\r\n";
				x->push_back(i);
				y->push_back(val);
			}
			catch (const char* s) {
				solutionTB->Text += gcnew String(s);
			}
		}
	}
	else {
		for (double i = x1; i > x2; i += f->getStep()) {
			try {
				double val = f->value(i);
				solutionTB->Text += Convert::ToString(i) + ": " + val + "\r\n";
				x->push_back(i);
				y->push_back(val);
			}
			catch (const char* s) {
				solutionTB->Text += gcnew String(s);
			}
		}
	}

	try {
		double val = f->value(x2);
		solutionTB->Text += Convert::ToString(x2) + ": " + val + "\r\n";
		x->push_back(x2);
		y->push_back(val);
	}
	catch (const char* s) {
		solutionTB->Text += gcnew String(s);
	}
	chart1_Paint();
}

Void Form1::chart1_Paint() {
	chart1->ChartAreas->Add("ChartArea1");
	chart1->ChartAreas["ChartArea1"]->AxisX->Title = "X";
	chart1->ChartAreas["ChartArea1"]->AxisY->Title = "Y";
	Series^ series = gcnew Series();
	series->ChartType = SeriesChartType::Point;
	series->Color = Color::DarkOrange;
	series->BorderWidth = 2;

	for (int i = 0; i < x->size(); i++)
	{
		series->Points->AddXY(x->at(i), y->at(i));
	}
	chart1->Series->Add(series);
}