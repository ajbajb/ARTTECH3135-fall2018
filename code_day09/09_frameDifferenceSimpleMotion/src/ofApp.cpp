#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    grabber.setup(640, 480);
    w = grabber.getWidth();
    h = grabber.getHeight();
    
    prevPixels.allocate(w, h, OF_PIXELS_RGB);
    prevPixels.set(0);  // set everything to black
    diffPixels.allocate(w, h, OF_PIXELS_RGB);
    diffPixels.set(0);
    
    diffTexture.allocate(w, h, GL_RGB);
}

//--------------------------------------------------------------
void ofApp::update()
{
    threshold = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 1000);
    
    grabber.update();
    
    if (grabber.isFrameNew())
    {
        for (int x = 0; x < w; x++)
        {
            for (int y = 0; y < h; y++)
            {
                // grab current color at that pixel location
                ofColor currentColor = grabber.getPixels().getColor(x, y);
                
                // grab the color of the prev frame at that same location
                ofColor prevColor = prevPixels.getColor(x, y);
                
                // and compare the two
                float distance = ofDist(currentColor.r, currentColor.g, currentColor.b,
                                        prevColor.r, prevColor.g, prevColor.b);
                
                if (distance > threshold)
                {
                    // A lot had chnaged at that pixel location
                    // so lets draw it in out diffPixels
                    diffPixels.setColor(x, y, 255);
                }
                else
                {
                    diffPixels.setColor(x, y, 0);
                }
                
                prevPixels.setColor(x, y, currentColor);
            }
        }
        
        diffTexture.loadData(diffPixels);
    }
}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofBackground(0);
    
    grabber.draw(0, 0, w/2, h/2);
    
    diffTexture.draw(w/2, 0, w, h);
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
