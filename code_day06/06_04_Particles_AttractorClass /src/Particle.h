#pragma once

#include "ofMain.h"

class Particle
{
public:
	
	Particle();
	
	void applyForce(glm::vec3 force);
	void update();
	void checkWalls(glm::vec3 bounds);
	void draw();
	
	glm::vec3 acceleration;	  // the rate of change of velocity. Has magnitude AND direction
	glm::vec3 velocity;		 // the rate of change of position
	glm::vec3 position;		// the position of the object
	
	float radius;
	float mass;
	float topSpeed;
	ofColor color;
};
