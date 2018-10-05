#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	const int numBalls = 1000;
	
	b1.px = ofGetWidth()/2;
	b1.py = ofGetHeight()/2;
	
	b2.px = ofGetWidth() - 100;
	b2.py = ofGetHeight() - 100;
	
	for (int i = 0; i < numBalls; i++)
	{
		Ball tempBall;
		tempBall.radius = ofRandom(3, 10);
		tempBall.px = ofRandom(30, ofGetWidth());
		tempBall.py = ofRandom(30, ofGetHeight());
		tempBall.ax = -ofRandom(0.05, 0.09);
		tempBall.ay = -ofRandom(0.05, 0.09);
		
		balls.push_back(tempBall);
	}
}

//--------------------------------------------------------------
void ofApp::update()
{
	b1.update();
	b2.update();
	
	for (int i = 0; i < balls.size(); i++)
	{
		
		balls[i].update();
	}

}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofBackgroundGradient(ofColor::yellow, ofColor::blueViolet, OF_GRADIENT_CIRCULAR);
	
	b1.draw();
	b2.draw();
	
	for (int i = 0; i < balls.size(); i++)
	{
		balls[i].draw();
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
