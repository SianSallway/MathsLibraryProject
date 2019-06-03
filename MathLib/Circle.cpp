#include "stdafx.h"
#include "Circle.h"
#include <math.h>

Circle::Circle()
{
}

Circle::~Circle()
{
}

void Circle::Fit(const Vector2* points, unsigned int count)
{
	//invalidate extents
	min = { FLT_MAX, FLT_MAX };
	max = { FLT_MIN, FLT_MIN };

	//loop through all points to find the min and max of the points
	for (unsigned int i = 0; i < count; ++i, ++points)
	{
		min = ::min(min, *points);
		max = ::max(max, *points);
	}

	//put a circle around the min/max box
	center = (min + max) * 0.5f;
	radius = center.Distance(max);
}

void Circle::Fit(const vector<Vector2>&points)
{
	//invalidate the extents
	min = { FLT_MAX, FLT_MAX };
	max = { FLT_MIN, FLT_MIN };

	//loop through all points to find the min and max of the points
	for (auto& p : points)
	{
		min = ::min(min, p);
		max = ::max(max, p);
	}

	//put a circle around the min/max box
	center = (min + max) * 0.5f;
	radius = center.Distance(max);
}

//test for points and circles overlaping 
bool Circle::Overlaps(const Vector2& p) const
{
	Vector2 toPoint = p - center;
	
	return toPoint.MagnitudeSquared() <= (radius * radius);
}

//test for more than one circle overlaping
bool Circle::Overlaps(const Circle& other) const
{
	Vector2 difference = other.center - center;

	//compare distance between circles to combined radii
	float r = radius + other.radius;

	return difference.MagnitudeSquared() <= (r * r);
}

//test for boxes and circles overlaping
bool Circle::Overlaps(const AABB& box) const
{
	auto difference = box.Center - center;

	return difference.dot(difference) <= (radius * radius);
}

//finding the closest point to a circle from another point
Vector2 Circle::ClosestPoint(const Vector2& p)
{
	//distance from the center
	Vector2 toPoint = p - center;

	//if outside of circle radius bring it back to the radius
	if (toPoint.MagnitudeSquared() > radius * radius)
	{
		toPoint = toPoint.Normalised() * radius;
	}

	return center + toPoint;
}