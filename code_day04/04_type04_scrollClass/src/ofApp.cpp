#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	// get our sentences from a .txt file in out /bin/data folder
	// split it up on the "." store the result in out sentences vector
	sentences = ofSplitString(ofBufferFromFile("if.txt").getText(), ".");

	// what kind of for look is this?
	for (auto sentence : sentences)
	{
		ofLog() << sentence;
	}

	// add a scroll to start :)
	Scroll tempScroll;		// create a temporary object
	// set it up
	tempScroll.setup(sentences[0], ofGetWidth()/2, ofRandom(ofGetHeight()) );

	// add it to our Scroll array
	myScrolls.push_back(tempScroll);
}

//--------------------------------------------------------------
void ofApp::update()
{
	// update all out Scrolls
	for (std::size_t i = 0; i < myScrolls.size(); i++)
	{
		myScrolls[i].update();
	}
}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofBackground(50);

	// draw all out Scrolls
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
	// when we press our mouse,
	// create a new Scroll object at the mouse x & y position
	//the text will come form our sentences vector
	int index = ofRandom(1, sentences.size());

	// create a temporary Scroll and add it to our Scroll vector
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
