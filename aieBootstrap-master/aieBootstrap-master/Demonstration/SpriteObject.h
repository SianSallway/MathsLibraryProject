#pragma once
#include "SceneObject.h"
#include "Renderer2D.h"
#include"Font.h"
#include <iostream>

using namespace std;

class SpriteObject : public SceneObject
{
public:

	SpriteObject();
	SpriteObject(const char* filename) { Load(filename); }
	virtual ~SpriteObject();

	bool Load(const char* filename);

	virtual void OnDraw(aie::Renderer2D* renderer);

protected:

	aie::Texture* texture = nullptr;

};

