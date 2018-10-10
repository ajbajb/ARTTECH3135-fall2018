#include "Particle.h"

Particle::Particle()
{
	acceleration = glm::vec3(0, 0, 0);
	velocity= glm::vec3(0, 0, 0);
	position = glm::vec3(0, 0, 0);
	
	radius = 10;
	mass = radius * 0.5;
	topSpeed = 50;
	color = ofColor(0, 200, 100);
}

void Particle::applyForce(glm::vec3 force)
{
	acceleration += (force / mass);  // here, radius * 0 .5 is the objects mass
}

void Particle::update()
{	
	velocity += acceleration;
	velocity = glm::clamp(velocity, -topSpeed, topSpeed);
	position += velocity;
	
	acceleration = {0, 0, 0};
}

void Particle::checkWalls()
{
	// check right
	if (position.x + radius > ofGetWidth())
	{
		velocity.x *= -1;
		position.x = ofGetWidth() - radius;
	}
	
	// check left
	if (position.x - radius < 0)
	{
		velocity.x *= -1;
		position.x = 0 + radius;
	}
	
	// check top
	if (position.y - radius < 0)
	{
		acceleration.y *= -1;
		velocity.y *= -1;
		position.y = 0 + radius;
	}
	
	// check bottom
	if (position.y + radius > ofGetHeight())
	{
		acceleration.y *= -1;
		velocity.y *= -1;
		position.y = ofGetHeight() - radius;
	}
}

void Particle::draw()
{
	ofSetColor(color);
	ofDrawCircle(position, radius);
	// tex.draw(position.x, position.y, radius, radius);
}
