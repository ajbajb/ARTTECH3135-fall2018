#pragma once

#include "ofMain.h"

class Attractor
{
public:
	
	Attractor();
	
	void update();
	void checkWalls();
	void isInside(glm::vec3 mouser);
	void draw();
	
	glm::vec3 acceleration;	  // the rate of change of velocity. Has magnitude AND direction
	glm::vec3 velocity;		 // the rate of change of position
	glm::vec3 position;		// the position of the object
	
	float radius;
	float mass;
	float topSpeed;
	
	ofColor color;
};
