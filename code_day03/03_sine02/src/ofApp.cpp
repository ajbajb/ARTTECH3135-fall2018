#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofBackground(50);
	ofSetBackgroundAuto(false);

}

//--------------------------------------------------------------
void ofApp::update()
{
	float time = ofGetElapsedTimef();
	
	float xFreq = 1;
	float yFreq = 2.3;
	
	float offset = 2;

	float sinValueX = sin(time * xFreq);
	xPos = ofMap(sinValueX, -1, 1, 50, ofGetWidth() - 50);
	
	float sinValueY = sin(time * yFreq + offset);
	yPos = ofMap(sinValueY, -1, 1, 50, ofGetHeight() - 50);
	
	float circleInc = ofRandom(-1, 1);
	
	circleSize += circleInc;
	
	if(circleSize > ofGetWidth()/2 || circleSize < -ofGetWidth()/2)
	{
		circleSize = 0;
		
	}
	
	if (ofGetFrameNum()%1000 == 0)
	{
		ofClear(50);
	}
	
}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofSetColor(ofColor::hotPink);
	ofFill();
	
	// SO this last value is size
	ofDrawCircle(xPos, yPos, circleSize);

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
