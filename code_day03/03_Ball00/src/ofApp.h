#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
	
		float xPos = ofGetWidth()/2;
		float xSpeed = 2;  // our variable for speed
		int xDirection = 1; // our variable for direction
	
		//make variables to change the y position of our "Ball"
		float yPos = 50;  //this is the y position
		float ySpeed = 3; // this is the speed on the y axis
		int yDirection = 1; // this is the direction on the y
	
		ofColor backgroundColor = (255, 0, 0, 20);
	
		ofSoundPlayer note1;
		ofSoundPlayer note2;
		ofSoundPlayer note3;
		ofSoundPlayer note4;
	
	std::vector<ofSoundPlayer> notes;
	
};
