#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	text.load("/Library/Fonts/Arial.ttf", 24);
	
	sentences = ofSplitString(ofBufferFromFile("if.txt"), ".");
	
	for ( auto sentence : sentences)
	{
		ofStringReplace(sentence, ",", "\n");
		ofLog() << sentence;
	}
	
	maxi = sentences.size();

}

//--------------------------------------------------------------
void ofApp::update()
{
	if (ofGetFrameNum() % interval == 0)
	{
		if (maxi > 0)
		{
			// grab the sentence at this index
			int index = ofRandom(maxi);
			
			// replace all the "," with new lines "\n"
			ofStringReplace(sentences[index], ",", "\n");
			
			// that string will be displayed
			displayStr = sentences[index];
			
		}
	}

}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofBackground(25);
	ofSetColor(0, 180, 90);
	ofFill();
	text.drawString(displayStr, 100, 200);
	
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
