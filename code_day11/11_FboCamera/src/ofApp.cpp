#include "ofApp.h"

//--------------------------------------------------------------
// mask:
// 255 will be opaque
// 0 will be transparent
void ofApp::setup()
{
    grabber.setup(640, 480);
    
    width = grabber.getWidth();
    height = grabber.getHeight();
    
    grayscalePix.allocate(width, height, OF_PIXELS_GRAY);
    grayscaleTex.allocate(width, height, GL_RGB);
    grabberCopy.allocate(width, height, GL_RGB);
    
    // load two images
    foreground.load("kandp.jpg");
    foreground.resize(width, height);
    
    background.load("squash.jpg");
    background.resize(width, height);
}

//--------------------------------------------------------------
void ofApp::update()
{
    float threshold = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 255);
    
    grabber.update();
    
    if (grabber.isFrameNew())
    {
        // do some stuff
        grabberCopy = grabber.getTexture();
        
        for (int x = 0; x < width; x++)
        {
            for (int y = 0; y < height; y++)
            {
                float brightness = grabber.getPixels().getColor(x, y).getBrightness();
                float pixColor = 
                
                if (brightness > threshold)
                {
                    grayscalePix.setColor(x, y, ofColor(255));
                }
                else
                {
                    grayscalePix.setColor(x, y, ofColor(0));
                }
            }
        }
        
        grayscaleTex.loadData(grayscalePix);
    }
    
    // apply mask as alpha channel for image 1 (foreground)
    grabberCopy.setAlphaMask(grayscaleTex);
    foreground.getTexture().setAlphaMask(grayscaleTex);
}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofBackground(0);
    
    grabber.draw(0, 0, width/2, height/2);
    grayscaleTex.draw(width/2, 0, width/2, height/2);
    
    // draw background image
    background.draw(0, height/2, width/2, height/2);
    // draw foreground
    // only opaque parts will be seen
    grabberCopy.draw(0, height/2, width/2, height/2);
    
    // draw background image
    background.draw(width/2, height/2, width/2, height/2);
    // draw foreground
    foreground.draw(width/2, height/2, width/2, height/2);

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
