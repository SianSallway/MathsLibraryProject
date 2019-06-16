#pragma once
#include "SpriteObject.h"
#include "SceneObject.h"
#include "Application.h"
#include "Renderer2D.h"
#include"Circle.h"
#include"Plane.h"
#include "Vector2.h"
#include"AABB.h"
#include <vector>

class DemonstrationApp : public aie::Application {
public:

	DemonstrationApp();
	virtual ~DemonstrationApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

	//check if each circle has collided
	void CheckBlueCollision();
	void CheckC1Collision();
	void CheckC2Collision();
	void CheckC3Collision();
protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;

	//stores all collidable and drawn circles on the screen
	vector<Circle> circlesOnScreen; 

	Circle circleControlled;
	Circle circle1;	
	Circle circle2;
	Circle circle3;
	Circle circle4;
	Circle circle5;
	Circle circle6;
	Circle circle7;
	Circle circle8;
	Circle circle9;
};