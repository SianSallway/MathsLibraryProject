#include "pch.h"
#include <iostream>
#include "MathFuncs.h"

using namespace std;

int main()
{	
	double a = 7.4;
	int b = 99;

	cout << "a + b = " << MathFuncs::Add(a, b) << endl;

	cout << "a - b = " << MathFuncs::Subtract(a, b) << endl;

	cout << "a * b = " << MathFuncs::Multiply(a, b) << endl;

	cout << "a / b = " << MathFuncs::Divide(a, b) << endl;

	system("pause");	
	return 0;
}