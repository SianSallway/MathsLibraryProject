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
	virtual ~SpriteObject() { delete texture;  }

	bool Load(const char* filename)
	{
		delete texture;

		texture = nullptr;
		//texture = new aie::Texture(filename);
		return texture != nullptr;
	}

	virtual void OnDraw(aie::Renderer2D* renderer);

protected:

	aie::Texture* texture = nullptr;

};

