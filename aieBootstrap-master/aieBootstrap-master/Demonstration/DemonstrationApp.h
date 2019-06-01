#pragma once
#include "SpriteObject.h"
#include "SceneObject.h"
#include "Application.h"
#include "Renderer2D.h"
//current
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

	SpriteObject tank;
	SpriteObject turret;
};