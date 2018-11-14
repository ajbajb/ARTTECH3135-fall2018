#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    backgroundImg.load("squash.jpg");
    popUpImg.load("kandp.jpg");
    
    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);
    
    fbo.begin();
    ofClear(0, 0, 0, 0);
    fbo.end();
    
    prevTime = 0;
}

//--------------------------------------------------------------
void ofApp::update()
{
    currentTime = ofGetElapsedTimeMillis();
    if (currentTime - prevTime > interval)
    {
        timerCompleted();
        prevTime = currentTime;
    }
}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofBackground(0);
    
    backgroundImg.draw(0, 0);
    
    fbo.draw(0, 0);
    
    string currentStr = ofToString(currentTime);
    string prevStr = ofToString(prevTime);

    ofDrawBitmapString(currentStr, 25, 25);
    ofDrawBitmapString(prevStr, 25, 40);
    
}
//--------------------------------------
void ofApp::timerCompleted()
{
    ofLog() << "Time reached!";
    
    int xpos = ofRandom(ofGetWidth());
    int ypos = ofRandom(ofGetHeight());
    
    fbo.begin();
    popUpImg.draw(xpos, ypos, 100, 100);
    fbo.end();
    
    
    
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
