#include "stdafx.h"
#include "Ray.h"
#include <math.h>
#include <algorithm>

Ray::~Ray()
{
}

Vector2 Ray::ClosestPoint(const Vector2& point) const
{
	//ray origin to arbitrary point
	auto p = point - origin;

	//projet the point onto the ray and clamp by length
	float t = clamp(p.DotProduct(direction), 0, length);

	//return position in direction of ray
	return origin + direction * t;
}