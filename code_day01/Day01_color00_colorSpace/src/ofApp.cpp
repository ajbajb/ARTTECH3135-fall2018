#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update()
{

}

void ofApp::draw()
{
	float width = ofGetWidth();
	float halfWidth = ofGetWidth()/2;
	float halfHeight = ofGetHeight()/2;
	
	//interate through all the y-coord in out window	
	for(int y=0; y< ofGetHeight(); y++)
	{
		//at every coord (for every y in our window) iternate through all the x-coord
		//but only up till the center of the screen
		for(int x=0; x < halfWidth; x++)
		{
			//create two color variables
			//one for rgb values, one for hsb
			ofColor rgb;
			ofColor hsb;
			
			// we will use the x coord to set the red componet of our rgb color
			//remap half the widh of the window to 0-255
			float rValue = ofMap(x, 0, halfWidth, 0, 255);
			
			// we will also use the x coord to set the huw componet of our hsb color
			float hue = ofMap(x, 0, halfWidth, 0, 255);
			
			// we will use the y coord to set the green componet of our rgb color
			//remap the height of the window to 0-255
			float gValue = ofMap(y, 0, ofGetHeight(), 0, 255);
			
			//we will also use the y-coord to set the saturation of out hsb color
			float sat = ofMap(y, 0, ofGetHeight(), 0, 255);
			
			//we will use the yPos of our mouse to set the blue value of our rgb color
			float bValue = ofMap(ofGetMouseY(), 0, width, 0, 255, true);
			//and for the brightness of out hsb color
			float bright = ofMap(ofGetMouseY(), 0, width, 0, 255, true);
			
			//compose the rgb color from the different color values
			rgb = ofColor(rValue, gValue, bValue);
			ofSetColor(rgb);
			//now draw a 1x1 rectangle with that color at that xy position
			ofDrawRectangle(x, y, 1, 1);
			
			//compose the hsb color from the hue, sat, bright values
			hsb.setHsb(hue, sat, bright);
			ofSetColor(hsb);
			//now draw a rectangle at that xy "spot" with that color
			// i say "spot" because we push it over by halfWidth so that it is not on top of our rgb recatngles
			ofDrawRectangle(x+halfWidth, y, 1, 1);
		}
	}
}
