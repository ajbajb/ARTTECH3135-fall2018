#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofSetCircleResolution(32);
	
	for (int i = 0; i < 20; i++)
	{
		Particle p;
		p.velocity = glm::vec3(3, 0, 0);
		p.position = glm::vec3(ofGetWidth()/2, ofGetHeight()/2, 0);
		p.color = ofColor(0, ofRandom(100, 255), 150);
		p.radius = (ofRandom(2, 15));
		p.acceleration.y = 2 - (p.radius * 0.1);
		
		particles.push_back(p);
	}
}

//--------------------------------------------------------------
void ofApp::update()
{
	for (auto& p : particles)
	{
		p.update();
	
	// check right wall
		if (p.position.x + p.radius > ofGetWidth())
		{
			p.velocity.x *= -1;
			p.position.x = ofGetWidth() - p.radius;
		}

	// check left wall
		if (p.position.x - p.radius < 0)
		{
			p.velocity.x *= -1;
			p.position.x = 0 + p.radius;
		}
	
		// check top wall
		if (p.position.y + p.radius < 0)
		{
			p.velocity.y *= -1;
			p.position.y = 0+ p.radius;
		}
	
		// check bottom wall
		if (p.position.y - p.radius > ofGetHeight())
		{
			p.velocity.y *= -1;
			p.position.y = ofGetHeight() - p.radius;
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofBackground(50);
	
	for (auto p : particles)
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
