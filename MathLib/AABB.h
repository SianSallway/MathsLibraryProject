#pragma once
#include "Vector2.h"
#include <iostream>
#include <vector>

using namespace std;

class AABB
{
public:
	AABB() {};
	AABB(const Vector2& min, const Vector2& max) : min(min), max(max) {}
	~AABB();

	Vector2 min;
	Vector2 max;

	//center = the point between the min and max
	Vector2 Center() const;

	//half-extents = subtracting the min from max point & halving the absolute value for each vector component
	Vector2 Extents() const;

	//returns the corners of the box 
	vector<Vector2> Corners() const;
};

