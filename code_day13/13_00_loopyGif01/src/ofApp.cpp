#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(0);
    
    int numFrames = 180;
    int frameCount = ofGetFrameNum();
    float t = 1.0 * frameCount / numFrames;

    float noiseScale = 0.004;
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofFill();
    
    float radius = 5;
    float speed = 1.0;
        
    float xPos = radius * cos(TWO_PI * t);
    float yPos = radius * sin(TWO_PI * t);
        
        ofDrawCircle(xPos, yPos, 5);
    
    ofPopMatrix();
    
    std::string tempFilename = "frame_{FRAME_NUMBER}.png";
    if (frameCount <= numFrames)
    {
        auto filename = tempFilename;
        ofStringReplace(filename, "{FRAME_NUMBER}", ofToString(frameCount, 4, '0'));
        ofSaveViewport(filename);
    } else
    {
        ofLog() << "Saved!";
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
