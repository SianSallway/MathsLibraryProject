#pragma once
class Colour
{
public:
	Colour();
	Colour(float _r, float _g, float _b);
	~Colour();

	union
	{
		struct
		{
			float r, g, b;
		};

		float data[3];
	};

	void SetRed(float value);

	void SetBlue(float value);
	
	void SetGreen(float value);

	float GetRed();

	float GetBlue();

	float GetGreen();
};

