#include "stdafx.h"
#include "Colour.h"

//current
Colour::Colour()
{
}

Colour::Colour(unsigned int _colour)
{
	SetColour(_colour);
}

Colour::~Colour()
{
}

void Colour::SetColour(unsigned int _colour)
{
	colour = _colour;
}

void Colour::SetRed(char value)
{
	colour = colour & 0x00FFFFFFFF;
	colour = colour | (value << 24);
}

void Colour::SetBlue(char value)
{
	colour = colour & 0xFFFF00FF;
	colour = colour | (value << 8);
}

void Colour::SetGreen(char value)
{
	colour = colour & 0xFF00FFFF;
	colour = colour | (value << 16);
}

void Colour::SetAlpha(char value)
{
	colour = colour & 0xFFFFFF00;
	colour = colour | (value << 0);
}

char Colour::GetRed()
{
	char alpha;
	alpha = ((colour & 0xFF000000) >> 24);

	return alpha;
}

char Colour::GetBlue()
{
	char alpha;
	alpha = ((colour & 0x0000FF00) >> 8);

	return alpha;
}

char Colour::GetGreen()
{
	char alpha;
	alpha = ((colour & 0x00FF0000) >> 16);

	return alpha;
}

char Colour::GetAlpha()
{
	char alpha;
	alpha = ((colour & 0x000000FF) >> 0);

	return alpha;
}