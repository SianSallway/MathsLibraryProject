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

	static float Max(float a, float b);

	static double Max(double a, double b);

	static float Min(float a, float b);
	
	static double Min(double a, double b);

	static float Clamp(float a, float min, float max);

	static double Clamp(double a, double min, double max);
};

