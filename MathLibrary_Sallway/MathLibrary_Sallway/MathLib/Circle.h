#pragma once
#include "Vector2.h"
#include "AABB.h"
#include <vector>
#include <iostream>

using namespace std;

class Circle
{
public:
	Circle();
	Circle(const Vector2& p, float r) : center(p), radius(r) {}
	~Circle();

	Vector2 center;
	float radius;
	Vector2 min;
	Vector2 max;

	void Fit(const Vector2* points, unsigned int count);

	void Fit(const vector<Vector2>& points);

	//test for points and circles overlaping 
	bool Overlaps(const Vector2& p) const;

	//test for more than one circle overlaping
	bool Overlaps(const Circle& other) const;

	//test for boxes and circles overlaping
	bool Overlaps(const AABB& box) const;

	//finding the closest point to a circle from another point
	Vector2 ClosestPoint(const Vector2& p);

};

