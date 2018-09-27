#pragma once

#include "ofMain.h"
// Here is our Scroll class
// a "scroll" has:
// text to display
// a speed,
// direction
// a color
// and position (x & y)

class Scroll
{
public:
	Scroll();
	~Scroll();

	void setup(string _sentence, float _x, float _y);
	void update();
	void draw();

	string displayStr;

	float speed;
	float dir;

	float xPos;
	float yPos;

	float inc;

	ofColor c;

	ofTrueTypeFont font;
};
