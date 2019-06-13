#pragma once
#include "Vector2.h"
#include "AABB.h"
#include <vector>
#include <iostream>

using namespace std;

class Circle
{
public:
	Circle();
	Circle(const Vector2& p, float r, float m) : position(p), radius(r), mass(m) {}
	~Circle();

	Vector2 position;					// position
	Vector2 velocity = { 0.0f, 0.0f };
	Vector2 acceleration = { 0.0f, 0.0f };
	float radius;
	float mass;
	Vector2 min;
	Vector2 max;

	void Fit(const Vector2* points, unsigned int count);

	void Fit(const vector<Vector2>& points);

	//test for points and circles overlaping 
	bool Overlaps(const Vector2& p) const;

	//test for more than one circle overlaping
	bool Overlaps(const Circle& other) const;

	Vector2 Reflection(Circle& other) const;

	//test for boxes and circles overlaping
	bool Overlaps(const AABB& box) const;

	//finding the closest point to a circle from another point
	Vector2 ClosestPoint(const Vector2& p);

	//computes new velocity after collision
	Vector2 NewVelocity(Circle& other);

	//returns x and y coordinantes of collision
	Vector2 GetCollisionPoints(Circle& other);

};

