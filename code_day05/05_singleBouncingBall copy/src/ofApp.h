#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

	
	float px;			 // position
	float py;
	int radius = 50;
	
	float topSpeed = 11;
	float vx = topSpeed; // velocity
	float vy = topSpeed;
	
	float accel = -0.07; // acceleration
	
	int dx = 1;			 // direction
	int dy = 1;

};
