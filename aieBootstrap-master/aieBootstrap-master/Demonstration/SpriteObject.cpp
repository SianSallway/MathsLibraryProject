#include "SpriteObject.h"
#include "Texture.h"

SpriteObject::SpriteObject()
{
}

SpriteObject::~SpriteObject()
{
	delete texture;
}

void SpriteObject::OnDraw(aie::Renderer2D* renderer)
{
	renderer->drawSpriteTransformed3x3(texture, (float*)&globalTransform);
}

bool SpriteObject::Load(const char* filename)
{
	delete texture;

	texture = nullptr;
	texture = new aie::Texture(filename);
	return texture != nullptr;
}