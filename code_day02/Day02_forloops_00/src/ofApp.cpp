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
	ofBackground(ofColor::fromHex(0x51B848));
	
	// A line of circles that take up the entire width of the screen
	// not drawn on top of each other
	int width = ofGetWidth();
	int radius = 25;
	
	// this is the top line of circles
	for(int x = 0; x<width; x+=radius*2) //i++ means the same as i = i+1
	{
		// This block loops while 2nd statement is true
		ofSetColor(ofColor::fromHex(0xE2D4CB));
		ofFill();
		int xPos = x;
		std::cout<<"x="<<x<<std::endl;
		std::cout<<"xPos="<<xPos<<std::endl;
		int yPos = (radius*2);
		ofDrawCircle(x, yPos, radius);
		// at the end of the block of code we are going to
		// do the 3rd statement (i=i+1), which will add one to i
	}
	
	// an emmbeded for loop. 2D!!
	for(int x = 0; x<width; x+=radius*2)
	{
		for(int y = radius*4; y<ofGetHeight(); y+=radius*2)
		{
			// last value will set opacity
			ofSetColor(ofColor::fromHex(0xF8C703),50);
			ofFill();
			ofDrawCircle(x, y, radius);
		}
	}
	
	
	
}
