#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    // setup our camera
    grabber.setup(640, 480);
    
    //allocate out pixels and texture
    grabberPix.allocate(grabber.getWidth(), grabber.getHeight(), OF_PIXELS_RGB);
    texture.allocate(grabber.getWidth(), grabber.getHeight(), GL_RGB);

}

//--------------------------------------------------------------
void ofApp::update()
{
    float noiseStep = 0.02;
    
    grabber.update();
    
    if (grabber.isFrameNew())
    {
        // get the pixels!
        grabberPix = grabber.getPixels();
        
        // do stuff to the pixels
        for (int x = 0; x < grabberPix.getWidth(); x++)
        {
            for (int y = 0; y < grabberPix.getHeight(); y++)
            {
                // value between 0-1
                float noiseValue = ofNoise((x+ ofGetMouseX()) * noiseStep);
                                // scaling to be 0 - width
                int displacedX = x + (noiseValue * grabberPix.getWidth());
                
                // wrap all the valaues to be between 0 - width
                displacedX = ofWrap(displacedX, 0, grabberPix.getWidth());
                
                // we want the color from the original pixels
                ofColor displacedColor = grabber.getPixels().getColor(displacedX, y);
                
                // we set our current pixel to that displacedColor
                grabberPix.setColor(x, y, displacedColor);
            }
        }
    }
    
    texture.loadData(grabberPix);
}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofBackground(0);
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2 + grabber.getWidth()/2, ofGetHeight()/2 - grabber.getWidth()/2);
    
    // flip the camera
    ofScale(-1, 1, 1);
    // grabber.draw(0, 0);
    texture.draw(0, 0);
    
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
