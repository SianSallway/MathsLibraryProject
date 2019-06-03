#pragma once
#include "Vector2.h"
#include "Vector3.h"
#include "Circle.h"
#include "AABB.h"

class Plane
{
public:

	enum PlaneResult : int
	{
		FRONT = 1,
		BACK = -1,
		INTERSECTS = 0
	};

	Plane() {}
	Plane(float x, float y, float d) : normal(x, y), d(d) {}
	Plane(const Vector2& n, float d) : normal(n), d(d) {}
	Plane(const Vector2& p1, const Vector2& p2);
	Plane(const Vector3& p1, const Vector3& p2, const Vector3& p3);
	~Plane();

	Vector2 normal;
	float d;

	//calculating the distance between a point and the plane 
	float DistanceTo(const Vector2& p) const;

	//finding the closest point on plane to arbitary point
	Vector2 ClosestPoint(const Vector2& p) const;

	//returns where a point is on plane depending on the result of the DistanceTo() method 
	int TestSide(const Vector2& p) const;

	//returns where a circle is on plane depending on the result of the DistanceTo() method 
	int TestSide(const Circle& circle) const;
	
	//returns where a box is on plane depending on the result of the DistanceTo() method 
	int TestSide(const AABB& box) const;
};

