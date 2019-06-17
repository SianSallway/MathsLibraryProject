#pragma once
#include "Vector2.h"
#include "AABB.h"
#include"SceneObject.h"
#include <vector>
#include <iostream>

using namespace std;

class CircleObject : public SceneObject
{
public:
	CircleObject() {}
	CircleObject(const Vector2& p, float r, float m);
	~CircleObject();

	//Vector2 position;					//x and y position 
	Vector2 velocity = { 0.0f, 0.0f };	//velocity 
	float radius;						//size
	float mass;							//mass
	Vector2 min;
	Vector2 max;

	Vector2 GetGlobalPosition() const { return Vector2(globalTransform.zAxis.x, globalTransform.zAxis.y); }

	void OnDraw(aie::Renderer2D* renderer);

	void UpdatePosition(float deltaTime);

	//void Fit(const Vector2* points, unsigned int count);

	//void Fit(const vector<Vector2>& points);

	//test for points and circles overlaping 
	bool Overlaps(const Vector2& p) const;

	//test for more than one circle overlaping
	bool Overlaps(const CircleObject& other) const;

	//calculates the collision reflection if two circles of the same mass collide 
	void Reflection(CircleObject& c1, CircleObject& c2) const;

	//test for boxes and circles overlaping
	bool Overlaps(const AABB& box) const;

	//finding the closest point to a circle from another point
	Vector2 ClosestPoint(const Vector2& p);

	//returns x and y coordinantes of collision
	Vector2 GetCollisionPoints(CircleObject& other);

};

