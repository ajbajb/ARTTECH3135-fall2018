#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	// get
	sentences = ofSplitString(ofBufferFromFile("if.txt").getText(), ".");
	
	for (auto sentence : sentences)
	{
		ofLog() << sentence;
	}
	
	Scroll tempScroll;															// create a temporary object
	tempScroll.setup(sentences[0], ofGetWidth()/2, ofRandom(ofGetHeight()) );  // set it up
	myScrolls.push_back(tempScroll); 										  // add it to our scroll array
}

//--------------------------------------------------------------
void ofApp::update()
{
	for (std::size_t i = 0; i < myScrolls.size(); i++)
	{
		myScrolls[i].update();
	}
}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofBackground(50);
	
	for (auto scroll : myScrolls)
	{
		scroll.draw();
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
	int index = ofRandom(1, sentences.size());
	
	Scroll tempScroll;
	tempScroll.setup(sentences[index], x, y);
	
	myScrolls.push_back(tempScroll);
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
