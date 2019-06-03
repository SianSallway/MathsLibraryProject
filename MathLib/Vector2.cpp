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

//computes the dot product of vector
float Vector2::DotProduct(const Vector2& other) const
{
	return x * other.x + y * other.y;
}

//distance between two points
float Vector2::Distance(const Vector2& other) const
{
	float dX = x - other.x;
	float dY = y - other.y;

	return sqrt(dX * dX + dY * dY);
}

//returns the angle between two vectors 
float Vector2::AngleBetween(const Vector2& other) const
{
	//normalise vectors
	Vector2 a = Normalised();
	Vector2 b = other.Normalised();

	//calculate the dot product
	float dot = a.x * b.x + a.y * b.y;

	//return the angle between them
	return acos(dot);
}