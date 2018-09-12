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

	for(int x=0; x<10; x++)
	{
		for(int y=0; y<10; y++)
		{
			int xPos = x * 50;
			int yPos = y * 50;
			
			ofSetColor(255, 0, 0);
			ofFill();
			ofDrawCircle(xPos, yPos, 25);
			
			ofSetColor(255);
			string strX = "x=" + ofToString(x);
			string strY = "y=" + ofToString(y);
			ofDrawBitmapString(strX, xPos, yPos+10);
			ofDrawBitmapString(strY, xPos, yPos+20);
			
		}
	}

}
