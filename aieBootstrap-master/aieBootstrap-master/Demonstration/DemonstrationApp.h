#pragma once
#include "SpriteObject.h"
#include "SceneObject.h"
#include "Application.h"
#include "Renderer2D.h"
#include"Circle.h"
#include"Plane.h"
#include "Vector2.h"
#include"AABB.h"

class DemonstrationApp : public aie::Application {
public:

	DemonstrationApp();
	virtual ~DemonstrationApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;

	//SpriteObject tank;
	//SpriteObject turret;
	Circle circle;
	Circle circle1;	
	Circle circle2;
	Circle circle3;
	Circle circle4;
	Circle circle5;
	Circle circle6;
	Vector2 u;
	Vector2 v;
};