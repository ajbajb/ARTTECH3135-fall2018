#pragma once

#include "ofMain.h"
#include "Ball.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void mousePressed(int x, int y, int button);
		
	std::vector<Ball> balls;
	
	const int NUM_BALLS = 5;
	
	

};
