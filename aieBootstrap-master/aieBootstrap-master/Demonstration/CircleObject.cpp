#include "CircleObject.h"
#include "stdafx.h"
#include <math.h>
#include <iostream>
#include <vector>

using namespace std;

CircleObject::CircleObject(const Vector2& p, float r, float m)
{
	localTransform.SetTranslate(p.x, p.y);
	UpdateTransform();
	radius = r;
	mass = m;
}

CircleObject::~CircleObject()
{
}

// draws coloured circle at global position
void CircleObject::OnDraw(aie::Renderer2D* renderer)
{
	Vector2 globalPos = GetGlobalPosition();
	renderer->drawCircle(globalPos.x, globalPos.y, radius);
}


void CircleObject::UpdatePosition(float deltaTime)
{
	Vector2 velocityThisFrame = velocity * deltaTime;
	Translate(velocityThisFrame.x, velocityThisFrame.y);
}
/*
void CircleObject::Fit(const Vector2* points, unsigned int count)
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

void CircleObject::Fit(const vector<Vector2>&points)
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
}*/

//test for points and circles overlaping 
bool CircleObject::Overlaps(const Vector2& p) const
{
	Vector2 toPoint = p - GetGlobalPosition();

	return toPoint.MagnitudeSquared() <= (radius * radius);
}

//test for more than one circle overlaping
bool CircleObject::Overlaps(const CircleObject& other) const
{
	Vector2 difference = other.GetGlobalPosition() - GetGlobalPosition();

	//compare distance between circles to combined radii
	float r = radius + other.radius;

	return difference.MagnitudeSquared() <= (r * r);
}

//test for boxes and circles overlaping
bool CircleObject::Overlaps(const AABB& box) const
{
	auto difference = box.Center() - GetGlobalPosition();

	return difference.DotProduct(difference) <= (radius * radius);
}

void CircleObject::Reflection(CircleObject& c1, CircleObject& c2) const
{
	//distance between circles
	float distance = c1.GetGlobalPosition().Distance(c2.GetGlobalPosition());

	//how much the circles are overlaping
	float cirOverlap = distance - c1.radius - c2.radius;

	//calculate collision normal 
	Vector2 collisionN = c1.GetGlobalPosition() - c2.GetGlobalPosition();
	collisionN.Normalise();
	//c1.position -= collisionN * (cirOverlap / 2);
	//c2.position += collisionN * (cirOverlap / 2);

	//calculate relavtive velocity of circles. NOTE:If relative velocity = 0 then the circles aren't colliding
	Vector2 relativeVelocity = c1.velocity - c2.velocity;

	//project relavtive velocity vector onto the collision normal vector
	Vector2 projected = relativeVelocity.ProjectVec(relativeVelocity, collisionN);

	//collision reflection to be added and subtracted to the circles velocity 
	Vector2 ref = projected * 2;

	//old velocity becomes new velocity
	c1.velocity -= ref;
	c2.velocity += ref;

	cout << "Velocity: " << c1.velocity << endl;
}

//finding the closest point to a circle from another point
Vector2 CircleObject::ClosestPoint(const Vector2& p)
{
	//distance from the center
	Vector2 toPoint = p - GetGlobalPosition();

	//if outside of circle radius bring it back to the radius
	if (toPoint.MagnitudeSquared() > radius * radius)
	{
		toPoint = toPoint.Normalised() * radius;
	}

	return GetGlobalPosition() + toPoint;
}

//returns x and y coordinantes of collision
Vector2 CircleObject::GetCollisionPoints(CircleObject& other)
{
	Vector2 colPoint;

	colPoint.x = ((GetGlobalPosition().x * other.radius) + (other.GetGlobalPosition().x  * radius)) / (radius + other.radius);
	colPoint.y = ((GetGlobalPosition().y * other.radius) + (other.GetGlobalPosition().y  * radius)) / (radius + other.radius);

	cout << "Collided at point: " << colPoint.x << " " << colPoint.y << endl;


	return colPoint;
}
