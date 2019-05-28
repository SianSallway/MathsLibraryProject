#pragma once

class MathFuncs
{
public:
	MathFuncs();
	~MathFuncs();

	//returns a + b
	static double Add(double a, double b);

	//returns a - b
	static double Subtract(double a, double b);

	//returns a * b
	static double Multiply(double a, double b);

	//returns a / b
	static double Divide(double a, double b);
};

