#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	p.position = glm::vec3(200, 0, 0);
	p.acceleration = glm::vec3(0.0, 0.0, 0);	
}

//--------------------------------------------------------------
void ofApp::update()
{
	glm::vec3 persistForce(0.05, 0.03, 0);
	glm::vec3 windForce(0, 0, 0);
	
	if (ofGetMousePressed())
	{
		bWind = true;
		windForce = glm::vec3(-0.45, -0.09, 0);
		p.applyForce(windForce);
	}
	
	p.applyForce(persistForce);
	
	checkWalls(p);
	p.update();
	
	ofLog() << "accel= " << p.acceleration;
	ofLog() << "velo= " << p.velocity;
}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofBackground(40);
	
	p.draw();
	
	if(bWind)
	{
		ofPushStyle();
		ofSetColor(255, 0, 255);
		
		ofDrawBitmapString("WIND!!!!!", ofGetWidth()/2, ofGetHeight()/2);
		ofPopStyle();
	}
	
	bWind = false;
}

void ofApp::checkWalls(Particle &pref)
{
	// check right
	if (pref.position.x + pref.radius > ofGetWidth())
	{
		pref.velocity.x *= -1;
		pref.position.x = ofGetWidth() - pref.radius;
	}
	
	// check left
	if (pref.position.x - pref.radius < 0)
	{
		pref.velocity.x *= -1;
		pref.position.x = 0 + pref.radius;
	}
	
	// check top
	if (pref.position.y - pref.radius < 0)
	{
		pref.acceleration.y *= -1;
		pref.velocity.y *= -1;
		pref.position.y = 0 + pref.radius;
	}
	
	// check bottom
	if (pref.position.y + pref.radius > ofGetHeight())
	{
		pref.acceleration.y *= -1;
		pref.velocity.y *= -1;
		pref.position.y = ofGetHeight() - pref.radius;
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
