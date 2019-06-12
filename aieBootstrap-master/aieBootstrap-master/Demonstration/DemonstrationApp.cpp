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
	//tank.Load("../bin/textures/Tank.png");
	//turret.Load("../bin/textures/GunTurret.png");
	circle = Circle({500, 500}, 20);
	circle1 = Circle({ 800, 400 }, 20);


	/*//plane = Plane({200, 300}, {600, 700});
	//get point closest to window center
	u = plane.ClosestPoint({640, 360});
	//get vector perpendicular to the plane normal
	v = { plane.normal.y, -plane.normal.x };*/

	//attach turret to the top of the tank
	//tank.AddChild(&turret);
	//center tank
	//tank.SetPosition(getWindowWidth() / 2.f, getWindowHeight() / 2.f);

	return true;
}

void DemonstrationApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
}

void DemonstrationApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	//tank.Update(deltaTime);

	//rotate tank, using deltaTime as the rotation speed
	if (input->isKeyDown(aie::INPUT_KEY_A))
	{
		circle.center.x -= 200 * deltaTime;
		//tank.Rotate(deltaTime);
	}
	if (input->isKeyDown(aie::INPUT_KEY_D))
	{
		circle.center.x += 200 * deltaTime;
		//tank.Rotate(-deltaTime);
	}

	if (circle.Overlaps(circle1))
	{
		cout << "contact w/ circle" << endl;
		++circle1.center.x;
	}
	/*if (plane.TestSide(circle))
	{
		cout << "contact w/ plane" << endl;
	}*/

	//move tank, the 100 magic-number represents speed
	if (input->isKeyDown(aie::INPUT_KEY_W))
	{
		circle.center.y += 200 * deltaTime;
		//auto facing = Vector3(0.f, 1.f, 0.f) * deltaTime * 100;
		//tank.Translate(facing.x, facing.y);
	}
	if (input->isKeyDown(aie::INPUT_KEY_S))
	{
		circle.center.y -= 200 * deltaTime;
		//auto facing = Vector3(0.f, 1.f, 0.f) * deltaTime * -100;
		//tank.Translate(facing.x, facing.y);
	}

	//rotate turret
	if (input->isKeyDown(aie::INPUT_KEY_LEFT))
	{
		//turret.Rotate(deltaTime);
	}
	if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
	{
		//turret.Rotate(-deltaTime);
	}

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void DemonstrationApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	//tank.Draw(m_2dRenderer);
	//ball.Draw(m_2dRenderer);
	//m_2dRenderer->setRenderColour(0.f, 1.f, 0.f, 0.f);
	
	//draw two circles
	m_2dRenderer->drawCircle(circle.center.x, circle.center.y, circle.radius);
	m_2dRenderer->drawCircle(circle1.center.x, circle1.center.y, circle1.radius);
	
	/*//draw plane normal 50px in length
	m_2dRenderer->setRenderColour(0, 0.5f, 0.7f, 1);
	m_2dRenderer->drawLine(u.x, u.y, u.x + plane.normal.x * 50, u.y + plane.normal.y * 50, 4);

	//draw separating line 3000px in length
	m_2dRenderer->setRenderColour(0, 0.5f, 0.7f, 1);
	m_2dRenderer->drawLine(u.x - v.x * 1500, u.y - v.x * 1500, u.x + v.x * 1500, u.y + v.x * 1500, 4);
	//m_2dRenderer->drawLine(200.f, 400.f, 200.f, 500.f, 10, 50);*/

	// output some text, uses the last used colour
	m_2dRenderer->setRenderColour(1, 1, 1, 1);
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}