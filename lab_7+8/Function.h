#pragma once
#include <cmath>

class Function {
	double x;
	double x1;
	double x2;
	double step;
public:
	Function();
	double value();
	double value(double arg);
	double getX1();
	double getX2();
	double getStep();
	void setX(double _x);
	void setX1(double _x1);
	void setX2(double _x2);
	void setStep(double _step);
};