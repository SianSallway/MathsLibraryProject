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
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);

	//load the circles
	circleControlled = Circle({500, 500}, 50, 10, circlesOnScreen);
	//circlesOnScreen.push_back(circle);
	circle1 = Circle({800, 400}, 50, 10, circlesOnScreen);
	circlesOnScreen.push_back(circle1);
	circle2 = Circle({200, 100}, 50, 10, circlesOnScreen);
	circlesOnScreen.push_back(circle2);
	circle3 = Circle({700, 800}, 50, 10, circlesOnScreen);
	circlesOnScreen.push_back(circle3);
	circle4 = Circle({800, 100}, 50, 10, circlesOnScreen);
	circlesOnScreen.push_back(circle4);
	circle5 = Circle({70, 800}, 50, 10, circlesOnScreen);
	circlesOnScreen.push_back(circle5);
	circle6 = Circle({1000, 600}, 50, 10, circlesOnScreen);
	circlesOnScreen.push_back(circle6);
	circle7 = Circle({ 90, 300 }, 50, 10, circlesOnScreen);
	circlesOnScreen.push_back(circle7);
	circle8 = Circle({ 2000, 700 }, 50, 10, circlesOnScreen);
	circlesOnScreen.push_back(circle8);
	circle9 = Circle({ 2500, 200 }, 50, 10, circlesOnScreen);
	circlesOnScreen.push_back(circle9);
	
	for (int i = 0; i < circlesOnScreen.size(); i++)
	{
		cout << circlesOnScreen[i].id << endl;
	}

	return true;
}

void DemonstrationApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
}

//check if each circle has collided
void DemonstrationApp::CheckBlueCollision()
{
	//if the circle being controlled collides with another circle, calculate reflection
	if (circleControlled.Overlaps(circle1))
	{
		cout << "contact w/ circle" << endl;
		circleControlled.GetCollisionPoints(circle1);
		circleControlled.Reflection(circleControlled, circle1);
	}
	else if (circleControlled.Overlaps(circle2))
	{
		cout << "contact w/ circle" << endl;
		circleControlled.GetCollisionPoints(circle2);
		circleControlled.Reflection(circleControlled, circle2);
	}
	else if (circleControlled.Overlaps(circle3))
	{
		cout << "contact w/ circle" << endl;
		circleControlled.GetCollisionPoints(circle3);
		circleControlled.Reflection(circleControlled, circle3);
	}
	else if (circleControlled.Overlaps(circle4))
	{
		cout << "contact w/ circle" << endl;
		circleControlled.GetCollisionPoints(circle4);
		circleControlled.Reflection(circleControlled, circle4);
	}
	else if (circleControlled.Overlaps(circle5))
	{
		cout << "contact w/ circle" << endl;
		circleControlled.GetCollisionPoints(circle5);
		circleControlled.Reflection(circleControlled, circle5);
	}
	else if (circleControlled.Overlaps(circle6))
	{
		cout << "contact w/ circle" << endl;
		circleControlled.GetCollisionPoints(circle6);
		circleControlled.Reflection(circleControlled, circle6);
	}
	else if (circleControlled.Overlaps(circle7))
	{
		cout << "contact w/ circle" << endl;
		circleControlled.GetCollisionPoints(circle7);
		circleControlled.Reflection(circleControlled, circle7);
	}
	else if (circleControlled.Overlaps(circle8))
	{
		cout << "contact w/ circle" << endl;
		circleControlled.GetCollisionPoints(circle8);
		circleControlled.Reflection(circleControlled, circle8);
	}
	else if (circleControlled.Overlaps(circle9))
	{
		cout << "contact w/ circle" << endl;
		circleControlled.GetCollisionPoints(circle9);
		circleControlled.Reflection(circleControlled, circle9);
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
	else if (circle1.Overlaps(circle3))
	{
		cout << "contact w/ circle" << endl;
		circle1.GetCollisionPoints(circle3);
		circle1.Reflection(circle1, circle3);
	}
	else if (circle1.Overlaps(circle4))
	{
		cout << "contact w/ circle" << endl;
		circle1.GetCollisionPoints(circle4);
		circle1.Reflection(circle1, circle4);
	}
	else if (circle1.Overlaps(circle5))
	{
		cout << "contact w/ circle" << endl;
		circle1.GetCollisionPoints(circle5);
		circle1.Reflection(circle1, circle5);
	}
	else if (circle1.Overlaps(circle6))
	{
		cout << "contact w/ circle" << endl;
		circle1.GetCollisionPoints(circle6);
		circle1.Reflection(circle1, circle6);
	}
	else if (circle1.Overlaps(circle7))
	{
		cout << "contact w/ circle" << endl;
		circle1.GetCollisionPoints(circle7);
		circle1.Reflection(circle1, circle7);
	}
	else if (circle1.Overlaps(circle8))
	{
		cout << "contact w/ circle" << endl;
		circle1.GetCollisionPoints(circle8);
		circle1.Reflection(circle1, circle8);
	}
	else if (circle1.Overlaps(circle9))
	{
		cout << "contact w/ circle" << endl;
		circle1.GetCollisionPoints(circle9);
		circle1.Reflection(circle1, circle9);
	}
}

void DemonstrationApp::CheckC2Collision()
{
	//if the circle 2 controlled collides with another circle, calculate reflection
	if (circle2.Overlaps(circle1))
	{
		cout << "contact w/ circle" << endl;
		circle2.GetCollisionPoints(circle1);
		circle2.Reflection(circle2, circle1);
	}
	else if (circle2.Overlaps(circle3))
	{
		cout << "contact w/ circle" << endl;
		circle2.GetCollisionPoints(circle3);
		circle2.Reflection(circle2, circle3);
	}
	else if (circle2.Overlaps(circle4))
	{
		cout << "contact w/ circle" << endl;
		circle2.GetCollisionPoints(circle4);
		circle2.Reflection(circle2, circle4);
	}
	else if (circle2.Overlaps(circle5))
	{
		cout << "contact w/ circle" << endl;
		circle2.GetCollisionPoints(circle5);
		circle2.Reflection(circle2, circle5);
	}
	else if (circle2.Overlaps(circle6))
	{
		cout << "contact w/ circle" << endl;
		circle2.GetCollisionPoints(circle6);
		circle2.Reflection(circle2, circle6);
	}
	else if (circle2.Overlaps(circle7))
	{
		cout << "contact w/ circle" << endl;
		circle2.GetCollisionPoints(circle7);
		circle2.Reflection(circle2, circle7);
	}
	else if (circle2.Overlaps(circle8))
	{
		cout << "contact w/ circle" << endl;
		circle2.GetCollisionPoints(circle8);
		circle2.Reflection(circle2, circle8);
	}
	else if (circle2.Overlaps(circle9))
	{
		cout << "contact w/ circle" << endl;
		circle2.GetCollisionPoints(circle9);
		circle2.Reflection(circle2, circle9);
	}
}

void DemonstrationApp::CheckC3Collision()
{
	//if the circle being controlled collides with another circle, calculate reflection
	if (circle3.Overlaps(circle1))
	{
		cout << "contact w/ circle" << endl;
		circle3.GetCollisionPoints(circle1);
		circle3.Reflection(circle3, circle1);
	}
	else if (circle3.Overlaps(circle2))
	{
		cout << "contact w/ circle" << endl;
		circle3.GetCollisionPoints(circle2);
		circle3.Reflection(circle3, circle2);
	}

	else if (circle3.Overlaps(circle4))
	{
		cout << "contact w/ circle" << endl;
		circle3.GetCollisionPoints(circle4);
		circle3.Reflection(circle3, circle4);
	}
	else if (circle3.Overlaps(circle5))
	{
		cout << "contact w/ circle" << endl;
		circle3.GetCollisionPoints(circle5);
		circle3.Reflection(circle3, circle5);
	}
	else if (circle3.Overlaps(circle6))
	{
		cout << "contact w/ circle" << endl;
		circle3.GetCollisionPoints(circle6);
		circle3.Reflection(circle3, circle6);
	}
	else if (circle3.Overlaps(circle7))
	{
		cout << "contact w/ circle" << endl;
		circle3.GetCollisionPoints(circle7);
		circle3.Reflection(circle3, circle7);
	}
	else if (circle3.Overlaps(circle8))
	{
		cout << "contact w/ circle" << endl;
		circle3.GetCollisionPoints(circle8);
		circle3.Reflection(circle3, circle8);
	}
	else if (circle3.Overlaps(circle9))
	{
		cout << "contact w/ circle" << endl;
		circle3.GetCollisionPoints(circle9);
		circle3.Reflection(circle3, circle9);
	}
}

void DemonstrationApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	float speed = 100.f;

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

	CheckBlueCollision();
	CheckC1Collision();
	CheckC2Collision();
	CheckC3Collision();

	// go through all your circles
	// on each one: add velocity vector * deltaTime to position (i.e. centre)
	circleControlled.position = circleControlled.position + circleControlled.velocity * deltaTime;
	circle1.position = circle1.position + circle1.velocity * deltaTime;
	circle2.position = circle2.position + circle2.velocity * deltaTime;
	circle3.position = circle3.position + circle3.velocity * deltaTime;
	circle4.position = circle4.position + circle4.velocity * deltaTime;
	circle5.position = circle5.position + circle5.velocity * deltaTime;
	circle6.position = circle6.position + circle6.velocity * deltaTime;
	circle7.position = circle7.position + circle7.velocity * deltaTime;
	circle8.position = circle8.position + circle8.velocity * deltaTime;
	circle9.position = circle9.position + circle9.velocity * deltaTime;
	

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void DemonstrationApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();
	
	//draw circles
	m_2dRenderer->setRenderColour(0, 0, 225, 1);
	m_2dRenderer->drawCircle(circleControlled.position.x, circleControlled.position.y, circleControlled.radius);
	m_2dRenderer->setRenderColour(1, 1, 1, 1);
	m_2dRenderer->drawCircle(circle1.position.x, circle1.position.y, circle1.radius);
	m_2dRenderer->drawCircle(circle2.position.x, circle2.position.y, circle2.radius);
	m_2dRenderer->drawCircle(circle3.position.x, circle3.position.y, circle3.radius);
	m_2dRenderer->drawCircle(circle4.position.x, circle4.position.y, circle4.radius);
	m_2dRenderer->drawCircle(circle5.position.x, circle5.position.y, circle5.radius);
	m_2dRenderer->drawCircle(circle6.position.x, circle6.position.y, circle6.radius);
	m_2dRenderer->drawCircle(circle7.position.x, circle7.position.y, circle7.radius);
	m_2dRenderer->drawCircle(circle8.position.x, circle8.position.y, circle8.radius);
	m_2dRenderer->drawCircle(circle9.position.x, circle9.position.y, circle9.radius);

	// output some text, uses the last used colour
	//m_2dRenderer->setRenderColour(1, 1, 1, 1);
	m_2dRenderer->drawText(m_font, "Use full-screen", 10, 20);
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 10, 10);

	// done drawing sprites
	m_2dRenderer->end();
}