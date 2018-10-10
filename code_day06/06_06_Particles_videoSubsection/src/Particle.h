#pragma once

#include "ofMain.h"

class Particle
{
public:
	
	Particle();
	
	void applyForce(glm::vec3 force);
	void update();
	void draw();
	void checkWalls(glm::vec3 bounds);
	
	glm::vec3 acceleration;
	glm::vec3 velocity;
	glm::vec3 position;
	
	glm::vec3 angularVelocity;
	glm::vec3 angularAcceleration;
	glm::vec3 orientation;
	
	float radius;
	float mass;
	float topSpeed;
	
	ofTexture tex;
	ofRectangle subSection;
	ofColor color;
};
