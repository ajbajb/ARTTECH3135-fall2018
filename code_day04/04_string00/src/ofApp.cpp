#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	font.load("/Library/Fonts/Arial.ttf", 15);

	text = "THIS IS A STRING";
	ofLog() << text;
	
//	ofStringReplace(text, " ", "");
//	ofLog() << text;
}

//--------------------------------------------------------------
void ofApp::update()
{

}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofBackground(50);
	
//	ofSetColor(0, 180, 90);
//	ofFill();
//
//	float time = ofGetElapsedTimef();
//	float freq = 1;
//	float maxi = text.size();
//	int index = (int)round(maxi/2 + maxi/2 * sin(time * freq));
//
//
//	int printHeight = ofGetHeight()/2;
//
//	for (int i = text.size()-1; i >= index; i--)
//	{
//		string display = ofToString(text[i]);
//		int lineHeight = font.stringHeight(display);
//		if (lineHeight == 0)
//		{
//			lineHeight = 5;
//		}
//		printHeight -= lineHeight;
//
//		font.drawString(display, ofGetWidth()/2, printHeight);
//	}
	
	// Draw the text
	font.drawString(text, ofGetWidth()/3, ofGetHeight()/3);
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
