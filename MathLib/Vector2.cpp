#include "stdafx.h"
#include "Vector2.h"
#include <assert.h>
#include <math.h>

Vector2::Vector2()
{
}

Vector2::Vector2(float _x, float _y)
{
	x = _x;
	y = _y;
}

Vector2::~Vector2()
{
}

float Vector2::operator[](int index)
{
	switch (index)
	{
	case 0:

		return x;
		break;

	case 1:

		return y;
		break;

	default:

		assert(false);
		break;
	}
}

//adding vectors
Vector2 Vector2::operator + (const Vector2& other) const
{
	return { x + other.x, y + other.y };
}

//subtracting vectors
Vector2 Vector2::operator - (const Vector2& other) const
{
	x - other.x;
	y - other.y;

	return *this;
}

//subtracting vectors
Vector2& Vector2::operator -= (const Vector2& other) 
{
	x -= other.x;
	y -= other.y;

	return *this;
}

//scaling a vector
Vector2 Vector2::operator * (float scalar) const
{
	x * scalar;
	y * scalar;

	return *this;
}

//scaling a vector
Vector2& Vector2::operator /= (float scalar)
{
	x /= scalar;
	y /= scalar;

	return *this;
}

//assigning a vector
Vector2& Vector2::operator = (const Vector2& other)
{
	x = other.x;
	y = other.y;

	return *this;
}

//computes magnitude of vector
float Vector2::Magnitude() const
{
	return sqrt(x * x + y * y);
}

//another way of computing magnitude of vector
float Vector2::MagnitudeSquared()const
{
	return (x * x + y * y);
}

//Converts vector to unit length 
void Vector2::Normalise()
{
	float magnitude = sqrt(x * x + y * y);

	x /= magnitude;
	y /= magnitude;
}

Vector2 Vector2::Normalised() const
{
	float mag = sqrt(x * x + y * y);
	return { x / mag, y / mag};
}
