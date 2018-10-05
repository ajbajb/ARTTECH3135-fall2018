#pragma once

#include "ofMain.h"

class Particle {
public:
	Particle();
	~Particle();
	
	void update();
	void draw();
	
	glm::vec2 position;
	glm::vec2 velocity;
	glm::vec2 acceleration;
	glm::vec2 mouseForce;
	float drag = 0.5;
	
	int radius;
	ofColor c;
};
