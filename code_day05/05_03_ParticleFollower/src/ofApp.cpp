#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofBlendMode(OF_BLENDMODE_ADD);
	ofSetCircleResolution(36);
	
	const int NUM = 1000;
	
	for (int i = 0; i < NUM; i++)
	{
		Particle p;
		p.position.x = ofRandom(ofGetWidth());
		p.position.y = ofRandom(ofGetHeight());
		p.acceleration.x = 0.1;
		p.velocity.x = ofRandom(-2, 2);
		p.velocity.y = ofRandom(-3, 3);
		p.drag = ofRandom(0.3, 0.95);
		
		p.c = ofColor(ofColor::fromHsb(ofRandom(255), 255, 255), ofRandom(50, 150));
		p.radius = ofRandom(1, 10);
		
		particles.push_back(p);
	}

}

//--------------------------------------------------------------
void ofApp::update()
{
	glm::vec2 mousePos(ofGetMouseX(), ofGetMouseY());
	
	int forceDirection = -1;
	if (ofGetMousePressed())
	{
		forceDirection = 10;
	}
	else
	{
		forceDirection = -1;
	}
	
	for (auto& p : particles)
	{
		// the mouse position will excert a force on our particles
		// the farther away, the stronger the attraction force
		// if you press your mouse, the force reverses, repelling
		//
		// get the particle position with p.position
		
		// get the distance from the particles current position
		// and the mouse position
		float distance = glm::distance(mousePos, p.position);
		
		// use the distance as the magnitude for the force
		float forceScale = 0.04;
		float magnitude = distance * forceScale * forceDirection;
		
		// get the direction of where the force is strongest
		glm::vec2 direction = glm::normalize(p.position - mousePos);
		
		// the force
		glm::vec2 force = magnitude * direction;
		
		p.acceleration.x = ofRandom(0.05, 0.1);
		p.mouseForce += force;
		
		p.update();
	}

}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofBackground(0);
	
	for (auto& p : particles)
	{
		p.draw();
	}

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
