#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update()
{


}

//--------------------------------------------------------------
void ofApp::draw()
{
	float nInc = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 0.5);
	float noisePos = 0;
	
	// for loop
	for (int i = 0; i < ofGetWidth(); i++)
	{
		noisePos += nInc;
		
		// ofNoise gives us a value 0 - 1
		float noise = ofNoise(noisePos);
		
		float hue = ofMap(noise, 0, 1, 0, 255);
		ofSetColor(ofColor::fromHsb(hue, 255, 255));
		
		ofDrawLine(i, 0, i, ofGetHeight());
		
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
