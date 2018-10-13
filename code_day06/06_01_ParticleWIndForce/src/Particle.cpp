#include "Particle.h"

Particle::Particle()
{
	acceleration = glm::vec3(0, 0, 0);
	velocity= glm::vec3(0, 0, 0);
	position = glm::vec3(0, 0, 0);
	
	radius = 10;
	topSpeed = 10;
	color = ofColor(0, 200, 100);
}

void Particle::applyForce(glm::vec3 force)
{
	// add force to acceleration
	acceleration += force / (radius * 0.5);
}

void Particle::update()
{
	velocity += acceleration;
	velocity = glm::clamp(velocity, -topSpeed, topSpeed);
	position += velocity;
	
	acceleration = {0, 0, 0};  // make sure to clear acceleration!
}

void Particle::draw()
{
	ofSetColor(color);
	ofDrawCircle(position, radius);
}
