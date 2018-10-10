#pragma once

#include "ofMain.h"

class Particle3D
{
public:
	Particle3D();
	
	void update();
	void draw();
	void applyForce(glm::vec3 force);
	void applyDrag(float dragCo);
	void checkBounds(glm::vec3 bounds);
	
	glm::vec3 angularAcceleration;
	glm::vec3 angularVelocity;
	glm::vec3 orientation;
	
	glm::vec3 acceleration;
	glm::vec3 velocity;
	glm::vec3 position;
	
	float size;
	float mass;
	float topSpeed;
	
	ofTexture texture;
	ofColor color;
	
};
