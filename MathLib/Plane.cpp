#include "stdafx.h"
#include "Plane.h"


Plane::Plane(const Vector2& p1, const Vector2& p2)
{
	//calculate normalised vector from p0 to p1
	auto v = p1 - p2;
	v.Normalise();

	//set normal perpendicular to the vector 
	normal.x = -v.y;
	normal.y = v.x;

	//calculate d
	d = -p1.DotProduct(normal);
}

Plane::Plane(const Vector3& p1, const Vector3& p2, const Vector3& p3)
{
	//calculate edge vectors
	auto v1 = (p2 - p1).Normalised();
	auto v2 = (p3 - p1).Normalised();

	//calculate normal
	Vector3 n = v1.CrossProduct(v2);

	//calculate d
	d = -p1.DotProduct(n);
}

Plane::~Plane()
{
}

//calculating the distance between a point and the plane 
float Plane::DistanceTo(const Vector2& p) const
{
	//will be +ve if point is in front of plane, -ve if behind plane and 0 if on plane
	return p.DotProduct(normal) + d;
}

//finding the closest point on plane to arbitary point
Vector2 Plane::ClosestPoint(const Vector2& p) const
{
	return (p - normal) * DistanceTo(p);
}

//returns where a point is on plane depending on the result of the DistanceTo() method 
int Plane::TestSide(const Vector2& p) const
{
	float t = p.DotProduct(normal) + d;

	if (t < 0)
	{
		return PlaneResult::BACK;
	}
	else if (t > 0)
	{
		return PlaneResult::FRONT;
	}
	else
	{
		return PlaneResult::INTERSECTS;
	}
}

//returns where a circle is on plane depending on the result of the DistanceTo() method 
int Plane::TestSide(const Circle& circle) const
{
	float t = DistanceTo(circle.center);

	if (t < -circle.radius)
	{
		return PlaneResult::BACK;
	}
	else if (t > circle.radius)
	{
		return PlaneResult::FRONT;
	}
	else
	{
		return PlaneResult::INTERSECTS;
	}	
}

//returns where a box is on plane depending on the result of the DistanceTo() method 
int Plane::TestSide(const AABB& box) const
{
	//tag if we find a corner on each side
	bool side[2] = { false, false };

	//compare each corner
	for (auto c : box.Corners())
	{
		auto result = TestSide(c);

		if (result == PlaneResult::FRONT)
		{
			side[0] = true;
		}
		else if (result == PlaneResult::BACK)
		{
			side[1] = true;
		}
	}

	if (side[0] && !side[1]) //if front but not back
	{
		return PlaneResult::FRONT;
	}
	else if (side[1] && !side[0]) //if back but not front
	{
		return PlaneResult::BACK;
	}
	else
	{
		return PlaneResult::INTERSECTS;
	}
}