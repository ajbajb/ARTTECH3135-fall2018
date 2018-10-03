#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofSetCircleResolution(36);

	
	// let create some objects!
	for (int i = 0; i < NUM_BALLS; i++)
	{
		Ball tempBall;
		tempBall.px = ofRandom(ofGetWidth());
		tempBall.py = ofRandom(ofGetHeight());
		tempBall.ax = -ofRandom(0.01, 0.3);
		tempBall.ay = -ofRandom(0.01, 0.3);
		tempBall.radius = ofRandom(3, 20);
		
		balls.push_back(tempBall);
	}
	
}

//--------------------------------------------------------------
void ofApp::update()
{
	// call the ball update function to update ball's values

	
	// call update on all our balls
	// ITERATE over all the balls in out ball vector
	
	for (int i = 0; i < balls.size(); i++)
	{
		balls[i].update();
		
		// maybe add something to animate the radius of the ball
	}

}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofBackgroundGradient(ofColor::yellow, ofColor::cornflowerBlue);

	// call draw on all out balls
	for (int i = 0; i < balls.size(); i++)
	{
		balls[i].draw();
	}
}

//================================================
void ofApp::mousePressed(int x, int y, int button)
{
	Ball tempBall;
	tempBall.px = x;
	tempBall.py = y;
	tempBall.ax = -ofRandom(0.01, 0.3);
	tempBall.ay = -ofRandom(0.01, 0.3);
	tempBall.radius = ofRandom(3, 20);
	
	balls.push_back(tempBall);
	
}













