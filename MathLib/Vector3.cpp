#include "stdafx.h"
#include "Vector3.h"
#include <assert.h>
#include <math.h>

Vector3::Vector3()
{
}

Vector3::Vector3(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
}

Vector3::~Vector3()
{
}

//adding vectors
Vector3 Vector3::operator + (const Vector3& other) const
{
	return { x + other.x, y + other.y, z + other.z };
}

//subtracting vectors
Vector3 Vector3::operator - (const Vector3& other) const
{
	return { x - other.x, y - other.y, z - other.z };
}

//subtracting vectors
Vector3& Vector3::operator -=(const Vector3& other)
{
	x -= other.x;
	y -= other.y;
	z -= other.z;

	return *this;
}

//scaling a vector
Vector3 Vector3::operator * (float scalar) const
{
	return {x * scalar, y * scalar, z * scalar};
}

//scaling a vector
Vector3& Vector3::operator /= (float scalar)
{
	x /= scalar;
	y /= scalar;
	z /= scalar;

	return *this;
}

//assigning a vector
Vector3& Vector3::operator = (const Vector3& other)
{
	x = other.x;
	y = other.y;
	z = other.z;

	return *this;
}

//computes magnitude of vector
float Vector3::Magnitude() const
{
	return sqrtf(x * x + y * y + z * z);
}

//another way of computing magnitude of vector
float Vector3::MagnitudeSquared()const
{
	return (x * x + y * y + z * z);
}

//computes the distance between two points
float Vector3::Distance(const Vector3& other) const
{
	float dX = x - other.x;
	float dY = y - other.y;
	float dZ = z - other.z;

	return sqrtf(dX * dX + dY * dY + dZ * dZ);
}

//Converts vector to unit length 
void Vector3::Normalise()
{
	float magnitude = sqrtf(x * x + y * y + z * z);

	x /= magnitude;
	y /= magnitude;
	z /= magnitude;
}

Vector3 Vector3::Normalised() const
{
	float mag = sqrtf(x * x + y * y + z * z);
	return { x / mag, y / mag, z / mag };
}

//computes the dot product of vector
float Vector3::DotProduct(const Vector3& other) const
{
	return x * other.x + y * other.y + z * other.z;
}

//computes the cross product of vector
Vector3 Vector3::CrossProduct(const Vector3& other) const
{
	return { y * other.z - z * other.y,
			 z * other.x - x * other.z,
			 x * other.y - y * other.x };
}

//returns the angle between two vectors 
float Vector3::AngleBetween(const Vector3& other) const
{
	//normalise vectors
	Vector3 a = Normalised();
	Vector3 b = other.Normalised();

	//calculate the dot product
	float dot = a.x * b.x + a.y * b.y + a.z * b.z;

	//return the angle between them
	return acosf(dot);
}