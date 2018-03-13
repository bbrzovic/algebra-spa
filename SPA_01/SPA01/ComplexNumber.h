#pragma once
#include <string>

using namespace std;

class ComplexNumber
{
public:
	ComplexNumber();
	ComplexNumber(int a, int b);
	ComplexNumber(ComplexNumber a, ComplexNumber b);

	void set_real(int a);
	void set_imaginary(int b);

	string get();


private:
	int a, b;
};