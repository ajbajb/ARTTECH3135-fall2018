#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw()
{
	// the amount we move though the space (like out "speed")
//	float nIncX = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 0.05, true);
//	float nIncY = ofMap(ofGetMouseY(), 0, ofGetHeight(), 0, 0.05, true);
	
	float time = ofGetElapsedTimef();
	
	float xOff = sin(time * 0.002);
	float yOff = sin(time * 0.003);
	
	// poisiton in out "noise space"
	float noisePosX = 0;
	float noisePosY = 0;
	
	for (int y = 0; y < ofGetHeight(); y += 2)
	{
		for (int x = 0; x < ofGetWidth(); x += 2)
		{
//			noisePosX += nIncX;
//			noisePosY += nIncY;
			
			// ofNoise *always* gives 0 - 1
			float noise = ofNoise(x * xOff, y * yOff);
			
			//multiply noise by 255  = 0 - 255
			float hue = noise * 255;
			ofSetColor(ofColor::fromHsb(hue, 255, 255));
			
			ofDrawRectangle(x, y, 2, 2);
		}
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
