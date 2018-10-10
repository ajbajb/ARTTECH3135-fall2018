#include "ofApp.h"
// NET force equals mass times acceleration
// drag force = (velocity * velocity) * dragCo * (velocity.normalized) * -1
// gravity force =
// ( gravityCo * mass1 * mass2 / (distance * diastance) ) * normralized(attractor position - particle position)
//--------------------------------------------------------------
void ofApp::setup()
{
	img.load("Fairytale.jpg");
	
	for (int i =0; i < 200; i++)
	{
		Particle p;
		p.position = glm::vec3(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), 0);
		p.velocity = glm::vec3(0.0, 0.01, 0);
		p.color = ofColor(255, ofRandom(50, 200));
		p.radius = ofRandom(2, 4);
			
		particles.push_back(p);
	}
}

//--------------------------------------------------------------
void ofApp::update()
{
	glm::vec3 mousePos(ofGetMouseX(), ofGetMouseY(), 0);
	
	for (auto& p : particles)
	{
		float dragCo = 0.25;
		glm::vec3 dragMagnitude = (p.velocity * p.velocity) * dragCo;
		glm::vec3 dragDirection = glm::normalize(p.velocity) * -1;
		glm::vec3 drag = dragMagnitude * dragDirection;
		
		glm::vec3 gravityForce = computeGravity(p, mousePos);
		
		if (ofGetMousePressed())
		{
			p.applyForce(gravityForce);
		}
		
		p.applyForce(drag);
		p.update();
		p.checkWalls();
	}
}

glm::vec3 ofApp::computeGravity(Particle &part, glm::vec3 attractor)
{
	float gravityConst = 10;
	
	// get the direction (normalized vector) form particle to attractor
	glm::vec3 direction = glm::normalize(attractor - part.position) * -1; // for repulsion just reverse the direction
	
	// get the distance from attractor to particle
	float distance = glm::distance(attractor, part.position);
	distance = ofClamp(distance, 2, 500);
//	// or
//	// mapping instead of clamping
//	distance = ofMap(distance, 0, 1000, 1, 0.0, true); // try different values for odd behavior
	
	// compute the magnitude of the force using the mass of the particle and gravity constant
	float magnitude = (gravityConst * part.mass) / (distance * distance);
	
//	// or
//	// map the magnitude instead of the distance
//	magnitude = ofMap(magnitude, 0, 100, 0, 1000, true);
	
//	// or
//	// we can throw away the gravity equasion and just set magnitude more directly to distance
//	float magnitude = ofMap(distance, 0, 100, 0.2, 0, true) * gravityConst;
	
	// force is always direction and magnitude
	glm::vec3 gravity = direction * magnitude;

	return gravity;
}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofBackground(20);
	// ofEnableBlendMode(OF_BLENDMODE_ADD);
	
	for (auto &p : particles)
	{
		p.draw();
	}
	
	string frameStr = "Framrate::" + ofToString(ofGetFrameRate());
	string parts = "Particles::" + ofToString(particles.size());
	ofDrawBitmapString(frameStr, 20, ofGetHeight() - 40);
	ofDrawBitmapString(parts, 20, ofGetHeight() - 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
