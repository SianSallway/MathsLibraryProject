#pragma once
#include "Vector4.h"

class Matrix4
{
public:
	Matrix4(float a11, float a12, float a13, float a14, float a21, float a22, float a23, float a24, float a31, float a32, float a33, float a34, float a41, float a42, float a43, float a44);
	Matrix4() {};
	~Matrix4();

	union
	{
		struct 
		{
			Vector4 xAxis;
			Vector4 yAxis;
			Vector4 zAxis;
			Vector4 translation;
		};
		Vector4 axis[4];
		float data[4][4];
	};

	//create a static const identity matrix
	static const Matrix4 identity;

	// reference access so it can be modified
	Vector4& operator [] (int index);

	// const access for read-only
	const Vector4& operator [] (int index) const;

	//binary * operator
	Matrix4 operator * (const Matrix4& other) const;

	//binary * operator
	Vector4 operator * (const Vector4& v) const;

	//assigning a vector
	Matrix4& operator = (const Matrix4& other);

	//creating a scaled matrix
	void SetScaled(float x, float y, float z);

	//applying scaling to an existing matrix
	void Scale(float x, float y, float z);

	//returns transposed matrix
	Matrix4 Transposed() const;

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

