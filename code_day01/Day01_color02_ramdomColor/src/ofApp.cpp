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
	//ofGetMouseX();
	//ofGetMouseY();
	ofBackground(0);
	
	ofSetCircleResolution(32);
	int spacing = 10;
	
	for(int y = 0; y<ofGetHeight(); y += spacing)
	{
		for(int x = 0; x<ofGetWidth(); x += spacing)
		{
			//create a color and call it prettyColor
			ofColor prettyColor;
			
			//x goes from 0 - width ie 800
			//but we need x to go from 0-255 only
			//in this casse we will REMAP the values of x to be
			// in the range of 0-255
				//5 arguments:::
				//1. the value to be mapped (the input value)
				//2. the "input" range lower bounds (the range that x is currently in
				//3. the input range upperbounds
				//4. output range lower bounds
				//5. output range upperbounds
			float remappedX = ofMap(x, 0, ofGetWidth(), 0, 255);
			
			//create 3 variables for color components
			//hue is determined by the remapped x position
			float hue = remappedX;
			
			// saturation is determined by the remapped y position
			float sat = ofMap(y, 0, ofGetHeight(), 0, 255);
			
			//brightness IS random
			//but random can take two arguments
			//low value and high value
			//and ofRandom() will generate a random number inbetween those two values
			//here, our max random value will be 255 (the max value for brightness)
			// but our low value will be determined by a remapped mouseX pos
			
			float remappedMouseX = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0., 255., true);
			//we set the last argument in ofMap() to true, so that numbers will be CLAMPED
			//and will not go outside out output range
			
			float bright = ofRandom(remappedMouseX, 255);
			
			//use those variables to set the color
			prettyColor.setHsb(hue, sat, bright);
			
			//fill the circles
			ofFill();
			//with my pretty color
			ofSetColor(prettyColor);
			//draw the circle at x,y location
			ofDrawCircle(x, y, spacing);
		}
	}
}












