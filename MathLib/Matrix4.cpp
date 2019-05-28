#include "stdafx.h"
#include "Matrix4.h"
#include <math.h>

Matrix4::Matrix4()
{
}

Matrix4::~Matrix4()
{
}

// reference access so it can be modified
Vector4& Matrix4::operator [] (int index)
{
	return axis[index];
}

// const access for read-only
const Vector4& Matrix4::operator [] (int index) const
{
	return axis[index];
}

Matrix4& Matrix4::operator = (const Matrix4& other)
{
	for (int row = 0; row < 4; ++row)
	{
		for (int col = 0; col < 4; ++col)
		{
			data[col][row] = other.data[col][row];
		}
	}

	return *this;
}

//binary * operator
Matrix4 Matrix4::operator * (const Matrix4& other) const
{
	Matrix4 result;

	for (int r = 0; r < 4; ++r)
	{
		for (int c = 0; c < 4; ++r)
		{
			result.data[c][r] = data[0][r] * other.data[c][0] +
								data[1][r] * other.data[c][1] +
								data[2][r] * other.data[c][2] +
								data[3][r] * other.data[c][3];
		}
	}
	return result;
}

//binary * operator
Vector4 Matrix4::operator * (const Vector4& v) const
{
	Vector4 result;

	/*result[0] = data[0][0] * v[0] + data[1][0] * v[1] + data[2][0] * v[2] + data[3][0] * v[3];
	result[1] = data[0][1] * v[0] + data[1][1] * v[1] + data[2][1] * v[2] + data[3][1] * v[3];
	result[2] = data[0][2] * v[0] + data[1][2] * v[1] + data[2][2] * v[2] + data[3][2] * v[3];
	result[3] = data[0][3] * v[0] + data[1][3] * v[1] + data[2][3] * v[2] + data[3][3] * v[3];*/

	return result;
}

//creating a scaled matrix
void Matrix4::SetScaled(float x, float y, float z)
{
	//set scale of each axis
	xAxis = { x, 0, 0, 0};
	yAxis = { 0, y, 0, 0};
	zAxis = { 0, 0, z , 0};
	translation = { 0, 0, 0, 1 };
}

//applying scaling to an existing matrix
void Matrix4::Scale(float x, float y, float z)
{
	Matrix4 m;
	m.SetScaled(x, y, z);

	*this = *this * m;
}

Matrix4 Matrix4::Transposed() const
{
	Matrix4 result;

	//flip row and column
	for (int r = 0; r < 4; ++r)
	{
		for (int c = 0; c < 4; ++c)
		{
			result.data[r][c] = data[c][r];
		}
	}

	return result;
}

//sets up a matrix to be rotated around the x axis
void Matrix4::SetRotateX(float radians)
{
	//leave x axis and elements unchanged
	xAxis = { 1, 0, 0, 0 };
	yAxis = { 0, cosf(radians), sinf(radians), 0 };
	zAxis = { 0, -sinf(radians), cosf(radians), 0 };
	translation = {0, 0, 0, 1};
}

//sets up a matrix to be rotated around the y axis
void Matrix4::SetRotateY(float radians)
{
	//leave y axis and elements unchanged
	xAxis = { cosf(radians), 0, -sinf(radians), 0 };
	yAxis = { 0, 1, 0 , 0};
	zAxis = { sinf(radians), 0, cosf(radians), 0};
	translation = { 0, 0, 0, 1 };
}

//sets up a matrix to be rotated around the z axis
void Matrix4::SetRotateZ(float radians)
{
	//leave z axis and elements unchanged
	xAxis = { cosf(radians), 0, -sinf(radians), 0};
	yAxis = { 0, sinf(radians), cosf(radians), 0 };
	zAxis = { 0, 0, 1, 0};
	translation = { 0, 0, 0, 1 };
}

//rotates and existing matrix around the x axis
void Matrix4::RotateX(float radians)
{
	Matrix4 m;
	m.SetRotateX(radians);

	*this = *this * m;
}

//rotates and existing matrix around the y axis
void Matrix4::RotateY(float radians)
{
	Matrix4 m;
	m.SetRotateY(radians);

	*this = *this * m;
}

//rotates and existing matrix around the z axis
void Matrix4::RotateZ(float radians)
{
	Matrix4 m;
	m.SetRotateZ(radians);

	*this = *this * m;
}

void Matrix4::SetEuler(float pitch, float yaw, float roll)
{
	Matrix4 x, y, z;

	x.SetRotateX(pitch);
	y.SetRotateX(yaw);
	z.SetRotateX(roll);

	//combine rotations in a specific order
	*this = z * y * x;
}