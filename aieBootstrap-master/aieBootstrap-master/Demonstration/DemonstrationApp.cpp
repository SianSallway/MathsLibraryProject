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
	tank.Load("../bin/textures/Tank.png");
	turret.Load("../bin/textures/GunTurret.png");

	//attach turret to the top of the tank
	tank.AddChild(&turret);

	//center tank
	tank.SetPosition(getWindowWidth() / 2.f, getWindowHeight() / 2.f);

	return true;
}

void DemonstrationApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
}

void DemonstrationApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	tank.Update(deltaTime);

	//rotate tank, using deltaTime as the rotation speed
	if (input->isKeyDown(aie::INPUT_KEY_A))
	{
		tank.Rotate(deltaTime);
	}
	if (input->isKeyDown(aie::INPUT_KEY_D))
	{
		tank.Rotate(-deltaTime);
	}

	//move tank, the 100 magic-number represents speed
	if (input->isKeyDown(aie::INPUT_KEY_W))
	{
		auto facing = Vector3(0.f, 1.f, 0.f) * deltaTime * 100;

		tank.Translate(facing.x, facing.y);
	}
	if (input->isKeyDown(aie::INPUT_KEY_S))
	{
		auto facing = Vector3(0.f, 1.f, 0.f) * deltaTime * -100;

		tank.Translate(facing.x, facing.y);
	}

	//rotate turret
	if (input->isKeyDown(aie::INPUT_KEY_LEFT))
	{
		turret.Rotate(deltaTime);
	}
	if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
	{
		turret.Rotate(-deltaTime);
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
	tank.Draw(m_2dRenderer);

	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}