#pragma once

#include "ofMain.h"

class Ball
{
public:
	Ball();
	~Ball();
	
	void setup();
	void update();
	void draw();
	
	// position
	float px;
	float py;
	
	// velocity
	float vx;
	float vy;
	
	// acceleration
	float ax;
	float ay;
	
	// reset for velocity once a ball hits a wall
	float setVelo;
	
	// direction
	int dx;
	int dy;
	
	int radius;
	ofColor c;
	
};
