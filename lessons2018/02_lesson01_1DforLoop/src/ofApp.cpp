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
	ofBackground(0);
	
	ofSetColor(255, 0, 0);
	ofFill();
	
	for(int i=0; i<10; i++)
	{
		int xPos = i*50;
		int yPos = 200;
		
		ofDrawCircle(xPos, yPos, 25);
	}
}
