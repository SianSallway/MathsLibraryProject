#pragma once
#include "SpriteObject.h"
#include "SceneObject.h"
#include "Application.h"
#include "Renderer2D.h"
#include"CircleObject.h"
#include "Vector2.h"

//handles the drawing, properties and behaviour of the physics demonstration
class DemonstrationApp : public aie::Application {
public:

	DemonstrationApp();
	virtual ~DemonstrationApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

	//checking if each circle has collided using the Overlaps() function to trigger reflection and elastic collision
	//the 14th circle doesn't need its own function as it is checked in all previous functions, I found if there were 'double ups' the reflection wouldn't be accurate
	void CheckControlledCollision();
	void CheckC1Collision();
	void CheckC2Collision();
	void CheckC3Collision();
	void CheckC4Collision();
	void CheckC5Collision();
	void CheckC6Collision();
	void CheckC7Collision();
	void CheckC8Collision();
	void CheckC9Collision();
	void CheckC10Collision();
	void CheckC11Collision();
	void CheckC12Collision();
	void CheckC13Collision();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;

	//circle object that the user can controlled and change the velocity of 
	CircleObject circleControlled;
	SpriteObject turret;

	//circle objects that the circle controlled by the user can collide with and also collide with other circle objects in the scene
	CircleObject circle1;
	CircleObject circle2;
	CircleObject circle3;
	CircleObject circle4;
	CircleObject circle5;
	CircleObject circle6;
	CircleObject circle7;
	CircleObject circle8;
	CircleObject circle9;
	CircleObject circle10;
	CircleObject circle11;
	CircleObject circle12;
	CircleObject circle13;
	CircleObject circle14;
};