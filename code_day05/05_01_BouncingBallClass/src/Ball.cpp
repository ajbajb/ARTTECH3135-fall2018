#include "Ball.h"

Ball::Ball()
{
	// this is our contructor
	// we give default values to our Ball object
	// when it is created
	
	px = ofGetWidth()/2;
	py = ofGetHeight()/2;
	
	topSpeed = 20;
	vx = topSpeed;
	vy = topSpeed;
	
	ax = -0.09;
	ay = -0.09;
	
	dx = 1;
	dy = -1;
	
	radius = 20;
	
	c = ofColor::fromHsb(ofRandom(255), 255, 255);	
}

Ball::~Ball()
{
	// reallocating memory
	// (What do we we do with the memory of our destroyed object?)
	// we are not going to worry about this
}

void Ball::setup()
{
	// we can setup our individual object here
	// if we want

}

void Ball::update()
{
	// updating all the position variables
	// velocity decreases with acceleration
	if (vx > 0)
	{
		vx += ax;
	}
	
	if (vy > 0)
	{
		vy += ay;
	}
	
	// update position with velocity
	px += vx * dx;
	py += vy * dy;
	
	// check out walls!
	if (px < radius)  // left wall
	{
		px = radius;
		dx *= -1;
		vx = topSpeed;
		vy = topSpeed - 3;
	}
	
	if (px > ofGetWidth() - radius) // right wall
	{
		px = ofGetWidth() - radius;
		dx *= -1;
		vx = topSpeed;
		vy = topSpeed - 3;
	}
	
	if (py < radius) // top wall
	{
		py = radius;
		dy *= -1;
		
		vx = topSpeed - 3;
		vy = topSpeed;
	}
	
	if (py > ofGetHeight() - radius) // bottom wall
	{
		py = ofGetHeight() - radius;
		dy *= -1;
		vx = topSpeed - 3;
		vy = topSpeed;
	}
}

void Ball::draw()
{
	ofSetColor(c);
	ofFill();
	ofDrawCircle(px, py, radius);
	
	ofSetColor(255);
	ofDrawLine(px, py, px + radius, py);
}















