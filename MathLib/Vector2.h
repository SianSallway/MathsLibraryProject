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
	
	//allows access to a chosen axis or dimension
	float operator[](int index);

	//adding vectors
	Vector2 operator + (const Vector2& other) const;

	//subtracting vectors
	Vector2& operator -= (const Vector2& other);

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
};

