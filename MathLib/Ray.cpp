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
bool Ray::Intersects(const Circle& circle, Vector2* i, Vector2* r) const
{
	//calculates ray origin to circle center
	auto l = circle.position - origin;

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

			if (r != nullptr)
			{
				//get surface normal at intersection point
				auto N = ((origin + direction * t) - circle.position);
				N /= circle.radius;

				//get penetration vector 
				auto P = direction * (length - t);

				//get penetration amount 
				float p = P.DotProduct(N);

				//get reflected vector
				*r = N * -2 * p + P;
			}

			return true;
		}
	}

	//default no intersectoin 
	return false;
}

//testing for intersections with planes and the location of the intersection
bool Ray::Intersects(const Plane& plane, Vector2* i, Vector2* r) const
{
	//project ray direction onto plane normal 
	//this should give us a value between -1 and 1 
	float t = direction.DotProduct(plane.normal);

	//must face the plane 
	if (t > 0)
	{
		return false;
	}

	//get distance of ray origin to the plane 
	float d = origin.DotProduct(plane.normal) + plane.d;

	//checkif ray is parallel with the plane 
	//no intersection if parallel and not touching
	if (t == 0 && d != 0)
	{
		return false;
	}

	//calculate distance along ray to plane 
	t = d == 0 ? 0 : -(d / t);

	//intersects if within range 
	if (t >= 0 && t <= length)
	{
		//store intersection point if requested 
		if (i != nullptr)
		{
			*i = origin + direction * t;

			if (r != nullptr)
			{
				//get penetration vector
				auto P = direction * (length - t);

				//get penetration amount
				float p = P.DotProduct(plane.normal);

				//get reflected vector
				*r = plane.normal * -2 * p + P;
			}

			return true;
		}
	}

	//default no intersectoin 
	return false;
}

//testing for intersections with boxes and the location of the intersection
bool Ray::Intersects(const AABB& box, Vector2* i, Vector2* r) const
{
	//get distance to each axis of the box 
	float xMin, xMax, yMin, yMax;

	//get min and max in the x-axis
	if (direction.x < 0)
	{
		xMin = (box.max.x - origin.x) / direction.x;
		xMax = (box.min.x - origin.x) / direction.x;
	}
	else
	{
		xMin = (box.min.x - origin.x) / direction.x;
		xMax = (box.max.x - origin.x) / direction.x;
	}

	//get min and max in the y-axis
	if (direction.y < 0)
	{
		yMin = (box.max.y - origin.y) / direction.y;
		yMax = (box.min.y - origin.y) / direction.y;
	}
	else
	{
		yMin = (box.min.y - origin.y) / direction.y;
		yMax = (box.max.y - origin.y) / direction.y;
	}

	//ensure within box 
	if (xMin > yMax || yMin > xMax)
	{
		return false;
	}

	//the first contact is the largest of the two min
	float t = MathFuncs::Max(xMin, yMin);

	//intersects if within range
	if (t >= 0 && t <= length)
	{
		//store intersection point if requested 
		if (i != nullptr)
		{
			*i = origin + direction * t;

			if (r != nullptr)
			{
				//need to determine box side hit 
				Vector2 N = {};
				if ( t == xMin)
				{
					//horizontal normal
					if (direction.x < 0)
					{
						//right side
						N = { 1, 0 };
					}
					else
					{
						//left side
						N = { -1, 0 };
					}
				}
				else
				{
					//vertical normal
					if (direction.y < 0)
					{
						//top
						N = { 0, 1 };
					}
					else
					{
						//bottom
						N = { 0, -1 };
					}
				}

				//get penetration vector
				auto P = direction * (length - t);

				//get penetration amount
				float p = P.DotProduct(N);

				//get reflected vector
				*r = N * -2 * p + P;
			}

			return true;
		}
	}

	//default no intersectoin 
	return false;
}