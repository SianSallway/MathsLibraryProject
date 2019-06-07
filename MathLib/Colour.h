#pragma once
class Colour
{
public:
	Colour();
	Colour(unsigned int _colour);
	~Colour();

	void SetColour(unsigned int _colour);

	void SetRed(char value);

	void SetBlue(char value);

	void SetGreen(char value);

	void SetAlpha(char value);

	char GetRed();

	char GetBlue();

	char GetGreen();

	char GetAlpha();

private:

	unsigned int colour;
};

