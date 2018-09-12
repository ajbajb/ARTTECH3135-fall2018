#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofSetRectMode(OF_RECTMODE_CENTER);
	rotation = 0;

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofBackground(0);
	
	ofSetColor(255);
	ofNoFill();
	
	rotation = rotation + 1;
	
	for(int i = 0; i < 8; i++)
	{
			//	// "pushed another co-ordinate system on top of out current one
		ofPushMatrix();
	
			//move the co-ordinate system 100 pix to the right, 300 pix down
			// (normal orintation of computer screen)
			ofTranslate(100*i, 300);
			ofRotateZDeg(rotation);
			ofDrawRectangle(0, 0, 100, 100);
	
		// Will "pop" of the co-ordinate system
		ofPopMatrix();
	}
	
	// if rotation hits 360, set it back to 0
	if(rotation > 360)
	{
		rotation = 0;
	}
	
//	// "pushed another co-ordinate system on top of out current one
//	ofPushMatrix();
//
//		//move the co-ordinate system 100 pix to the right, 300 pix down
//		// (normal orintation of computer screen)
//		ofTranslate(100, 300);
//		ofRotateZDeg(30);
//		ofDrawRectangle(0, 0, 100, 100);
//
//	// Will "pop" of the co-ordinate system
//	ofPopMatrix();

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
