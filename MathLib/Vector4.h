#pragma once
class Vector4
{
public:
	Vector4();
	~Vector4();
	Vector4(float _x, float _y, float _z, float _w);

	union 
	{
		struct
		{
			float x, y, z, w;
		};
		float data[4];
	};

	//allows access to a chosen axis or dimension
	//float operator[](int index);

	//adding vectors
	Vector4& operator += (const Vector4& other);

	//subracting vectors
	Vector4& operator -= (const Vector4& other);

	//multiplying by scalar
	Vector4& operator *= (float scalar);

	//scaling a vector
	Vector4& operator /= (float scalar);

	//assigning a vector
	Vector4& operator = (const Vector4& other);

	//computes magnitude of vector
	float Magnitude() const;

	//converts vector to unit length 
	void Normalise();

	//computes the dot product of vector
	float DotProduct(const Vector4& other) const;

	//computes the cross product of vector
	Vector4 CrossProduct(const Vector4& other) const;
};

