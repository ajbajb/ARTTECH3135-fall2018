#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	grabber.setDeviceID(0);
	grabber.setup(640, 480);
	
	int rows = 64;
	int columns = 48;
	int sectionWidth = grabber.getWidth() / rows;
	int sectionHeight = grabber.getHeight() / columns;
	
	int numParticles = rows * columns;
	
	for (int y = 0; y < grabber.getHeight(); y += sectionHeight)
	{
		for (int x = 0; x < grabber.getWidth(); x += sectionWidth)
		{
			ofRectangle sub(x, y, sectionWidth, sectionHeight);
			
			Particle p;
			p.position = {x, y, 0};
			p.tex = grabber.getTexture();
			p.subSection = sub;
			
			particles.push_back(p);
		}
	}
	
	boundingRect = {ofGetWidth(), ofGetHeight(), 500};
	cam.setScale(1, -1, 1);

}

//--------------------------------------------------------------
void ofApp::update()
{
	grabber.update();
	
	glm::vec3 mouse(ofGetMouseX(), ofGetMouseY(), 0);
	
	for (auto& p : particles)
	{
		p.tex = grabber.getTexture();
		p.update();
	}
}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofBackground(0);
	
	cam.begin();
	ofEnableDepthTest();
	
	ofPushMatrix();
		ofTranslate(-grabber.getWidth()/2, -grabber.getHeight()/2);
		for (auto& p : particles)
		{
			p.draw();
		}
	ofPopMatrix();
	
	cam.end();
	
	ofPushStyle();
	ofSetColor(255);
	string frameStr = "Framerate: " + ofToString(ofGetFrameRate());
	string pStr = "Particles:: " + ofToString(particles.size());
	ofDrawBitmapString(frameStr, 20, ofGetHeight() - 40);
	ofDrawBitmapString(pStr, 20, ofGetHeight() - 20);
	ofPopStyle();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	if (key == ' ')
	{
		for (auto &p : particles)
		{
			p.angularAcceleration = {ofRandom(-0.1, 0.1), ofRandom(-0.1, 0.1), ofRandom(-0.1, 0.1)};
			p.acceleration = {ofRandom(-0.1, 0.1), ofRandom(-0.1, 0.1), ofRandom(-0.1, 0.1)};
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
