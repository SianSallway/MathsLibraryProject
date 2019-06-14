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

void Circle::Reflection(Circle& c1, Circle& c2) const
{
	//don't need tangent just velocity normal and collision normal
	//old velocity becomes new velocity 

	//distance between circles
	float distance = c1.position.Distance(c2.position);

	//how much the circles are overlaping
	float cirOverlap = distance - c1.radius - c2.radius;

	//make sure circles are colliding on their edges rather than overlaping
	Vector2 collisionN = c1.position - c2.position;
	collisionN.Normalise();
	//c1.position -= collisionN * (cirOverlap / 2);
	//c2.position += collisionN * (cirOverlap / 2);

	//Vector2 collisionN = c1.position - c2.position;

	//Normal
	//Vector2 collisionN = {(c1.position.x - other.position.x) / distance, (c1.position.y - other.position.y) / distance };

	Vector2 relativeVelocity = c1.velocity - c2.velocity;
	
	//dot prod of relative velocity
	//float dotProdN = relativeVelocity.DotProduct(collisionN);

	Vector2 projected = relativeVelocity.ProjectVec(relativeVelocity, collisionN);

	//reflection
	Vector2 ref = projected *2;

	//velocity after collision
	/*Vector2 newPos1 = { c1.position.x - other.position.x, c1.position.y - other.position.y };
	Vector2 newPos2 = { c1.position.y - other.position.y, c1.position.x - other.position.x };

	Vector2 newVel1 = c1.velocity;
	newVel1 += newVel1.ProjectVec(other.velocity, Vector2(c1.position.x - other.position.x, c1.position.y - other.position.y));
	newVel1 -= newVel1.ProjectVec(c1.velocity, Vector2(c1.position.y - other.position.y, c1.position.x - other.position.x));

	Vector2 newVel2 = other.velocity;
	newVel2 += newVel2.ProjectVec(other.velocity, newPos1);
	newVel2 -= newVel2.ProjectVec(c1.velocity, newPos2);*/

	c1.velocity -= ref;
	c2.velocity += ref;

	cout << "Velocity: " << c1.velocity << endl;

	//float momentum = (dotProdN * (mass - other.mass) + 2.0f * other.mass * dotProdN) / (mass + other.mass);

	//Vector2 velocity = Vector2{ (t.x * dotProdT) , (t.y * dotProdT)  };	
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

	cout << "Collided at point: " << colPoint.x << " " << colPoint.y << endl;
	

	return colPoint;
}