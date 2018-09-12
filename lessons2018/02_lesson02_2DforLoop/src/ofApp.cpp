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
		for(int j=0; j<10; j++)
		{
			int xPos = i * 50;
			int yPos = j * 50;
			
			ofDrawCircle(xPos, yPos, 25);
		}
	}
}
