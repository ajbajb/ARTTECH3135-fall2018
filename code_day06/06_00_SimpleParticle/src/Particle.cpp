#include "Particle.h"

Particle::Particle()
{
	acceleration = glm::vec3(0, 0, 0);
	velocity= glm::vec3(0, 0, 0);
	position = glm::vec3(0, 0, 0);
	
	radius = 10;
	color = ofColor(0, 200, 100);
}

void Particle::update()
{
	// motion 101
	// acceleration is change of velocity over time
	// velocity is change of position
	velocity += acceleration;
	position += velocity;
}

void Particle::draw()
{
	ofSetColor(color);
	ofDrawCircle(position, radius);
}
