#include "stdafx.h"
#include "Ray.h"
#include "MathFuncs.h"
#include <math.h>

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

//testing for intersections with circles and the location of the intersection
bool Ray::Intersects(const Circle& circle, Vector2* i = nullptr) const
{
	//calculates ray origin to circle center
	auto l = circle.center - origin;

	//project circle center onto ray
	float t = l.DotProduct(direction);

	//get sqr distance from circle center to ray
	float dd = l.DotProduct(l) - t * t;

	//subtract penetration amount from projected distance
	t -= sqrt(circle.radius * circle.radius - dd);

	//it intersects if within ray length
	if (t >= 0 && t <= length)
	{
		//store intersection point if requested
		if (i != nullptr)
		{
			*i = origin + direction * t;
			return true;
		}
	}

	//default no intersectoin 
	return false;
}