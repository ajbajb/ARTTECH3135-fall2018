#include "Ball.h"


Ball::Ball()
{
	// default values
	px = ofGetWidth()/2;
	py = ofGetHeight()/2;
	setVelo = 12;
	vx = setVelo;
	vy = setVelo;
	ax = -0.05;
	ay = -0.05;
	
	dx = 1;
	dy = 1;
	
	radius = 10;
	c = ofColor::fromHsb(ofRandom(255), 200, 180);
	// c = ofColor(0);
}

Ball::~Ball(){}

void Ball::setup(){}

void Ball::update()
{
	if (vx > 0 and vx < 50)
	{
		vx += ax;
	}
	
	if (vy > 0 and vy < 50)
	{
		vy += ay;
	}
	
	px += vx * dx;
	py += vy * dy;
	
	// check walls
	if (px < radius)
	{
		px = radius;
		dx *= -1;
		vx = setVelo;
		vy = setVelo - 3;
	}
	
	if (px > ofGetWidth() - radius)
	{
		px = ofGetWidth() - radius;
		dx *= -1;
		vx = setVelo;
		vy = setVelo - 3;
	}
	
	if (py < radius)
	{
		py = radius;
		dy *= -1;
		vx = setVelo - 3;
		vy = setVelo;
	}
	
	if (py > ofGetHeight() - radius)
	{
		py = ofGetHeight() - radius;
		dy *= -1;
		vx = setVelo - 3;
		vy = setVelo;
	}
}

void Ball::draw()
{
	ofSetColor(c);
	ofFill();
	ofDrawCircle(px, py, radius);
}
