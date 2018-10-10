#pragma once

#include "ofMain.h"

class Particle
{
public:
	
	Particle();
	
	void applyForce(glm::vec3 force);
	void update();
	void checkWalls();
	void draw();
	
	glm::vec3 acceleration;
	glm::vec3 velocity;
	glm::vec3 position;
	
	float radius;
	float mass;
	float topSpeed;
	ofColor color;
	
	ofTexture tex;
};
