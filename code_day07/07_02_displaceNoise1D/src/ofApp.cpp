#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    grabber.setup(640, 480);
    
    grabberPix.allocate(grabber.getWidth(), grabber.getHeight(), OF_PIXELS_RGB);
    texture.allocate(grabber.getWidth(), grabber.getHeight(), GL_RGB);
}

//--------------------------------------------------------------
void ofApp::update()
{
    float noiseScale = 0.003;
    grabber.update();
    
    if (grabber.isFrameNew())
    {
        grabberPix = grabber.getPixels();
        
        for (int x = 0; x < grabberPix.getWidth(); x++)
        {
            for (int y = 0; y < grabberPix.getHeight(); y++)
            {
                // noise(0-1) = noise( (noiseSpace + offset) * scalestep)
                float noise = ofNoise((x + ofGetMouseX()) * noiseScale);
                float xDisplaced = x + (ofGetWidth() * noise);
                
                xDisplaced = ofWrap(xDisplaced, 0, grabberPix.getWidth());
                ofColor displacedColor = grabberPix.getColor(xDisplaced, y);
                
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
    ofTranslate(ofGetWidth()/2 + texture.getWidth()/2, ofGetHeight()/2 - texture.getHeight()/2);
    ofScale( -1, 1, 1);
    
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
