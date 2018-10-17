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
    
    if (grabber.isFrameNew())
    {
        grabberPix = grabber.getPixels();
        
    }

}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofBackgroundGradient(ofColor::darkGrey, ofColor::black);
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2 - grabber.getWidth()/2, ofGetHeight()/2 - grabber.getHeight()/2);
    // grabber.draw(0, 0);
    
    for (int x = 0; x < grabberPix.getWidth(); x+=10)
    {
        for (int y = 0; y < grabberPix.getHeight(); y+=10)
        {
            ofColor pixColor = grabberPix.getColor(x, y);
            float brightness = pixColor.getBrightness();
            float size = ofMap(brightness, 0., 255., 2., 25., true);
            
            ofSetColor(pixColor);
            ofFill();
            ofDrawCircle(x, y, size);
        }
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
