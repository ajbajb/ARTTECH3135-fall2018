#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
	
		ofImage img1;
		ofImage img2;
	
	ofSoundPlayer player;
};
