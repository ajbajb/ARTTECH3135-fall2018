#include "ofApp.h"
// NET force equals mass times acceleration
// drag force = (velocity * velocity) * dragCo * (velocity.normalized) * -1
// gravity force =
// ( gravityCo * mass1 * mass2 / (distance * diastance) ) * normralized(attractor position - particle position)
//--------------------------------------------------------------
void ofApp::setup()
{
	cam.setScale(1, -1, 1);
	
	// width, height, depth of bounding cube
	boundingSize = {1000, 1000, 1000};
	
//	Attractor aa;
//	aa.position = {0, 0, 0};
//	attractors.push_back(aa);
	
	for (int i = 0; i < 10; i++)
	{
		Attractor a;
		a.position = {ofRandom(-500, 500), ofRandom(-500, 500), ofRandom(-500, 500)};
		a.radius = ofRandom(2, 50);
		
		attractors.push_back(a);
	}
	
	for (int i = 0; i < 1000; i++)
	{
		Particle p;
		p.position = {ofRandom(-250, 250), ofRandom(-250, 250), ofRandom(-250, 250)};
		p.velocity = {0.1, 0.1, 0.1};
		p.radius = ofRandom(2, 20);
		p.color = ofColor(255, ofRandom(100), ofRandom(200), 100);
	
		particles.push_back(p);
	}

}

//--------------------------------------------------------------
void ofApp::update()
{
	glm::vec3 mousePos(ofGetMouseX(), ofGetMouseY(), 0);
	
	for (auto &p : particles)
	{
		float dragCo = 0.03;
		glm::vec3 dragMagnitude = (p.velocity * p.velocity) * dragCo;
		glm::vec3 dragDirection = glm::normalize(p.velocity) * -1;
		glm::vec3 drag = dragMagnitude * dragDirection;
		
		for (auto &a : attractors)
		{
			glm::vec3 gravityForce = computeGravity(p, a);
			p.applyForce(gravityForce);
		}

		p.applyForce(drag);
		p.update();
		p.checkWalls(boundingSize);
	}
}

glm::vec3 ofApp::computeGravity(Particle &part, Attractor &attractor)
{
	float gravityConst = 10;
	
	// get the direction (normalized vector) form particle to attractor
	glm::vec3 direction = glm::normalize(attractor.position - part.position) * 1;
	
	// get the distance from attractor to particle
	float distance = glm::distance(attractor.position, part.position);
	distance = ofClamp(distance, 7, 500);

	// compute the magnitude of the force using the mass of the particle and gravity constant
	float magnitude = (gravityConst * part.mass * attractor.mass) / (distance * distance);
		
	// force is always direction and magnitude
	glm::vec3 gravity = direction * magnitude;

	return gravity;
}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofBackground(20);
	// ofEnableBlendMode(OF_BLENDMODE_ADD);
	
	cam.begin();
	
	if (bDrawAttractors)
	{
		for (auto &a: attractors)
		{
			a.draw();
		}
	}
	
	for (auto &p : particles)
	{
		p.draw();
	}
	
	if (bDrawAxis)
	{
		ofDrawAxis(boundingSize.x/2);
		ofPushStyle();
		ofSetColor(255, 50, 50, 25);
		ofDrawBox(boundingSize.x, boundingSize.y, boundingSize.z);
		ofPopStyle();
	}
	
	cam.end();
	
	ofPushStyle();
		ofSetColor(255);
		string frameStr = "Framrate::" + ofToString(ofGetFrameRate());
		string parts = "Particles::" + ofToString(particles.size());
		ofDrawBitmapString(frameStr, 20, ofGetHeight() - 40);
		ofDrawBitmapString(parts, 20, ofGetHeight() - 20);
	ofPopStyle();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	if (key == 'x')
	{
		bDrawAxis =! bDrawAxis;
	}
	
	if (key == 's')
	{
		glm::vec3 mouse(ofGetMouseX() - ofGetWidth()/2, ofGetMouseY() - ofGetHeight()/2, 0);
		
		for (auto &a : attractors)
		{
			a.isInside(mouse);
			ofLog() << "attractor= " << a.position;
		}
		
		ofLog() << "mousePos= "<< mouse;
	}
	
	if (key == 'd')
	{
		bDrawAttractors =! bDrawAttractors;
	}
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
