#pragma once

#include "ofMain.h"

class Ball {
public:
	Ball();
	~Ball();
	
	void setup();
	void update();
	void draw();
	
	// has position
	float px;
	float py;
	
	// has velocity
	float vx;
	float vy;
	
	// has acceleration
	float ax;
	float ay;
	
	// has a direction
	int dx;
	int dy;
	
	// a top speed
	float topSpeed;
	
	// has a size
	int radius;
	
	// has a color
	ofColor c;
};
