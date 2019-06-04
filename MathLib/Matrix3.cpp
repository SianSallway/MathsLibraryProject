#include "stdafx.h"
#include "Matrix3.h"
#include <math.h>

Matrix3::Matrix3()
{
	xAxis = { 1, 0, 0 };
	yAxis = { 0, 1, 0 };
	zAxis = { 0, 0, 1 };
}

Matrix3::~Matrix3()
{
}

//create a static const identity matrix
const Matrix3 Matrix3::identity;// = Matrix3(1, 0, 0, 0, 1, 0, 0, 0, 1);

// reference access so it can be modified
Vector3& Matrix3::operator [] (int index)
{
	return axis[index];
}

// const access for read-only
const Vector3& Matrix3::operator [] (int index) const
{
	return axis[index];
}

//binary * operator
Matrix3 Matrix3::operator * (const Matrix3& other) const
{
	Matrix3 result;

	for (int r =0; r < 3; ++r)
	{
		for (int c = 0; c < 3; ++r)
		{
			result.data[c][r] = data[0][r] * other.data[c][0] +
								data[1][r] * other.data[c][1] +
								data[2][r] * other.data[c][2];
		}
	}
	return result;
}

//binary * operator
Vector3 Matrix3::operator * (const Vector3& v) const
{
	Vector3 result;

	result[0] = data[0][0] * v[0] + data[1][0] * v[1] + data[2][0] * v[2];
	result[1] = data[0][1] * v[0] + data[1][1] * v[1] + data[2][1] * v[2];
	result[2] = data[0][2] * v[0] + data[1][2] * v[1] + data[2][2] * v[2];

	return result;
}

Matrix3& Matrix3::operator = (const Matrix3& other)
{
	for (int row = 0; row < 3; ++row)
	{
		for (int col = 0; col < 3; ++col)
		{
			data[col][row] = other.data[col][row];
		}
	}

	return *this;
}

//creating a scaled matrix
void Matrix3::SetScaled(float x, float y, float z)
{
	//set scale of each axis
	xAxis = {x, 0, 0};
	yAxis = {0, y, 0};
	zAxis = {0, 0, z};
}

//applying scaling to an existing matrix
void Matrix3::Scale(float x, float y, float z)
{
	Matrix3 m;
	m.SetScaled(x, y, z);

	*this = *this * m;
}

Matrix3 Matrix3::Transposed() const
{
	Matrix3 result;

	//flip row and column
	for (int r = 0; r < 3; ++r)
	{
		for (int c = 0; c < 3; ++c)
		{
			result.data[r][c] = data[c][r];
		}
	}

	return result;
}

//sets up a matrix to be rotated around the x axis
void Matrix3::SetRotateX(float radians)
{
	//leave x axis and elements unchanged
	xAxis = {1, 0, 0};
	yAxis = {1, cosf(radians), sinf(radians)};
	zAxis = {1, -sinf(radians), cosf(radians)};
}

//sets up a matrix to be rotated around the y axis
void Matrix3::SetRotateY(float radians)
{
	//leave y axis and elements unchanged
	xAxis = {cosf(radians), 0, -sinf(radians)};
	yAxis = {0, 1, 0};
	zAxis = {sinf(radians), 0, cosf(radians)};
}

//sets up a matrix to be rotated around the z axis
void Matrix3::SetRotateZ(float radians)
{
	//leave z axis and elements unchanged
	xAxis = {cosf(radians), 0, -sinf(radians)};
	yAxis = {sinf(radians), cosf(radians), 0};
	zAxis = {0, 0, 1};
}

//rotates and existing matrix around the x axis
void Matrix3::RotateX(float radians)
{
	Matrix3 m;
	m.SetRotateX(radians);

	*this = *this * m;
}

//rotates and existing matrix around the y axis
void Matrix3::RotateY(float radians)
{
	Matrix3 m;
	m.SetRotateY(radians);

	*this = *this * m;
}

//rotates and existing matrix around the z axis
void Matrix3::RotateZ(float radians)
{
	Matrix3 m;
	m.SetRotateZ(radians);

	*this = *this * m;
}

void Matrix3::SetEuler(float pitch, float yaw, float roll)
{
	Matrix3 x, y, z;

	x.SetRotateX(pitch);
	y.SetRotateX(yaw);
	z.SetRotateX(roll);

	//combine rotations in a specific order
	*this = z * y * x;
}