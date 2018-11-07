#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    player.load("chomsky1.mp3");
    player.setVolume(0.7);
    if (player.isLoaded())
    {
         player.play();
    }
    
    smoothedFft.assign(nBands, 0);
    
    ofLog() << nBands;
    
    float rotate= 360 / float(nBands);
    
    ofLog() << rotate;

}

//--------------------------------------------------------------
void ofApp::update()
{
    ofSoundUpdate();
    
    float * fft = ofSoundGetSpectrum(nBands);
    
    for (int i = 0; i < nBands; i++)
    {
        smoothedFft[i] = fft[i];
                             
        // or smooth it out!
        //smoothedFft[i] = 0.92 * (fft[i] + smoothedFft[i]);
        
//         smoothing equation
//         output = ⍶ * ( input - output );
//         where ⍶ is our smoothing constant
    }

}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofBackground(25);
    
    float rotation = 360 / float(nBands/2);
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    
    for (int i = 0; i < nBands/2; i++)
    {
        ofRotateZDeg(rotation);
        
        ofSetColor(200, 200, 0);
        ofDrawRectangle(100, 0, smoothedFft[i]*200, 20);
    }
    
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
