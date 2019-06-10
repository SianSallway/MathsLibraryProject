#include "stdafx.h"
#include "math.h"
#include "MathFuncs.h"
#include <stdexcept>

MathFuncs::MathFuncs()
{
}

MathFuncs::~MathFuncs()
{
}

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

double MathFuncs::Max(double a, double b)
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

double MathFuncs::Min(double a, double b)
{
	return a < b ? a : b;
}

float MathFuncs::Clamp(float a, float min, float max)
{
	return Max(min, Min(a, max));
}

double MathFuncs::Clamp(double a, double min, double max)
{
	return Max(min, Min(a, max));
}