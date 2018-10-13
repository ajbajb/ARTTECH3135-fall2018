#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    grabber.setup(640, 480);

}

//--------------------------------------------------------------
void ofApp::update()
{
    grabber.update();

}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofBackground(0);
    float atWidth = ofGetWidth()/2 - grabber.getWidth()/2;
    float atHeight = ofGetHeight()/2 - grabber.getHeight()/2;
    
    grabber.draw(atWidth, atHeight);

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
