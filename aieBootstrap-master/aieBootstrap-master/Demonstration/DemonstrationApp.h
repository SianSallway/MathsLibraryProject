#pragma once
#include "SpriteObject.h"
#include "SceneObject.h"
#include "Application.h"
#include "Renderer2D.h"
#include"Circle.h"
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
	Circle circleControlled;	
	
	//circle objects that the circle controlled by the user can collide with and also collide with other circle objects in the scene
	Circle circle1;				
	Circle circle2;
	Circle circle3;
	Circle circle4;
	Circle circle5;
	Circle circle6;
	Circle circle7;
	Circle circle8;
	Circle circle9;
	Circle circle10;
	Circle circle11;
	Circle circle12;
	Circle circle13;
	Circle circle14;

};