#include "stdafx.h"
#include "math.h"
#include "MathFuncs.h"
#include <stdexcept>

//returns a + b
double MathFuncs::Add(double a, double b)
{
	return a + b;
}

//returns a - b
double MathFuncs::Subtract(double a, double b)
{
	return a - b;
}

//returns a * b
double MathFuncs::Multiply(double a, double b)
{
	return a * b;
}

//returns a / b
double MathFuncs::Divide(double a, double b)
{
	return a / b;
}

float MathFuncs::Max(float a, float b)
{
	if (a > b)
		return a;
	else
		return b;
}

float MathFuncs::Min(float a, float b)
{
	return a < b ? a : b;
}

float MathFuncs::Clamp(float a, float min, float max)
{
	return Max(min, Min(a, max));
}

MathFuncs::MathFuncs()
{
}

MathFuncs::~MathFuncs()
{
}
