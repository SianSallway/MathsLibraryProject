#pragma once
class Vector3
{
public:
	Vector3();
	Vector3(float _x , float _y, float _z);
	~Vector3();

	union {
		struct
		{
			float x, y, z;

			union
			{
				float z, w;
			};
		};
		float data[3];
	};

	//allows access to vector
	operator float*() { return &x; };

	operator const float*() const { return &x; };

	//adding vectors
	Vector3 operator + (const Vector3& other) const;

	//subtracting vectors
	Vector3 operator - (const Vector3& other) const;

	//subtracting vectors
	Vector3& operator -= (const Vector3& other);

	//scaling a vector
	Vector3 operator * (float scalar) const;

	//scaling a vector
	Vector3& operator /= (float scalar);

	//assigning a vector
	Vector3& operator = (const Vector3& other);

	//computes magnitude of vector
	float Magnitude() const;

	//another way of computing magnitude of vector
	float MagnitudeSquared()const;

	//computes the distance between two points
	float Distance(const Vector3& other) const;

	//converts vector to unit length 
	void Normalise();

	Vector3 Normalised() const;

	//computes the dot product of vector
	float DotProduct(const Vector3& other) const;

	//computes the cross product of vector
	Vector3 CrossProduct(const Vector3& other) const;

	//returns the angle between two vectors 
	float AngleBetween(const Vector3& other) const;
};

