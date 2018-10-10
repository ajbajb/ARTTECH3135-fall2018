#include "Particle.h"

Particle::Particle()
{
	acceleration = glm::vec3(0, 0, 0);
	velocity= glm::vec3(0, 0, 0);
	position = glm::vec3(0, 0, 0);
	
	angularAcceleration = glm::vec3(0, 0, 0);
	angularVelocity = glm::vec3(0, 0, 0);
	orientation = glm::vec3(0, 0, 0);
	
	radius = 2;
	mass = radius * 0.5;
	topSpeed = 20;
	
	color = ofColor(0, 200, 100);
}

void Particle::applyForce(glm::vec3 force)
{
	acceleration += force / mass;  // here, radius * 0 .5 is the objects mass
}

void Particle::update()
{
	angularVelocity += angularAcceleration;
	angularVelocity = glm::clamp(angularVelocity, -topSpeed, topSpeed);
	orientation += angularVelocity;
	
	angularAcceleration = {0, 0, 0};
	
	velocity += acceleration;
	velocity = glm::clamp(velocity, -topSpeed, topSpeed);
	position += velocity;
	
	acceleration = {0, 0, 0};
}

void Particle::draw()
{
	ofPushMatrix();
		ofTranslate(position);
		ofRotateXDeg(orientation.x);
		ofRotateYDeg(orientation.y);
		ofRotateZDeg(orientation.z);
	
		//create a rectangle that is same dimentions as the subsection
		ofRectangle drawBounds(0, 0, subSection.width, subSection.height);
		tex.drawSubsection(drawBounds, subSection);
	ofPopMatrix();
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
