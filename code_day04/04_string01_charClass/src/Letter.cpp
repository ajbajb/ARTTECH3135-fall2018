#include "Letter.h"


Letter::Letter()
{
	speed = 10;
	size = 15;
	acceleration = -0.03;
	c = ofColor( 0, 180, 90);
}

Letter::~Letter()
{
	// nothing to destruct
}

void Letter::setup(string _letter, float _x, float _y, int _s)
{
	xPos = _x;
	yPos = _y;
	
	theLetter = _letter;
	size = _s;
	
	font.load("/Library/Fonts/Arial.ttf", size);
}

void Letter::update()
{
	if (speed > 0)
	{
		yPos += speed;
		speed += acceleration;
	}
	
	if (yPos >= ofGetHeight())
	{
		yPos = 0;
	}
	
}

void Letter::draw()
{
	ofSetColor(c);
	ofFill();
	font.drawString(theLetter, xPos, yPos);
}
