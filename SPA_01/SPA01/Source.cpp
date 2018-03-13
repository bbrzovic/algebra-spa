#include <iostream>
#include <string>
using namespace std;

#include "ComplexNumber.h"

int main() {
	ComplexNumber k1(17, 2);
	ComplexNumber k2;
	k2.set_real(9);
	k2.set_imaginary(-2);
	ComplexNumber rez(k1, k2);
	cout << rez.get() << endl;
	return 0;
};