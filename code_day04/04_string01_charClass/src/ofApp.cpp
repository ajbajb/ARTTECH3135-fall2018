#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	str = "THE COOLEST SINCE SLICED BREAD";
	
	ofStringReplace(str, " ", "");
	
	ofLog() << str;
	
	string l = ofToString(str[0]);
	Letter tempLetter;
	tempLetter.setup(l, ofGetMouseX(), ofGetMouseY(), 15);
	
	letters.push_back(tempLetter);
	index++;

}

//--------------------------------------------------------------
void ofApp::update()
{
	for(int i = 0; i < letters.size(); i++)
	{
		letters[i].update();
	}
	
	
}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofBackground(50);
	
	for (auto letter : letters)
	{
		letter.draw();
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
void ofApp::mousePressed(int x, int y, int button)
{
	string l = ofToString(str[index]);
	Letter tempLetter;
	tempLetter.setup(l, x, y, ofRandom(5, 50));
	
	letters.push_back(tempLetter);
	
	index++;
	if (index >= str.size())
	{
		index = 0;
	}

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
