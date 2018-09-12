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
	ofBackground(0);
	
	int original = ofGetMouseY();
	
	float map1 = ofMap(original, 0, ofGetHeight(), 0, 256);
	float map2 = ofMap(original, 0, ofGetHeight(), 256, 2000);
	
	ofSetColor(255, 0, 0);
	ofFill();
	ofDrawRectangle(100, 0, 50, original);
	ofDrawRectangle(400, 0, 50, map1);
	ofDrawRectangle(700, 0, 50, map2);
	
	ofSetColor(255);
	ofDrawLine(0, 256, ofGetWidth(), 256);
	
	string orgStr = "original Value:: \n" + ofToString(original);
	string m1Str = "Mapped smaller range:: \n" + ofToString(map1);
	string m2Str = "Mapped larger range:: \n" + ofToString(map2);
	
	ofDrawBitmapString(orgStr, 150, 20);
	ofDrawBitmapString(m1Str, 450, 20);
	ofDrawBitmapString(m2Str, 750, 20);
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
