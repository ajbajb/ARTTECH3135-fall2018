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
	ofBackground(50);
	
	// get the minutes, seconds, hours!
	int seconds = ofGetSeconds();
	int minutes = ofGetMinutes();
	int hours = ofGetHours(); // hours is in 24hour time
	
	//map those numbers to a rotation
	
	float sDegree = ofMap(seconds, 0, 60, 0, 360);
	float mDegree = ofMap(minutes , 0, 60, 0, 360);
	float hDegree = ofMap(hours, 0, 24, 0, 720);
	
	//great now we have our rotation amounts
	
	ofPushMatrix();
	// translate to the middle of the screen
	ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
	ofRotateZDeg(180);

		ofPushMatrix(); //draw the second hand it its own matrix
			// drawing the second hand, use sDegree
			ofRotateZDeg(sDegree);

			ofSetLineWidth(1);
			ofSetColor(ofColor::red);
			ofDrawLine(0, 0, 0, 300);
		ofPopMatrix();  // "pop" off the second matrix

		// draw the minute hand
		ofPushMatrix(); //push the "minute" matrix on
			ofRotateZDeg(mDegree);

			ofSetColor(ofColor::purple);
			ofSetLineWidth(3);
			ofDrawLine(0, 0, 0, 250);
		ofPopMatrix();
	
		// Draw the hour hand
		ofPushMatrix(); // "push on the hour Matrix
			ofRotateZDeg(hDegree); // rotate it by hDegree
	
			ofSetColor(ofColor::white);
			ofSetLineWidth(5);
			ofDrawLine(0, 0, 0, 100);
		ofPopMatrix();

	ofPopMatrix();

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
