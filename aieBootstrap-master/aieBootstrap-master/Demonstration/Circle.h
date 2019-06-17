#pragma once
#include "Vector2.h"
#include "AABB.h"
#include <vector>
#include <iostream>

using namespace std;

//handles the behaviour and properties of a circle object
class Circle : public
{
public:
	Circle() {};
	Circle(const Vector2& p, float r, float m);
	~Circle();

	Vector2 position;					//x and y position 
	Vector2 velocity = { 0.0f, 0.0f };	//velocity 
	float radius;						//size
	float mass;							//mass
	Vector2 min;
	Vector2 max;

	void Fit(const Vector2* points, unsigned int count);

	void Fit(const vector<Vector2>& points);

	//test for points and circles overlaping 
	bool Overlaps(const Vector2& p) const;

	//test for more than one circle overlaping
	bool Overlaps(const Circle& other) const;

	//calculates the collision reflection if two circles of the same mass collide 
	void Reflection(Circle& c1, Circle& c2) const;

	//test for boxes and circles overlaping
	bool Overlaps(const AABB& box) const;

	//finding the closest point to a circle from another point
	Vector2 ClosestPoint(const Vector2& p);

	//returns x and y coordinantes of collision
	Vector2 GetCollisionPoints(Circle& other);

};

