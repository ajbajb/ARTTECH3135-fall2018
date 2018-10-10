#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	cam.setScale(1, -1, 1);
	
	boundingBox = {500, 500, 500};
	aForce = glm::vec3(0., 0., 0.);
	
	for (int i = 0; i < 50; i++)
	{
		Particle3D p;
		p.applyForce(aForce);
		particles.push_back(p);
	}
}

//--------------------------------------------------------------
void ofApp::update()
{
	for (auto &p : particles)
	{
		p.applyDrag(globalDrag);
		p.update();
		p.checkBounds(boundingBox);
	}
}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofBackground(20);
	
	cam.begin();
	for (auto &p : particles)
	{
		p.draw();
	}
	
	if (bDrawDebug)
	{
		ofDrawAxis(550);
		ofPushStyle();
		ofSetColor(255, 0, 0, 25);
		ofDrawBox(boundingBox.x, boundingBox.y, boundingBox.z);
		ofPopStyle();
	}
	
	cam.end();
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	if (key == 'd')
	{
		bDrawDebug =! bDrawDebug;
	}
	
	if (key == 'f')
	{
		for (auto &p : particles)
		{
			aForce.x = ofRandom(-10, 10);
			aForce.y = ofRandom(-10, 10);
			aForce.z = ofRandom(-10, 10);
			p.applyForce(aForce);
		}
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
