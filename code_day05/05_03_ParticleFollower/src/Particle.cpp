#include "Particle.h"


Particle::Particle(){}

Particle::~Particle(){}

void Particle::update()
{
	velocity += acceleration + mouseForce;
	velocity *= drag;
	position += velocity;
	mouseForce = {0, 0};
}

void Particle::draw()
{
	ofSetColor(c);
	ofFill();
	ofDrawCircle(position, radius);
}


