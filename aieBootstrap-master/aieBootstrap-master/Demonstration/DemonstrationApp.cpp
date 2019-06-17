#include "DemonstrationApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"

DemonstrationApp::DemonstrationApp() {

}

DemonstrationApp::~DemonstrationApp() {

}

bool DemonstrationApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../../../../bin/font/consolas.ttf", 32);

	//load the circle objects to be used in the demonstration
	//tank.Load("./textures/Tank.png");
	turret.Load("./textures/GunTurret.png");
	circleControlled = CircleObject({1000, 500}, 50, 10);
	circleControlled.AddChild(&turret);
	circle1 = CircleObject({800, 400}, 50, 10);
	circle2 = CircleObject({200, 100}, 50, 10);
	circle3 = CircleObject({700, 800}, 50, 10);
	circle4 = CircleObject({800, 100}, 50, 10);
	circle5 = CircleObject({1300, 800}, 50, 10);
	circle6 = CircleObject({1000, 800}, 50, 10);
	circle7 = CircleObject({90, 300}, 50, 10);
	circle8 = CircleObject({1500, 700}, 50, 10);
	circle9 = CircleObject({1500, 200}, 50, 10);
	circle10 = CircleObject({400, 550}, 50, 10);
	circle11 = CircleObject({400, 900}, 50, 10);
	circle12 = CircleObject({1100, 250}, 50, 10);
	circle13 = CircleObject({1250, 450}, 50, 10);
	circle14 = CircleObject({450, 250}, 50, 10);



	return true;
}

void DemonstrationApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
}

void DemonstrationApp::CheckControlledCollision()
{
	//if the circle being controlled collides with another circle, calculate reflection
	if (circleControlled.Overlaps(circle1))
	{
		cout << "contact w/ circle" << endl;
		circleControlled.GetCollisionPoints(circle1);
		circleControlled.Reflection(circleControlled, circle1);
	}
	if (circleControlled.Overlaps(circle2))
	{
		cout << "contact w/ circle" << endl;
		circleControlled.GetCollisionPoints(circle2);
		circleControlled.Reflection(circleControlled, circle2);
	}
	if (circleControlled.Overlaps(circle3))
	{
		cout << "contact w/ circle" << endl;
		circleControlled.GetCollisionPoints(circle3);
		circleControlled.Reflection(circleControlled, circle3);
	}
	if (circleControlled.Overlaps(circle4))
	{
		cout << "contact w/ circle" << endl;
		circleControlled.GetCollisionPoints(circle4);
		circleControlled.Reflection(circleControlled, circle4);
	}
	if (circleControlled.Overlaps(circle5))
	{
		cout << "contact w/ circle" << endl;
		circleControlled.GetCollisionPoints(circle5);
		circleControlled.Reflection(circleControlled, circle5);
	}
	if (circleControlled.Overlaps(circle6))
	{
		cout << "contact w/ circle" << endl;
		circleControlled.GetCollisionPoints(circle6);
		circleControlled.Reflection(circleControlled, circle6);
	}
	if (circleControlled.Overlaps(circle7))
	{
		cout << "contact w/ circle" << endl;
		circleControlled.GetCollisionPoints(circle7);
		circleControlled.Reflection(circleControlled, circle7);
	}
	if (circleControlled.Overlaps(circle8))
	{
		cout << "contact w/ circle" << endl;
		circleControlled.GetCollisionPoints(circle8);
		circleControlled.Reflection(circleControlled, circle8);
	}
	if (circleControlled.Overlaps(circle9))
	{
		cout << "contact w/ circle9" << endl;
		circleControlled.GetCollisionPoints(circle9);
		circleControlled.Reflection(circleControlled, circle9);
	}
	if (circleControlled.Overlaps(circle10))
	{
		cout << "contact w/ circle" << endl;
		circleControlled.GetCollisionPoints(circle10);
		circleControlled.Reflection(circleControlled, circle10);
	}
	if (circleControlled.Overlaps(circle11))
	{
		cout << "contact w/ circle" << endl;
		circleControlled.GetCollisionPoints(circle11);
		circleControlled.Reflection(circleControlled, circle11);
	}
	if (circleControlled.Overlaps(circle12))
	{
		cout << "contact w/ circle" << endl;
		circleControlled.GetCollisionPoints(circle12);
		circleControlled.Reflection(circleControlled, circle12);
	}
	if (circleControlled.Overlaps(circle13))
	{
		cout << "contact w/ circle" << endl;
		circleControlled.GetCollisionPoints(circle13);
		circleControlled.Reflection(circleControlled, circle13);
	}
	if (circleControlled.Overlaps(circle14))
	{
		cout << "contact w/ circle14" << endl;
		circleControlled.GetCollisionPoints(circle14);
		circleControlled.Reflection(circleControlled, circle14);
	}
}

void DemonstrationApp::CheckC1Collision()
{
	//if the circle 1 collides with another circle, calculate reflection
	if (circle1.Overlaps(circle2))
	{
		cout << "contact w/ circle" << endl;
		circle1.GetCollisionPoints(circle1);
		circle1.Reflection(circle1, circle2);
	}
	if (circle1.Overlaps(circle3))
	{
		cout << "contact w/ circle" << endl;
		circle1.GetCollisionPoints(circle3);
		circle1.Reflection(circle1, circle3);
	}
	if (circle1.Overlaps(circle4))
	{
		cout << "contact w/ circle" << endl;
		circle1.GetCollisionPoints(circle4);
		circle1.Reflection(circle1, circle4);
	}
	if (circle1.Overlaps(circle5))
	{
		cout << "contact w/ circle" << endl;
		circle1.GetCollisionPoints(circle5);
		circle1.Reflection(circle1, circle5);
	}
	if (circle1.Overlaps(circle6))
	{
		cout << "contact w/ circle" << endl;
		circle1.GetCollisionPoints(circle6);
		circle1.Reflection(circle1, circle6);
	}
	if (circle1.Overlaps(circle7))
	{
		cout << "contact w/ circle" << endl;
		circle1.GetCollisionPoints(circle7);
		circle1.Reflection(circle1, circle7);
	}
	if (circle1.Overlaps(circle8))
	{
		cout << "contact w/ circle" << endl;
		circle1.GetCollisionPoints(circle8);
		circle1.Reflection(circle1, circle8);
	}
	if (circle1.Overlaps(circle9))
	{
		cout << "contact w/ circle" << endl;
		circle1.GetCollisionPoints(circle9);
		circle1.Reflection(circle1, circle9);
	}
	if (circle1.Overlaps(circle10))
	{
		cout << "contact w/ circle" << endl;
		circle1.GetCollisionPoints(circle10);
		circle1.Reflection(circle1, circle10);
	}
	if (circle1.Overlaps(circle11))
	{
		cout << "contact w/ circle" << endl;
		circle1.GetCollisionPoints(circle11);
		circle1.Reflection(circle1, circle11);
	}
	if (circle1.Overlaps(circle12))
	{
		cout << "contact w/ circle" << endl;
		circle1.GetCollisionPoints(circle12);
		circle1.Reflection(circle1, circle12);
	}
	if (circle1.Overlaps(circle13))
	{
		cout << "contact w/ circle" << endl;
		circle1.GetCollisionPoints(circle13);
		circle1.Reflection(circle1, circle13);
	}
	if (circle1.Overlaps(circle14))
	{
		cout << "contact w/ circle" << endl;
		circle1.GetCollisionPoints(circle14);
		circle1.Reflection(circle1, circle14);
	}
}

void DemonstrationApp::CheckC2Collision()
{
	if (circle2.Overlaps(circle3))
	{
		cout << "contact w/ circle" << endl;
		circle2.GetCollisionPoints(circle3);
		circle2.Reflection(circle2, circle3);
	}
	if (circle2.Overlaps(circle4))
	{
		cout << "contact w/ circle" << endl;
		circle2.GetCollisionPoints(circle4);
		circle2.Reflection(circle2, circle4);
	}
	if (circle2.Overlaps(circle5))
	{
		cout << "contact w/ circle" << endl;
		circle2.GetCollisionPoints(circle5);
		circle2.Reflection(circle2, circle5);
	}
	if (circle2.Overlaps(circle6))
	{
		cout << "contact w/ circle" << endl;
		circle2.GetCollisionPoints(circle6);
		circle2.Reflection(circle2, circle6);
	}
	if (circle2.Overlaps(circle7))
	{
		cout << "contact w/ circle" << endl;
		circle2.GetCollisionPoints(circle7);
		circle2.Reflection(circle2, circle7);
	}
	if (circle2.Overlaps(circle8))
	{
		cout << "contact w/ circle" << endl;
		circle2.GetCollisionPoints(circle8);
		circle2.Reflection(circle2, circle8);
	}
	if (circle2.Overlaps(circle9))
	{
		cout << "contact w/ circle" << endl;
		circle2.GetCollisionPoints(circle9);
		circle2.Reflection(circle2, circle9);
	}
	if (circle2.Overlaps(circle10))
	{
		cout << "contact w/ circle" << endl;
		circle2.GetCollisionPoints(circle10);
		circle2.Reflection(circle2, circle10);
	}
	if (circle2.Overlaps(circle11))
	{
		cout << "contact w/ circle" << endl;
		circle2.GetCollisionPoints(circle11);
		circle2.Reflection(circle2, circle11);
	}
	if (circle2.Overlaps(circle12))
	{
		cout << "contact w/ circle" << endl;
		circle2.GetCollisionPoints(circle12);
		circle2.Reflection(circle2, circle12);
	}
	if (circle2.Overlaps(circle13))
	{
		cout << "contact w/ circle" << endl;
		circle2.GetCollisionPoints(circle13);
		circle2.Reflection(circle2, circle13);
	}
	if (circle2.Overlaps(circle14))
	{
		cout << "contact w/ circle" << endl;
		circle2.GetCollisionPoints(circle14);
		circle2.Reflection(circle2, circle14);
	}
}

void DemonstrationApp::CheckC3Collision()
{
	if (circle3.Overlaps(circle4))
	{
		cout << "contact w/ circle" << endl;
		circle3.GetCollisionPoints(circle4);
		circle3.Reflection(circle3, circle4);
	}
	if (circle3.Overlaps(circle5))
	{
		cout << "contact w/ circle" << endl;
		circle3.GetCollisionPoints(circle5);
		circle3.Reflection(circle3, circle5);
	}
	if (circle3.Overlaps(circle6))
	{
		cout << "contact w/ circle" << endl;
		circle3.GetCollisionPoints(circle6);
		circle3.Reflection(circle3, circle6);
	}
	if (circle3.Overlaps(circle7))
	{
		cout << "contact w/ circle" << endl;
		circle3.GetCollisionPoints(circle7);
		circle3.Reflection(circle3, circle7);
	}
	if (circle3.Overlaps(circle8))
	{
		cout << "contact w/ circle" << endl;
		circle3.GetCollisionPoints(circle8);
		circle3.Reflection(circle3, circle8);
	}
	if (circle3.Overlaps(circle9))
	{
		cout << "contact w/ circle" << endl;
		circle3.GetCollisionPoints(circle9);
		circle3.Reflection(circle3, circle9);
	}
	if (circle3.Overlaps(circle10))
	{
		cout << "contact w/ circle" << endl;
		circle3.GetCollisionPoints(circle10);
		circle3.Reflection(circle3, circle10);
	}
	if (circle3.Overlaps(circle11))
	{
		cout << "contact w/ circle" << endl;
		circle3.GetCollisionPoints(circle11);
		circle3.Reflection(circle3, circle11);
	}
	if (circle3.Overlaps(circle12))
	{
		cout << "contact w/ circle" << endl;
		circle3.GetCollisionPoints(circle12);
		circle3.Reflection(circle3, circle12);
	}
	if (circle3.Overlaps(circle13))
	{
		cout << "contact w/ circle" << endl;
		circle3.GetCollisionPoints(circle13);
		circle3.Reflection(circle3, circle13);
	}
	if (circle3.Overlaps(circle14))
	{
		cout << "contact w/ circle" << endl;
		circle3.GetCollisionPoints(circle14);
		circle3.Reflection(circle3, circle14);
	}
}

void DemonstrationApp::CheckC4Collision()
{
	if (circle4.Overlaps(circle5))
	{
		cout << "contact w/ circle" << endl;
		circle4.GetCollisionPoints(circle5);
		circle4.Reflection(circle4, circle5);
	}
	if (circle4.Overlaps(circle6))
	{
		cout << "contact w/ circle" << endl;
		circle4.GetCollisionPoints(circle6);
		circle4.Reflection(circle4, circle6);
	}
	if (circle4.Overlaps(circle7))
	{
		cout << "contact w/ circle" << endl;
		circle4.GetCollisionPoints(circle7);
		circle4.Reflection(circle4, circle7);
	}
	if (circle4.Overlaps(circle8))
	{
		cout << "contact w/ circle" << endl;
		circle4.GetCollisionPoints(circle8);
		circle4.Reflection(circle4, circle8);
	}
	if (circle4.Overlaps(circle9))
	{
		cout << "contact w/ circle" << endl;
		circle4.GetCollisionPoints(circle9);
		circle4.Reflection(circle4, circle9);
	}
	if (circle4.Overlaps(circle10))
	{
		cout << "contact w/ circle" << endl;
		circle4.GetCollisionPoints(circle10);
		circle4.Reflection(circle4, circle10);
	}
	if (circle4.Overlaps(circle11))
	{
		cout << "contact w/ circle" << endl;
		circle4.GetCollisionPoints(circle11);
		circle4.Reflection(circle4, circle11);
	}
	if (circle4.Overlaps(circle12))
	{
		cout << "contact w/ circle" << endl;
		circle4.GetCollisionPoints(circle12);
		circle4.Reflection(circle4, circle12);
	}
	if (circle4.Overlaps(circle13))
	{
		cout << "contact w/ circle" << endl;
		circle4.GetCollisionPoints(circle13);
		circle4.Reflection(circle4, circle13);
	}
	if (circle4.Overlaps(circle14))
	{
		cout << "contact w/ circle" << endl;
		circle4.GetCollisionPoints(circle14);
		circle4.Reflection(circle4, circle14);
	}
}

void DemonstrationApp::CheckC5Collision()
{
	if (circle5.Overlaps(circle6))
	{
		cout << "contact w/ circle" << endl;
		circle5.GetCollisionPoints(circle6);
		circle5.Reflection(circle5, circle6);
	}
	if (circle5.Overlaps(circle7))
	{
		cout << "contact w/ circle" << endl;
		circle5.GetCollisionPoints(circle7);
		circle5.Reflection(circle5, circle7);
	}
	if (circle5.Overlaps(circle8))
	{
		cout << "contact w/ circle" << endl;
		circle5.GetCollisionPoints(circle8);
		circle5.Reflection(circle5, circle8);
	}
	if (circle5.Overlaps(circle9))
	{
		cout << "contact w/ circle" << endl;
		circle5.GetCollisionPoints(circle9);
		circle5.Reflection(circle5, circle9);
	}
	if (circle5.Overlaps(circle10))
	{
		cout << "contact w/ circle" << endl;
		circle5.GetCollisionPoints(circle10);
		circle5.Reflection(circle8, circle10);
	}
	if (circle5.Overlaps(circle11))
	{
		cout << "contact w/ circle" << endl;
		circle5.GetCollisionPoints(circle11);
		circle5.Reflection(circle5, circle11);
	}
	if (circle3.Overlaps(circle12))
	{
		cout << "contact w/ circle" << endl;
		circle5.GetCollisionPoints(circle12);
		circle5.Reflection(circle5, circle12);
	}
	if (circle5.Overlaps(circle13))
	{
		cout << "contact w/ circle" << endl;
		circle5.GetCollisionPoints(circle13);
		circle5.Reflection(circle5, circle13);
	}
	if (circle5.Overlaps(circle14))
	{
		cout << "contact w/ circle" << endl;
		circle5.GetCollisionPoints(circle14);
		circle5.Reflection(circle5, circle14);
	}
}

void DemonstrationApp::CheckC6Collision()
{
	if (circle6.Overlaps(circle7))
	{
		cout << "contact w/ circle" << endl;
		circle6.GetCollisionPoints(circle7);
		circle6.Reflection(circle6, circle7);
	}
	if (circle6.Overlaps(circle8))
	{
		cout << "contact w/ circle" << endl;
		circle6.GetCollisionPoints(circle8);
		circle6.Reflection(circle6, circle8);
	}
	if (circle6.Overlaps(circle9))
	{
		cout << "contact w/ circle" << endl;
		circle6.GetCollisionPoints(circle9);
		circle6.Reflection(circle6, circle9);
	}
	if (circle6.Overlaps(circle10))
	{
		cout << "contact w/ circle" << endl;
		circle6.GetCollisionPoints(circle10);
		circle6.Reflection(circle6, circle10);
	}
	if (circle6.Overlaps(circle11))
	{
		cout << "contact w/ circle" << endl;
		circle6.GetCollisionPoints(circle11);
		circle6.Reflection(circle6, circle11);
	}
	if (circle6.Overlaps(circle12))
	{
		cout << "contact w/ circle" << endl;
		circle6.GetCollisionPoints(circle12);
		circle6.Reflection(circle6, circle12);
	}
	if (circle6.Overlaps(circle13))
	{
		cout << "contact w/ circle" << endl;
		circle6.GetCollisionPoints(circle13);
		circle6.Reflection(circle6, circle13);
	}
	if (circle6.Overlaps(circle14))
	{
		cout << "contact w/ circle" << endl;
		circle6.GetCollisionPoints(circle14);
		circle6.Reflection(circle6, circle14);
	}
}

void DemonstrationApp::CheckC7Collision()
{
	if (circle7.Overlaps(circle8))
	{
		cout << "contact w/ circle" << endl;
		circle7.GetCollisionPoints(circle8);
		circle7.Reflection(circle7, circle8);
	}
	if (circle7.Overlaps(circle9))
	{
		cout << "contact w/ circle" << endl;
		circle7.GetCollisionPoints(circle9);
		circle7.Reflection(circle7, circle9);
	}
	if (circle7.Overlaps(circle10))
	{
		cout << "contact w/ circle" << endl;
		circle7.GetCollisionPoints(circle10);
		circle7.Reflection(circle7, circle10);
	}
	if (circle7.Overlaps(circle11))
	{
		cout << "contact w/ circle" << endl;
		circle7.GetCollisionPoints(circle11);
		circle7.Reflection(circle7, circle11);
	}
	if (circle7.Overlaps(circle12))
	{
		cout << "contact w/ circle" << endl;
		circle7.GetCollisionPoints(circle12);
		circle7.Reflection(circle7, circle12);
	}
	if (circle7.Overlaps(circle13))
	{
		cout << "contact w/ circle" << endl;
		circle7.GetCollisionPoints(circle13);
		circle7.Reflection(circle7, circle13);
	}
	if (circle7.Overlaps(circle14))
	{
		cout << "contact w/ circle" << endl;
		circle7.GetCollisionPoints(circle14);
		circle7.Reflection(circle7, circle14);
	}
}

void DemonstrationApp::CheckC8Collision()
{
	if (circle8.Overlaps(circle9))
	{
		cout << "contact w/ circle" << endl;
		circle8.GetCollisionPoints(circle9);
		circle8.Reflection(circle8, circle9);
	}
	if (circle8.Overlaps(circle10))
	{
		cout << "contact w/ circle" << endl;
		circle8.GetCollisionPoints(circle10);
		circle8.Reflection(circle8, circle10);
	}
	if (circle8.Overlaps(circle11))
	{
		cout << "contact w/ circle" << endl;
		circle8.GetCollisionPoints(circle11);
		circle8.Reflection(circle8, circle11);
	}
	if (circle7.Overlaps(circle12))
	{
		cout << "contact w/ circle" << endl;
		circle8.GetCollisionPoints(circle12);
		circle8.Reflection(circle8, circle12);
	}
	if (circle8.Overlaps(circle13))
	{
		cout << "contact w/ circle" << endl;
		circle8.GetCollisionPoints(circle13);
		circle8.Reflection(circle8, circle13);
	}
	if (circle8.Overlaps(circle14))
	{
		cout << "contact w/ circle" << endl;
		circle8.GetCollisionPoints(circle14);
		circle8.Reflection(circle8, circle14);
	}
}

void DemonstrationApp::CheckC9Collision()
{
	 if (circle9.Overlaps(circle10))
	 {
		cout << "contact w/ circle" << endl;
		circle9.GetCollisionPoints(circle10);
		circle9.Reflection(circle9, circle10);
	 }
	 if (circle9.Overlaps(circle11))
	 {
		 cout << "contact w/ circle" << endl;
		 circle9.GetCollisionPoints(circle11);
		 circle9.Reflection(circle9, circle11);
	 }
	 if (circle9.Overlaps(circle12))
	 {
		 cout << "contact w/ circle" << endl;
		 circle9.GetCollisionPoints(circle12);
		 circle9.Reflection(circle9, circle12);
	 }
	 if (circle9.Overlaps(circle13))
	 {
		 cout << "contact w/ circle" << endl;
		 circle9.GetCollisionPoints(circle13);
		 circle9.Reflection(circle9, circle13);
	 }
	 if (circle9.Overlaps(circle14))
	 {
		 cout << "9 contact w/ circle 14" << endl;
		 circle9.GetCollisionPoints(circle14);
		 circle9.Reflection(circle9, circle14);
	 }
}

void DemonstrationApp::CheckC10Collision()
{
	if (circle10.Overlaps(circle11))
	{
		cout << "contact w/ circle" << endl;
		circle10.GetCollisionPoints(circle11);
		circle10.Reflection(circle10, circle11);
	}
	if (circle10.Overlaps(circle12))
	{
		cout << "contact w/ circle" << endl;
		circle10.GetCollisionPoints(circle12);
		circle10.Reflection(circle10, circle12);
	}
	if (circle10.Overlaps(circle13))
	{
		cout << "contact w/ circle" << endl;
		circle10.GetCollisionPoints(circle13);
		circle10.Reflection(circle10, circle13);
	}
	if (circle10.Overlaps(circle14))
	{
		cout << "contact w/ circle" << endl;
		circle10.GetCollisionPoints(circle14);
		circle10.Reflection(circle10, circle14);
	}
}

void DemonstrationApp::CheckC11Collision()
{
	if (circle11.Overlaps(circle12))
	{
		cout << "contact w/ circle" << endl;
		circle11.GetCollisionPoints(circle12);
		circle11.Reflection(circle11, circle12);
	}
	if (circle11.Overlaps(circle13))
	{
		cout << "contact w/ circle" << endl;
		circle11.GetCollisionPoints(circle13);
		circle11.Reflection(circle11, circle13);
	}
	if (circle11.Overlaps(circle14))
	{
		cout << "contact w/ circle" << endl;
		circle11.GetCollisionPoints(circle14);
		circle11.Reflection(circle11, circle14);
	}
}

void DemonstrationApp::CheckC12Collision()
{
	if (circle12.Overlaps(circle13))
	{
		cout << "contact w/ circle" << endl;
		circle12.GetCollisionPoints(circle13);
		circle12.Reflection(circle12, circle13);
	}
	if (circle12.Overlaps(circle14))
	{
		cout << "contact w/ circle" << endl;
		circle12.GetCollisionPoints(circle14);
		circle12.Reflection(circle12, circle14);
	}
}

void DemonstrationApp::CheckC13Collision()
{
	 if (circle13.Overlaps(circle14))
	 {
		cout << "contact w/ circle" << endl;
		circle13.GetCollisionPoints(circle14);
		circle13.Reflection(circle13, circle14);
	 }
}

void DemonstrationApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	float speed = 100.f;

	circleControlled.Update(deltaTime);

	/*//rotate the tanks turrett
	if (input->isKeyDown(aie::INPUT_KEY_LEFT))
	{
		turret.Rotate(deltaTime);
	}
	if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
	{
		turret.Rotate(-deltaTime);
	}*/

	// Rotate turret
	turret.Rotate(deltaTime);

	//add and subtract circle speed from the circles velocity vector axis to create movement
	if (input->wasKeyPressed(aie::INPUT_KEY_W))
	{
		//move up
		circleControlled.velocity = circleControlled.velocity + Vector2(0, speed);
	}
	if (input->wasKeyPressed(aie::INPUT_KEY_D))
	{
		//move right
		circleControlled.velocity = circleControlled.velocity + Vector2(speed, 0);
	}
	if (input->wasKeyPressed(aie::INPUT_KEY_S))
	{
		//move down
		circleControlled.velocity = circleControlled.velocity + Vector2(0, -speed);
	}
	if (input->wasKeyPressed(aie::INPUT_KEY_A))
	{
		//move left 
		circleControlled.velocity = circleControlled.velocity + Vector2(-speed, 0);
	}

	//calls the check collision functions once per frame
	CheckControlledCollision();
	CheckC1Collision();
	CheckC2Collision();
	CheckC3Collision();
	CheckC4Collision();
	CheckC5Collision();
	CheckC6Collision();
	CheckC7Collision();
	CheckC8Collision();
	CheckC9Collision();
	CheckC10Collision();
	CheckC11Collision();
	CheckC12Collision();
	CheckC13Collision();

	//updates the position of each circle object once per frame
	circleControlled.UpdatePosition(deltaTime);
	circle1.UpdatePosition(deltaTime);
	circle2.UpdatePosition(deltaTime);
	circle3.UpdatePosition(deltaTime);
	circle4.UpdatePosition(deltaTime);
	circle5.UpdatePosition(deltaTime);
	circle6.UpdatePosition(deltaTime);
	circle7.UpdatePosition(deltaTime);
	circle8.UpdatePosition(deltaTime);
	circle9.UpdatePosition(deltaTime);
	circle10.UpdatePosition(deltaTime);
	circle11.UpdatePosition(deltaTime);
	circle12.UpdatePosition(deltaTime);
	circle13.UpdatePosition(deltaTime);
	circle14.UpdatePosition(deltaTime);

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void DemonstrationApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	//draw tank texture
	//turret.Draw(m_2dRenderer);

	//draws each circle object according to its specifications
	m_2dRenderer->setRenderColour(0, 0, 255.0f, 1);
	circleControlled.Draw(m_2dRenderer);

	m_2dRenderer->setRenderColour(1, 1, 1, 1);
	circle1.Draw(m_2dRenderer);
	circle2.Draw(m_2dRenderer);
	circle3.Draw(m_2dRenderer);
	circle4.Draw(m_2dRenderer);
	circle5.Draw(m_2dRenderer);
	circle6.Draw(m_2dRenderer);
	circle7.Draw(m_2dRenderer);
	circle8.Draw(m_2dRenderer);
	circle9.Draw(m_2dRenderer);
	circle10.Draw(m_2dRenderer);
	circle11.Draw(m_2dRenderer);
	circle12.Draw(m_2dRenderer);
	circle13.Draw(m_2dRenderer);
	circle14.Draw(m_2dRenderer);

	// output some text, uses the last used colour
	//m_2dRenderer->drawText(m_font, "Use arrow keys to ", 10, 950);
	//m_2dRenderer->drawText(m_font, "rotate turret", 10, 890);
	m_2dRenderer->drawText(m_font, "Use WASD to move", 900, 555);
	m_2dRenderer->drawText(m_font, "Use full-screen mode", 360, 10);
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 10, 10);

	// done drawing sprites
	m_2dRenderer->end();
}