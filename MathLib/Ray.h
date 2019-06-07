#pragma once
#include "Vector2.h"
#include "Circle.h"
#include <math.h>

class Ray
{
public:
	Ray() {}
	Ray(const Vector2& start, const Vector2& dir, float lgth = INFINITY) : origin(start), direction(dir), length(lgth) {}
	~Ray();

	Vector2 origin;
	Vector2 direction;
	float length;

	Vector2 ClosestPoint(const Vector2& point) const;

	//testing for intersections with circles and the location of the intersection
	bool Intersects(const Circle& circle, Vector2* I = nullptr) const;
};

