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
	ofSeedRandom(ofGetMouseX());
	
	for(int x=0; x<=ofGetWidth(); x+=2)
	{
		for(int y=0; y<=ofGetHeight(); y+=2)
		{
			
			// trying changing the value for randomScale and see how it affects random();
			float randomScale = 1.0;
			//float randomScale = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0., 255.);
			float randomValue = ofRandom(randomScale);
			
			float greyscale = randomValue * (255.0/randomScale);
			
			ofSetColor(greyscale);
			ofFill();
			ofDrawRectangle(x, y, 2, 2);
		}
	}

}
