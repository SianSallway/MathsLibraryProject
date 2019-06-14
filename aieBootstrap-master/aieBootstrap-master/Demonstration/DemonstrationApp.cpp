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
	circle = Circle({500, 500}, 50, 10);
	circle1 = Circle({800, 400}, 50, 10);
	circle2 = Circle({200, 100}, 50, 10);
	circle3 = Circle({700, 800}, 50, 10);
	circle4 = Circle({800, 100}, 50, 10);
	circle5 = Circle({70, 800}, 50, 10);
	circle6 = Circle({1000, 600}, 50, 10);


	return true;
}

void DemonstrationApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
}

void DemonstrationApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	float speed = 100.f;

	//rotate tank, using deltaTime as the rotation speed
	if (input->wasKeyPressed(aie::INPUT_KEY_W))
	{
		circle.velocity = circle.velocity + Vector2(0, speed);
	}
	if (input->wasKeyPressed(aie::INPUT_KEY_D))
	{
		circle.velocity = circle.velocity + Vector2(speed, 0);
	}
	if (input->wasKeyPressed(aie::INPUT_KEY_S))
	{
		circle.velocity = circle.velocity + Vector2(0, -speed);
	}
	if (input->wasKeyPressed(aie::INPUT_KEY_A))
	{
		circle.velocity = circle.velocity + Vector2(-speed, 0);
	}

	if (circle.Overlaps(circle1))
	{
		cout << "contact w/ circle" << endl;
		circle.GetCollisionPoints(circle1);
		circle.Reflection(circle, circle1);
	}
	if (circle.Overlaps(circle2))
	{
		cout << "contact w/ circle" << endl;
		circle.GetCollisionPoints(circle2);
		circle.Reflection(circle, circle2);
	}
	if (circle.Overlaps(circle3))
	{
		cout << "contact w/ circle" << endl;
		circle.GetCollisionPoints(circle3);
		circle.Reflection(circle, circle3);
	}
	if (circle.Overlaps(circle4))
	{
		cout << "contact w/ circle" << endl;
		circle.GetCollisionPoints(circle4);
		circle.Reflection(circle, circle4);
	}
	if (circle.Overlaps(circle5))
	{
		cout << "contact w/ circle" << endl;
		circle.GetCollisionPoints(circle5);
		circle.Reflection(circle, circle5);
	}
	if (circle.Overlaps(circle6))
	{
		cout << "contact w/ circle" << endl;
		circle.GetCollisionPoints(circle6);
		circle.Reflection(circle, circle6);
	}

	// go through all your circles
	// on each one: add velocity vector * deltaTime to position (i.e. centre)
	circle.position = circle.position + circle.velocity * deltaTime;

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void DemonstrationApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();
	
	//draw two circles
	m_2dRenderer->setRenderColour(0, 0, 225, 1);
	m_2dRenderer->drawCircle(circle.position.x, circle.position.y, circle.radius);
	m_2dRenderer->setRenderColour(1, 1, 1, 1);
	m_2dRenderer->drawCircle(circle1.position.x, circle1.position.y, circle1.radius);
	m_2dRenderer->drawCircle(circle2.position.x, circle2.position.y, circle2.radius);
	m_2dRenderer->drawCircle(circle3.position.x, circle3.position.y, circle3.radius);
	//m_2dRenderer->setRenderColour(0, 0, 225, 1);
	m_2dRenderer->drawCircle(circle4.position.x, circle4.position.y, circle4.radius);
	m_2dRenderer->drawCircle(circle5.position.x, circle5.position.y, circle5.radius);
	m_2dRenderer->drawCircle(circle6.position.x, circle6.position.y, circle6.radius);

	// output some text, uses the last used colour
	m_2dRenderer->setRenderColour(1, 1, 1, 1);
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}