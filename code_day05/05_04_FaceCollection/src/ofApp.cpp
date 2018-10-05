#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofSetCircleResolution(32);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofBackground(0);
	ofSetLineWidth(1);
	
	ofSetColor(255);
	
	glm::vec2 origin(ofGetWidth()/2, ofGetHeight()/2);

	ofPushMatrix();
		ofTranslate(origin);

		// for the back of the face
		for (int i = 1; i < 20; i++)
		{
			int yOffset = i * ofClamp(i*0.4, 1, 8);
			int xOffset = ofClamp(i * i*0.3, 1, 45);
			ofDrawLine(-10 - xOffset, 100-yOffset, 10 + xOffset, 100-yOffset);
		}

		// the hair
		ofPushMatrix();
			ofTranslate(-55, -54);

			for (int j = 0; j < 4; j++)
			{
				int hx = j*27;
				for (int i = 0; i < 8; i++)
				{
					int length = i * 3;
					float xOff = ofClamp(i * (i*0.5), 3, 30);
					ofDrawLine(xOff + hx, 0, xOff + hx, -15 - length);
				}
			}
		ofPopMatrix();

		// mouth
		ofPushMatrix();
			ofTranslate(0, 70);

			ofPushStyle();
			ofSetColor(0);
			ofFill();
			ofDrawCircle(0, 0, 23);
			ofPopStyle();

			ofSetColor(255);
			for (int i = 0; i < 4; i++)
			{
				int lx = i * 4;
				ofDrawLine(2 + lx, -20, 2 + lx, 20);
				ofDrawLine(-2 - lx, -20, -2 - lx, 20);
			}
		ofPopMatrix();

		// nose
		ofPushMatrix();
			ofTranslate(0, -30);

			for (int i = 0; i < 3; i++)
			{
				int lx = i * 3;
				ofDrawLine(2 + lx, 0, 2 + lx, 73);
				ofDrawLine(-2 - lx, 0, -2 - lx, 73);
			}
		ofPopMatrix();

		// left eye
		ofPushMatrix();
			ofTranslate(-65, -15);

			ofSetColor(0);
			ofFill();
			ofDrawRectangle(0, 0, 45, 25);

			ofSetColor(255);
			ofNoFill();
			ofDrawRectangle(0, 0, 45, 25);
		ofPopMatrix();

		// right eye
		ofPushMatrix();
			ofTranslate(20, -30);

			ofSetColor(0);
			ofFill();
			ofDrawRectangle(0, 0, 30, 30);

			ofSetColor(255);
			for (int i = 0; i < 8; i++)
			{
				int lx = i * 4;
				ofDrawLine(0 + lx, 0, 0 + lx, 40);
			}
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
