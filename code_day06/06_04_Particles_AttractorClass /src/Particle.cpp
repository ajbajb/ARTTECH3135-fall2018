#include "Particle.h"

Particle::Particle()
{
	acceleration = glm::vec3(0, 0, 0);
	velocity= glm::vec3(0, 0, 0);
	position = glm::vec3(0, 0, 0);
	
	radius = 10;
	mass = radius * 0.5;
	topSpeed = 40;
	color = ofColor(0, 200, 100);
}

void Particle::applyForce(glm::vec3 force)
{
	acceleration += force / mass;  // here, radius * 0 .5 is the objects mass
}

void Particle::update()
{	
	velocity += acceleration;
	velocity = glm::clamp(velocity, -topSpeed, topSpeed);
	position += velocity;
	
	acceleration = {0, 0, 0};
}

void Particle::draw()
{
	ofSetColor(color);
	ofDrawSphere(position, radius);
}

void Particle::checkWalls(glm::vec3 bounds)
{
	// check x
	if (position.x + radius > bounds.x / 2)
	{
		acceleration.x *= -1;
		velocity.x *= -1;
		position.x = bounds.x /2 - radius;
	}
	else if (position.x - radius < -bounds.x / 2)
	{
		acceleration.x *= -1;
		velocity.x *= -1;
		position.x = -bounds.x / 2 + radius;
	}
	
	// check Y
	if (position.y + radius > bounds.y / 2)
	{
		acceleration.y *= -1;
		velocity.y *= -1;
		position.y = bounds.y / 2 - radius;
	}
	else if (position.y - radius < -bounds.y / 2)
	{
		acceleration.y *= -1;
		velocity.y *= -1;
		position.y = -bounds.y / 2 + radius;
	}
	
	// check z
	if (position.z + radius > bounds.z / 2)
	{
		acceleration.z *= -1;
		velocity.z *= -1;
		position.z = bounds.z / 2 - radius;
	}
	else if (position.z - radius < -bounds.z / 2)
	{
		acceleration.z *= -1;
		velocity.z *= -1;
		
		position.z = -bounds.z / 2 + radius;
	}
}
