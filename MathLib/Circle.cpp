#include "stdafx.h"
#include "Circle.h"
#include <math.h>
#include <iostream>

using namespace std;

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
		min = min.Min(min, *points);
		max = min.Max(max, *points);
	}

	//put a circle around the min/max box
	position = (min + max) * 0.5f;
	radius = position.Distance(max);
}

void Circle::Fit(const vector<Vector2>&points)
{
	//invalidate the extents
	min = { FLT_MAX, FLT_MAX };
	max = { FLT_MIN, FLT_MIN };

	//loop through all points to find the min and max of the points
	for (auto& p : points)
	{
		min = min.Min(min, p);
		max = min.Max(max, p);
	}

	//put a circle around the min/max box
	position = (min + max) * 0.5f;
	radius = position.Distance(max);
}

//test for points and circles overlaping 
bool Circle::Overlaps(const Vector2& p) const
{
	Vector2 toPoint = p - position;
	
	return toPoint.MagnitudeSquared() <= (radius * radius);
}

//test for more than one circle overlaping
bool Circle::Overlaps(const Circle& other) const
{
	Vector2 difference = other.position - position;

	//compare distance between circles to combined radii
	float r = radius + other.radius;

	return difference.MagnitudeSquared() <= (r * r);
}

//test for boxes and circles overlaping
bool Circle::Overlaps(const AABB& box) const
{
	auto difference = box.Center() - position;

	return difference.DotProduct(difference) <= (radius * radius);
}

Vector2 Circle::Reflection(Circle& other) const
{
	float distance = position.Distance(other.position);

	Vector2 N;

	//tangent
	Vector2 t = {N.x, -N.y};
}

//finding the closest point to a circle from another point
Vector2 Circle::ClosestPoint(const Vector2& p)
{
	//distance from the center
	Vector2 toPoint = p - position;

	//if outside of circle radius bring it back to the radius
	if (toPoint.MagnitudeSquared() > radius * radius)
	{
		toPoint = toPoint.Normalised() * radius;
	}

	return position + toPoint;
}

//computes new velocity after collision
/*Vector2 Circle::NewVelocity(Circle& other)
{
	Vector2 newVel;
		
		newVel.x = (speed * (radius - other.radius) + (2 * radius * other.speed)) / (radius - other.radius);
		newVel.y = (speed * (radius - other.radius) + (2 * radius * other.speed)) / (radius - other.radius);

		center.x += newVel.x;
		center.y += newVel.y;

		cout << center.x << center.y << endl;

	return newVel;
}*/

//returns x and y coordinantes of collision
Vector2 Circle::GetCollisionPoints(Circle& other)
{
	Vector2 colPoint;

	colPoint.x = ((position.x * other.radius) + (other.position.x  * radius)) / (radius + other.radius);
	colPoint.y = ((position.y * other.radius) + (other.position.y  * radius)) / (radius + other.radius);

	if (colPoint.x > colPoint.y)
	{
		++position.x;
		--position.y;
	}
	else if (colPoint.x < colPoint.y)
	{
		--position.x;
		++position.y;
	}

	cout << "Collided at point: " << colPoint.x << " " << colPoint.y << endl;

	return colPoint;
}