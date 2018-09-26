#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	text.load("/Library/Fonts/Arial.ttf", 15);
	
	sentences = ofSplitString(ofBufferFromFile("if.txt").getText(), ".");
	
	maxi = sentences.size();
	
	for (auto sentence : sentences)
	{
		ofLog() << sentence;
	}

	displayStr = sentences[0];
}

//--------------------------------------------------------------
void ofApp::update()
{
	xPos += speed * -1;
	
	
	// get the size of the rectangle that out text takes up
	ofRectangle boundingRect = text.getStringBoundingBox(displayStr, xPos, yPos);
	
	// the rectangle has and x.y position and a width/height
	ofLog() << boundingRect.x << " " << boundingRect.y << " "
			<< boundingRect.width << " " << boundingRect.height;
	
	// check if we scroll off the screen
	float furthestDistance = -boundingRect.width;
	
	// if our xPos gets to this point.
	// put it back to the starting point (ofGetWidth())
	if (xPos <= furthestDistance)
	{
		xPos = ofGetWidth();
		
		int index = ofRandom(maxi);
		displayStr = sentences[index];
		
		yPos = ofRandom(ofGetHeight());
	}
}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofBackground(30);
	
	ofSetColor(0, 190, 90);
	ofFill();
	text.drawString(displayStr, xPos, yPos);
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
