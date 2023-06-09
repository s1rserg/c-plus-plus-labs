#include "pch.h"
#include "Function.h"

Function::Function() {
	x = 0;
	x1 = 0;
	x2 = 0;
	step = 0;
}

double Function::value() {
	if (x == 2) {
		throw "2 не входить в область визначення\r\n";
	}
	return abs((abs((x - 2) + 1)) / (x - 2));
}

double Function::value(double arg) {
	if (arg == 2) {
		throw "2 не входить в область визначення\r\n";
	}
	return abs((abs((arg - 2) + 1)) / (arg - 2));
}

double Function::getX1() {
	return x1;
}

double Function::getX2() {
	return x2;
}

double Function::getStep() {
	return step;
}

void Function::setX(double _x) {
	x = _x;
}

void Function::setX1(double _x1) {
	x1 = _x1;
}

void Function::setX2(double _x2) {
	x2 = _x2;
}

void Function::setStep(double _step) {
	step = _step;
}