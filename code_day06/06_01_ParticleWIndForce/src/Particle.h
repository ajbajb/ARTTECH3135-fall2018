#pragma once

#include "ofMain.h"

class Particle
{
public:
	
	Particle();
	
	void applyForce(glm::vec3 force);
	void update();
	void draw();
	
	glm::vec3 acceleration;	  // the rate of change of velocity- m & d
	glm::vec3 velocity;		 // the rate of change of location
	glm::vec3 position;
	
	float radius;
	float topSpeed;
	ofColor color;
};
