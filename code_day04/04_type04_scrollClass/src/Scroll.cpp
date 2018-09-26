#include "Scroll.h"

Scroll::Scroll()
{
	speed = ofRandom(0.6, 7.0);
	dir = -1;
	//xPos = ofGetWidth();
	yPos = ofRandom(ofGetHeight());
	c = ofColor(0, 180, 90, 90);
	
	font.load("/Library/Fonts/Arial.ttf", 15);
}

Scroll::~Scroll(){}

void Scroll::setup(string _sentence, float _x, float _y)
{
	displayStr = _sentence;
	xPos = _x;
	yPos = _y;
}

void Scroll::update()
{
	xPos += speed * dir;
	
	ofRectangle boundingRect = font.getStringBoundingBox(displayStr, xPos, yPos);
	
	if (xPos <= -boundingRect.width)
	{
		xPos = ofGetWidth();
		// yPos = ofRandom(ofGetHeight());
	}
}

void Scroll::draw()
{
	ofSetColor(c);
	ofFill();
	font.drawString(displayStr, xPos, yPos);
}
