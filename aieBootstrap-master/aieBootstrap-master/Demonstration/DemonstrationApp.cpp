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

	//load the sprites
	circle = Circle({500, 500}, 50, 200.f);
	circle1 = Circle({800, 400}, 50, 0.f);

	return true;
}

void DemonstrationApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
}

void DemonstrationApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	float speed = 150.f;

	//rotate tank, using deltaTime as the rotation speed
	if (input->wasKeyPressed(aie::INPUT_KEY_W))
	{
		circle.velocity = circle.velocity + Vector2(0, speed);
		circle.acceleration.x = -circle.velocity.x * 0.8f;
		circle.acceleration.y = -circle.velocity.y * 0.8f;

		if (circle.velocity <= 0)
		{
			circle.velocity = Vector2(0, 0);
		}
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
	m_2dRenderer->drawCircle(circle.position.x, circle.position.y, circle.radius);
	m_2dRenderer->drawCircle(circle1.position.x, circle1.position.y, circle1.radius);
	

	// output some text, uses the last used colour
	m_2dRenderer->setRenderColour(1, 1, 1, 1);
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}