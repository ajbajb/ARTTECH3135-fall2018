#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	// get the number of seconds since Jan. 1, 1970
	// assign that number to time
	time = ofGetUnixTime();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw()
{
	// draw a black background
	ofBackground(0);
	
	// try uncommenting the next line and see how it changes the program
	//ofSeedRandom(time);

	// get a random number and assign it to xPos
	int xPos = ofRandom(ofGetWidth());
	
	// get another random number and assign it to yPos
	int yPos = ofRandom(ofGetHeight());
	
	ofSetColor(100, 0, 200);
	ofFill();
	
	// use the xPos and yPos variables to set the position of our circle
	ofDrawCircle(xPos, yPos, 40);
}
