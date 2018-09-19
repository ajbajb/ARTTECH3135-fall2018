#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofBackground(50);
	//ofSetBackgroundAuto(false);

}

float sinFunc(float speed, float magnitude, float offset)
{
	
	float time = ofGetElapsedTimef();
	
	float s = magnitude * sin(time * (speed + offset));
	return s;
}

//--------------------------------------------------------------
void ofApp::update()
{
//	float clearTime = ofGetElapsedTimeMillis();
//
//	if(clearTime - prevTime > clearInterval)
//	{
//		ofClear(50);
//		ofLog() << "clear!";
//		prevTime = clearTime;
//		line.clear();
//	}
	
	if( points.size() > MAX_SIZE)
	{
		points.erase(points.begin());
		
	}
	
	xPos = sinFunc(2.3, 400, 0);
	yPos = sinFunc( 5, 200, 0.2);
	
	glm::vec3 point(xPos, yPos, 0);
	points.push_back(point);
	
	line.clear();
	line.addVertices(points);

}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofPushMatrix();
	ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
	
	ofSetColor(120, 0, 200);
	ofSetLineWidth(ofMap(ofGetMouseX(), 0, ofGetWidth(), 1, 15, true));
	line.draw();
	ofPopMatrix();
	
	ofLog() << line.size();
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
