#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofSetCircleResolution(36);
	

}

//--------------------------------------------------------------
void ofApp::update()
{
	// speed decreases with negative acceleration
	if (vx > 0)
	{
		vx += accel;
	}
	
	if (vy > 0)
	{
		vy += accel;
	}
	
	// add velocity to position
	px += vx * dx;
	py += vy * dy;
	
	// check wallls
	
	if (px < radius)
	{
		px = radius;
		dx *= -1;
		vx = topSpeed;
		vy = topSpeed - 2;
	}
	
	if ( px > ofGetWidth() - radius)
	{
		px = ofGetWidth() - radius;
		dx *= -1;
		vx = topSpeed;
		vy = topSpeed - 2;
	}
	
	if (py < radius)
	{
		py = radius;
		dy *=-1;
		vx = topSpeed - 2;
		vy = topSpeed;
	}
	
	if (py > ofGetHeight() - radius)
	{
		py = ofGetHeight() - radius;
		dy *= -1;
		vx = topSpeed - 2;
		vy = topSpeed;
	}

}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofBackgroundGradient(ofColor::yellow, ofColor::cornflowerBlue);
	
	ofSetColor(50);
	ofFill();
	ofDrawCircle(px, py, radius);
	
	ofSetColor(255);
	ofDrawLine(px, py, px + radius, py);
}

