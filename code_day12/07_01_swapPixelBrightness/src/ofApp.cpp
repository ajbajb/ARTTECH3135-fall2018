#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    grabber.setup(640, 480);
    
    texture.allocate(grabber.getWidth(), grabber.getHeight(), GL_RGB);
    
}

//--------------------------------------------------------------
void ofApp::update()
{
    grabber.update();
    
    // brightestPixel = {0, 0};
 
    if (grabber.isFrameNew())
    {
        float maxBrightness = 0.0;
        // get a copy of the pixels
        ofPixels grabberPix = grabber.getPixels();
        
        for (std::size_t y = 0; y < grabberPix.getWidth(); y++)
        {
            for (std::size_t x = 0; x < grabberPix.getHeight(); x++)
            {
                // do something
                // find the brightest pixel
                
                 float currentBrightness = grabberPix.getColor(x, y).getBrightness();
            
                if (currentBrightness > maxBrightness)
                {
                    brightestPixel = {x, y};
                    maxBrightness = currentBrightness;
                }
                
            }
        }
    }
    
    circlePos = brightestPixel;
    ofLog() << brightestPixel << " " << maxBrightness;
}

//--------------------------------------------------------------
void ofApp::draw()
{
    grabber.draw(0, 0);
    
    ofPushStyle();
    ofSetColor(255, 0, 0);
    ofFill();
    ofDrawCircle(circlePos, 3);
    ofPopStyle();

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
