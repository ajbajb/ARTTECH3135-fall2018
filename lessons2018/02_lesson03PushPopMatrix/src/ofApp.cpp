#include "ofApp.h"

//-------------------
void ofApp::setup(){

}

//--------------------
void ofApp::update(){

}


// just ignore this for now. it draw a grid with certain color
void drawGrid(ofColor c)
{
	ofPushStyle();
	
	ofSetLineWidth(1);
	ofSetColor(c);
	ofFill();
	ofDrawCircle(0, 0, 5);
	
	int linelength = 100;
	ofSetColor(c, 5);
	
	for(int x = -linelength; x <= linelength; x+=10)
	{
		for(int y= -linelength; y<=linelength; y+=10)
		{
			ofDrawLine(x, linelength, x, -linelength);
			ofDrawLine(linelength, y, -linelength, y);
		}
	}
	
	ofPopStyle();
}


//--------------------------------------------------------------
void ofApp::draw()
{
	ofBackground(0);
	
	// draw a grid of lines with the center being where (0,0) is
	drawGrid(ofColor(255,0, 0));
	
	// draw a rectangle at the origin
	ofNoFill();
	ofSetColor(200);
	ofSetLineWidth(3);
	ofDrawRectangle(0, 0, 100, 100);
	
	
	// ofPushMatrix will "push" another co-ordinate system on top of the current one
	ofPushMatrix();
	
		// move the coordinate system over 93 pixels to the right and 94 down
		// (usual orientation of looking at computer screen).
		ofTranslate(93, 94);
	
		// draw a grid describing the new co-ordinate system
		drawGrid(ofColor(0, 255, 0));
	
		// draw a rectangle at (0,0) in the new system
		ofDrawRectangle(0, 0, 100, 100);
	
	// restore the previous co-ordinate system. or, 'pop' the current one off
	ofPopMatrix();
	
	// lets do it again
	ofPushMatrix();
		ofTranslate(201, 255);
	
		drawGrid(ofColor(0, 0, 255));
		ofDrawRectangle(0, 0, 100, 100);
	
	ofPopMatrix();
	
	ofPushMatrix();
		ofTranslate(451, 355);
	
		drawGrid(ofColor(255, 255, 0));
		ofDrawRectangle(0, 0, 100, 100);
	
			// translations are accumulative (same with rotations, and scalings)
			ofTranslate(0, 300);
			drawGrid(ofColor(255, 0, 255));
			ofDrawRectangle(0, 0, 100, 100);
	
	ofPopMatrix();
	
}
