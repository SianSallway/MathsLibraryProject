#include "stdafx.h"
#include "AABB.h"
#include <math.h>

AABB::~AABB()
{
}

//center = the point between the min and max
Vector2 AABB::Center() const
{
	return (min + max) * 0.5f;
}

//half-extents = subtracting the min from max point & halving the absolute value for each vector component
Vector2 AABB::Extents() const
{
	return { abs(max.x - min.x) * 0.5f, abs(max.y - min.y) * 0.5f };
}

//returns the corners of the box 
vector<Vector2> AABB::Corners() const
{
	vector<Vector2> corners(4);

	corners[0] = min;
	corners[1] = { min.x, max.y };
	corners[2] = max;
	corners[3] = { max.x, min.y };

	return corners;
}
