#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    grabber.setup(640, 480);
    
    gWidth = grabber.getWidth();
    gHeight = grabber.getHeight();
    
    grabberPix.allocate(gWidth, gHeight, OF_PIXELS_RGB);
    texture.allocate(gWidth, gHeight, GL_RGB);

}

//--------------------------------------------------------------
void ofApp::update()
{
    float noiseScale = 0.001;
    grabber.update();
    
    if (grabber.isFrameNew())
    {
        // get a fresh set of pixels to play with
        grabberPix = grabber.getPixels();
        
        for (int x = 0; x < gWidth; x++)
        {
            for (int y = 0; y < gHeight; y++)
            {
                // do something
                // 2d Noise
                float noise = ofNoise((x + ofGetMouseX()) * noiseScale, (y + ofGetMouseY()) * noiseScale);
                
                int displacedX = x + gWidth * noise;
                int displacedY = y + gHeight * noise;
                
                displacedX = ofWrap(displacedX, 0, gWidth);
                displacedY = ofWrap(displacedY, 0, gHeight);
                
                // grab the color at the displaced location from the fresh pixels
                ofColor displacedColor = grabber.getPixels().getColor(displacedX, displacedY);
                
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
    ofTranslate(ofGetWidth()/2 + gWidth/2, ofGetHeight()/2 - gHeight/2);
    ofScale(-1, 1, 1);
    
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
