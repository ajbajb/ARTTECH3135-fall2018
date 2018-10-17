#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    grabber.setup(640, 480);
    grabberPix.allocate(grabber.getWidth(), grabber.getHeight(), OF_PIXELS_RGB);
    
    ofLoadImage(fredTex, "freddy.png");
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
    ofBackground(0);
    
    for (int x = 0; x< grabberPix.getWidth(); x += 20)
    {
        for (int y = 0; y < grabberPix.getHeight(); y += 20)
        {
            ofColor pixelColor = grabberPix.getColor(x, y);
            float brightness = pixelColor.getBrightness();
            
            float freddySize = ofMap(brightness, 0, 255, 0, 100);
            
            ofSetColor(pixelColor);
            
            ofPushMatrix();
            ofTranslate(x, y);
            ofRotateZDeg(d);
            fredTex.draw(0, 0, freddySize, freddySize);
            
            ofPopMatrix();
        }
    }
    
    d += 0.4 * rotationDirection;
    if (d > 10 or d < -10 )
    {
        
        rotationDirection *= -1;
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
