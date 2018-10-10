#pragma once

#include "ofMain.h"

class Particle
{
public:
	
	Particle();
	
	void update();
	void draw();
	
	glm::vec3 acceleration;
	glm::vec3 velocity;
	glm::vec3 position;
	
	float radius;
	ofColor color;
};
