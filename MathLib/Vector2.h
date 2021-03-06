#pragma once
class Vector2
{
public:
	Vector2();
	~Vector2();
	Vector2(float x, float y);

	union 
	{
		struct
		{
			float x, y;
		};
		float data[2];
	};

	//allows access to vector
	operator float*() { return &x; };

	operator const float*() const { return &x; };

	//adding vectors
	Vector2 operator + (const Vector2& other) const;

	//subtracting vectors
	Vector2 operator - (const Vector2& other) const;

	//subtracting vectors
	Vector2& operator -= (const Vector2& other);

	//adding vectors
	Vector2& operator += (const Vector2& other);

	//scaling a vector
	Vector2 operator * (float scalar) const;
	
	//scaling a vector
	Vector2& operator /= (float scalar);

	//assigning a vector
	Vector2& operator = (const Vector2& other);

	//computes magnitude of vector
	float Magnitude() const;

	//another way of computing magnitude of vector
	float MagnitudeSquared()const;

	//converts vector to unit length 
	void Normalise();

	Vector2 Normalised() const;

	//computes the dot product of vector
	float DotProduct(const Vector2& other) const;

	//distance betweentwo points
	float Distance(const Vector2& other) const;

	//returns the angle between two vectors 
	float AngleBetween(const Vector2& other) const;

	Vector2 Min(const Vector2& a, const Vector2& b);
	
	Vector2 Max(const Vector2& a, const Vector2& b);
	
	Vector2 Clamp(const Vector2& t, const Vector2& a, const Vector2& b);

	Vector2 Scale(const Vector2& v, float d);

	//projects vector of circle onto another 
	Vector2 ProjectVec(const Vector2& v1, const Vector2& v2);
};

