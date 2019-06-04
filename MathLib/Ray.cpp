#include "stdafx.h"
#include "Ray.h"
#include "MathFuncs.h"
#include <algorithm>

Ray::~Ray()
{
}

Vector2 Ray::ClosestPoint(const Vector2& point) const
{
	//ray origin to arbitrary point
	auto p = point - origin;

	//project the point onto the ray and clamp by length
	float t = MathFuncs::Clamp(p.DotProduct(direction), 0.0f, length);

	//return position in direction of ray
	return origin + direction * t;
}