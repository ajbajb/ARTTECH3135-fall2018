#include "Particle3D.h"

Particle3D::Particle3D()
{
	angularAcceleration = glm::vec3(0, 0, 0);
	angularVelocity = glm::vec3(0, 0, 0);
	orientation = glm::vec3(0, 0, 0);
	
	acceleration = glm::vec3(0, 0, 0);
	velocity = glm::vec3(0, 0, 0);
	position = glm::vec3(0, 0, 0);
	
	size = 10;
	mass = size * 0.2;
	topSpeed = 10;
	
	color = ofColor(255);
}

void Particle3D::applyForce(glm::vec3 force)
{
	acceleration += (force / mass);
	angularAcceleration += (force / mass);
}

void Particle3D::applyDrag(float dragCo)
{
	// dragforce = (velocity * velocity) * dragCo * (velocity.normalized * -1)
	glm::vec3 dragMagnitude = (velocity * velocity) * dragCo;
	glm::vec3 dragDirection = glm::normalize(velocity) * -1;
	glm::vec3 drag = dragMagnitude * dragDirection;
	
	acceleration += (drag / mass);
	angularAcceleration += (drag / mass);
}

void Particle3D::update()
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

void Particle3D::draw()
{
	ofPushMatrix();
	ofTranslate(position);
	ofRotateXDeg(orientation.x);
	ofRotateYDeg(orientation.y);
	ofRotateZDeg(orientation.z);
	
	ofSetColor(color);
	// texture.draw(0-size/2, 0-size/2, size, size);
	
	ofDrawBox(size);
	ofDrawAxis(size);
	
	ofPopMatrix();
}

void Particle3D::checkBounds(glm::vec3 bounds)
{
	// checkX
	if (position.x + size > bounds.x / 2)
	{
		velocity.x *= -1;
		position.x = bounds.x / 2 - size;
	}
	else if (position.x - size < -bounds.x / 2)
	{
		velocity.x *= -1;
		position.x = -bounds.x / 2 + size;
	}
	
	// checkY
	if (position.y + size > bounds.y / 2)
	{
		velocity.z *= -1;
		position.y = bounds.y / 2 - size;
	}
	else if (position.y - size < -bounds.y / 2)
	{
		velocity.z *= -1;
		position.y = -bounds.y / 2 + size;
	}
	
	// checkZ
	if (position.z + size > bounds.z / 2)
	{
		velocity.z *= -1;
		position.z = bounds.z / 2 - size;
	}
	else if (position.z - size < -bounds.z / 2)
	{
		velocity.z *= -1;
		position.z = -bounds.z / 2 + size;
	}
}
