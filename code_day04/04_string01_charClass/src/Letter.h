#pragma once

#include "ofMain.h"

class Letter {
public:
	Letter();
	~Letter();
	
	void setup(string _letter, float _x, float _y, int _s);
	void update();
	void draw();
	
	string theLetter;
	ofColor c;
	
	float xPos;
	float yPos;
	float speed;
	float acceleration;
	
	float size;
	
	ofTrueTypeFont font;
};
