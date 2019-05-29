#include "SpriteObject.h"

SpriteObject::SpriteObject()
{
}

SpriteObject::~SpriteObject()
{
}

void SpriteObject::OnDraw(aie::Renderer2D* renderer)
{
	renderer->drawSpriteTransformed3x3(texture, (float*)&globalTransform);
}