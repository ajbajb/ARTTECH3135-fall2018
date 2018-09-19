#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update()
{
	float time = ofGetElapsedTimef();
	float freq = 0.8;
	
	// will give me a # between -1, 1
//	sinFunc = sin(time * freq);
	
	// map the current range sinFunc is in
	// to another range ex. 0 - 200
//	sinFunc = ofMap(sinFunc, -1, 1, 0, ofGetHeight());
	
	sinFunc = ofGetHeight()/2 + ofGetHeight()/2 * sin(time * freq);
	
	ofLog() << sinFunc;
}
//--------------------------------------------------------
void ofApp::draw()
{
	ofBackground(50);
	
	ofSetColor(255);
	ofDrawCircle(ofGetWidth()/2, sinFunc, 10);
}













