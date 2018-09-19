#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofBackground(50);
	
	// get the time
	float time = ofGetElapsedTimef();
	
	// set the speed of our sine wave
	float freq = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 1);  //try a dynamic number here
	
	// set up our loop
	// im doing everything in the loop 800 times
	for (int i = 0; i < 800; i++) // i++ is the same as i = i + 1, "shorthand"
	{
		// sineValue is a function of 1. time 2. our freq 3. our "index"
		float sineValue = sin(time * freq * i);
		
		// map our sine values to the height of the screen
		// ofMap(value, input Low, input Hi, output Lo, output Hi)
		float yPos = ofMap(sineValue, -1, 1, 0, ofGetHeight(), true);
		
		// map sineValue to a hue
		float hue = ofMap(sineValue, -1, 1, 0, 255);
		
		// draw some circles (about 800)
		ofSetColor(ofColor::fromHsb(hue, 100, 255));
		ofFill();
		ofDrawCircle(i*8, yPos, 8);
	}

}










