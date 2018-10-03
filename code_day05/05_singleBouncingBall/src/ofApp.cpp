#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofSetCircleResolution(36);
	ball2.ax = -0.1;
	ball2.ay = -0.11;
	
	ball3.ax = -0.11;
	ball3.ay = -0.2;
	ball3.px = 100;
	ball3.py = 100;
	ball3.radius = 10;
	
}

//--------------------------------------------------------------
void ofApp::update()
{
	// call the ball update function to update ball's values
	ball1.update();
	ball2.update();
	ball3.update();

}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofBackgroundGradient(ofColor::yellow, ofColor::cornflowerBlue);
	
	ball1.draw();
	ball2.draw();
	ball3.draw();
	
}










