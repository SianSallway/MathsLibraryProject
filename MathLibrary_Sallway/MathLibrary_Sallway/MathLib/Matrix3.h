#pragma once
#include "Vector3.h"

class Matrix3
{
public:
	Matrix3(float a11, float a12, float a13, float a21, float a22, float a23, float a31, float a32, float a33);
	Matrix3() {};
	~Matrix3();

	union 
	{
		struct
		{
			Vector3 xAxis;
			Vector3 yAxis;

			union
			{
				Vector3 zAxis;
				Vector3 translation;
			};
		};
		Vector3 axis[3];
		float data[3][3];
	};

	//create a static const identity matrix
	static const Matrix3 identity;

	operator float*() { return &xAxis.x; };

	operator const float*() const { return &xAxis.x; };

	//reference access so it can be modified
	Vector3& operator [] (int index);

	//const access for read-only
	const Vector3& operator [] (int index) const;

	//adding matrices
	Matrix3 operator + (const Matrix3& other) const;

	//subtracting matrices
	Matrix3 operator - (const Matrix3& other) const;

	//binary * operator
	Matrix3 operator * (const Matrix3& other) const;

	//binary * operator
	Vector3 operator * (const Vector3& v) const;

	//assigning a vector
	Matrix3& operator = (const Matrix3& other);

	//creating a scaled matrix
	void SetScaled(float x, float y, float z);

	//creating a scaled matrix passing a vector
	void SetScaled(const Vector3& other);

	//applying scaling to an existing matrix
	void Scale(float x, float y, float z);

	//applying scaling to an existing matrix passing a vector
	void Scale(const Vector3& other);

	//returns transposed matrix
	Matrix3 Transposed() const;

	//sets up a matrix to be rotated around the x axis
	void SetRotateX(float radians);

	//sets up a matrix to be rotated around the y axis
	void SetRotateY(float radians);

	//sets up a matrix to be rotated around the z axis
	void SetRotateZ(float radians);

	//rotates and existing matrix around the x axis
	void RotateX(float radians);

	//rotates and existing matrix around the y axis
	void RotateY(float radians);

	//rotates and existing matrix around the z axis
	void RotateZ(float radians);

	void SetEuler(float pitch, float yaw, float roll);
};

