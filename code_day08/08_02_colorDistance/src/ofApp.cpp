#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    grabber.setup(640, 480);
    
    pixels.allocate(grabber.getWidth(), grabber.getHeight(), OF_PIXELS_RGB);
    texture.allocate(grabber.getWidth(), grabber.getHeight(), GL_RGB);
    
    gui.setup();
    gui.add(threshold.set("threshold", 127., 0., 255.));
    gui.add(selectedColor.set("color", ofColor(255, 0, 0), ofColor(0,0), ofColor(255, 255)));
    
}

//--------------------------------------------------------------
void ofApp::update()
{
    // threshold = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 1000);
    //selectedColor = ofColor(255, 0, 0);
    
    grabber.update();
    if (grabber.isFrameNew())
    {
        pixels = grabber.getPixels();
        for (int x = 0; x < grabber.getWidth(); x++)
        {
            for (int y = 0; y < grabber.getHeight(); y++)
            {
                ofColor current = pixels.getColor(x, y);
                
                float colorDistance = ofDist(selectedColor->r,
                                             selectedColor->g,
                                             selectedColor->b,
                                             current.r, current.g, current.b);
                
                if (colorDistance > threshold)
                {
                    pixels.setColor(x, y, ofColor(0));
                }
            }
        }
        
        texture.loadData(pixels);
    }
}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofBackground(25);
    
    ofSetColor(255);
    texture.draw(0, 0);
    
    ofSetColor(selectedColor);
    ofFill();
    ofDrawRectangle(20, 20, 40, 40);
    
    gui.draw();
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
