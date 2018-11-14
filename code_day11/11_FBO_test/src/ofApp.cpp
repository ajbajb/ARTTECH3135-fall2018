#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    // load two images
    
    backgroundImg.load("squash.jpg");
    foregroundImg.load("kandp.jpg");
    
    width = backgroundImg.getWidth();
    height = backgroundImg.getHeight();
    
    foregroundImg.resize(width, height);
    
    // load a greyscale mask
    maskFbo.allocate(width, height, GL_RGBA);
    
    maskFbo.begin();
    ofClear(0, 0, 0, 0);
    maskFbo.end();
    
    bBrushDown = false;

}

//--------------------------------------------------------------
void ofApp::update()
{
    if (bBrushDown)
    {
        ofSetColor(255);
        maskFbo.begin();
        
        int brushSize = 25;
        int brushX = mouseX - brushSize * 0.5;
        int brushY = mouseY - brushSize * 0.5;
        
        ofFill();
        ofDrawCircle(brushX, brushY, brushSize);
        
        maskFbo.end();
    }
    
    // apply mask to foreground image
    foregroundImg.getTexture().setAlphaMask(maskFbo.getTexture());

}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofBackground(0);
    
    // draw background image
    backgroundImg.draw(0, 0);
    
    // draw foreground image, see image 2 through mask of 1
    foregroundImg.draw(0, 0);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    if (key == ' ')
    {
        maskFbo.begin();
        ofClear(0, 0, 0, 0);
        maskFbo.end();
        
        ofLog() << "CLEAR!";
    }

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
void ofApp::mousePressed(int x, int y, int button)
{
    bBrushDown = true;

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
    bBrushDown = false;

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
