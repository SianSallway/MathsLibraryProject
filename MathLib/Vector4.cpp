#include "stdafx.h"
#include "Vector4.h"
#include <math.h>
#include <assert.h>

Vector4::Vector4()
{
}

Vector4::Vector4(float _x, float _y, float _z, float _w)
{
	x = _x;
	y = _y;
	z = _z;
	w = _w;
}

Vector4::~Vector4()
{
}

//adding vectors
Vector4 Vector4::operator + (const Vector4& other) const
{
	return { x + other.x, y + other.y,  z + other.z , w + other.w };
}

//adding vectors
Vector4& Vector4::operator += (const Vector4& other)
{
	x += other.x;
	y += other.y;
	z += other.z;
	w += other.w;

	return *this;
}

//subtracting vectors
Vector4 Vector4::operator - (const Vector4& other) const
{
	x - other.x;
	y - other.y;
	z - other.z;
	w - other.w;

	return *this;
}

//subtracting vectors
Vector4& Vector4::operator -= (const Vector4& other)
{
	x -= other.x;
	y -= other.y;
	z -= other.z;
	w -= other.w;

	return *this;
}

//scaling a vector
Vector4 Vector4::operator * (float scalar) const
{
	return { x * scalar, y * scalar, z * scalar, w * scalar };
}

Vector4& Vector4::operator *= (float scalar)
{
	x *= scalar;
	y *= scalar;
	z *= scalar;
	w *= scalar;

	return *this;
}

//scaling a vector
Vector4& Vector4::operator /= (float scalar)
{
	x /= scalar;
	y /= scalar;
	z /= scalar;
	w /= scalar;

	return *this;
}

//assigning a vector
Vector4& Vector4::operator = (const Vector4& other)
{
	x = other.x;
	y = other.y;
	z = other.z;
	w = other.w;

	return *this;
}

//computes magnitude of vector
float Vector4::Magnitude() const
{
	return sqrt(x * x + y * y + z * z + w * w);
}

//Converts vector to unit length 
void Vector4::Normalise()
{
	float magnitude = sqrt(x * x + y * y + z * z + w * w);

	x /= magnitude;
	y /= magnitude;
	z /= magnitude;
	w /= magnitude;
}

//computes the dot product of vector
float Vector4::DotProduct(const Vector4& other) const
{
	return x * other.x + y * other.y + z * other.z + w * other.w;
}

//computes the cross product of vector
Vector4 Vector4::CrossProduct(const Vector4& other) const
{
	return { y * other.z - z * other.y,
			 z * other.x - x * other.z,
			 x * other.y - y * other.x,
			 0};
}