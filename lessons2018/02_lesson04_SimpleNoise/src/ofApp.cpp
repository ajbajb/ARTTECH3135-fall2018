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
	// lets map all the values we could get from ofGetMouseX()
	// and map that into a range we can use for scaling the values
	// for ofNoise();
	float noiseScale = ofMap(ofGetMouseX(), 0, 255, 0.0, 0.2);
	
	// print it out, useful for later :)
	std::cout<<noiseScale<<std::endl;
	
	
	for(int x=0; x<=ofGetWidth(); x+=2)
	{
		for(int y=0; y<=ofGetHeight(); y+=2)
		{
			// here we will generate a new noise value
			// ofNoise returns a value from 0.0 - 1.0
			float noiseValue = ofNoise(x*noiseScale, y*noiseScale);
			
			// we are using noise to set a greyscale value so we need it 0.0- 255.0
			float greyscale = noiseValue * 255.0;
			
			// we will use the vaules form ofNoise to set the color of a grey rectangle
			ofSetColor(greyscale);
			ofFill();
			ofDrawRectangle(x, y, 2, 2);
		}
	}
}
