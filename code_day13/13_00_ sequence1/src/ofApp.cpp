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
    ofSetCircleResolution(32);
    
    float t = ofGetElapsedTimef();
    int num = ofGetHeight();
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, 0);
    
    ofFill();
    for (int i = 0; i < num; i++)
    {
        float radius = 500;
        float sizeScaler = num/2 + num/2 * cos(t * i * 0.002);
        float size = ofMap(sizeScaler, 0, num, 250, 2);
        
        float xPos = i * sin(t * 2);
        float yPos =  i;
        
        float r = 127 + 127 * sin(t * (0.004*i));
        float g = 127 + 127 * sin(t * (0.002*i));
        float b = 127 + 127 * sin(t * (0.003*i));
        
        ofSetColor(r,g,b);
        ofDrawCircle(xPos, yPos, size);
    }
    
    ofPopMatrix();
    
//    int frameCount = ofGetFrameNum();
//    std::string tempFilename = "frame_{FRAME_NUMBER}.png";
//    auto filename = tempFilename;
//    ofStringReplace(filename, "{FRAME_NUMBER}", ofToString(frameCount, 4, '0'));
//    ofSaveViewport(filename);

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
