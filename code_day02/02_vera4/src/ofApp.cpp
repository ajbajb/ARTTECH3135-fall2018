#include "ofApp.h"

//---Vera-Molnar-Iterruptions-1968/69---------------------------
void ofApp::setup()
{
	ofBackground(255);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw()
{
	int border = 50;
	int drawingWidth = ofGetWidth() - border;
	int drawingHeight = ofGetHeight() - border;
	
	ofSetColor(0);
	
	ofSeedRandom(2);
	int lineSize = 20;
	
	for(int y=border; y<=drawingHeight; y+=lineSize-8)
	{
		for(int x=border; x<=drawingWidth; x+=lineSize-8)
		{
			float randomAngle = ofRandom(-180, 180);
			
			ofPushMatrix();
			ofTranslate(x, y);
			
			ofRotateZDeg(randomAngle);
			
			if(ofNoise(x*0.01, y*0.01, ofGetMouseX()) < 0.75)
			{
				ofDrawLine(0-10,0, 0+10, 0);
			}
			ofPopMatrix();
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
