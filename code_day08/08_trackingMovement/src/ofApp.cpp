#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    ofSetBackgroundAuto(false);
    
    grabber.setup( 640, 480);
    
    gw = grabber.getWidth();
    gh = grabber.getHeight();
    
    prevPixels.allocate(gw, gh, OF_PIXELS_RGB);
    drawPixels.allocate(gw, gh, OF_PIXELS_RGB);
    
    texture.allocate(gw, gh, GL_RGB);
    
    prevPixels.set(255);
    drawPixels.set(255);
}

//--------------------------------------------------------------
void ofApp::update()
{
    threshold = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 255, true);
    
    grabber.update();
    
    if (grabber.isFrameNew())
    {
        ofPixels currentPixels = grabber.getPixels();
        
        for (int x = 0; x < gw; x++)
        {
            for (int y = 0; y < gh; y++)
            {
                // get current pixels brightness
                // ofColor color = currentPixels.getColor(x, y);
                // brightness = color.getBrightness();
                float currentBrightness = currentPixels.getColor(x, y).getBrightness();
                
                // prev pixels brightness
                float prevBrightness = prevPixels.getColor(x, y).getBrightness();
                
                float brightnessDiff = ofDist(currentBrightness, 0, prevBrightness, 0);
                
                if ( brightnessDiff > threshold)
                {
                    // there is movement!
                    drawPixels.setColor(x, y, ofColor(0));
                }
                else
                {
                    // there is no change - no movement
                    drawPixels.setColor(x, y, ofColor(255));
                }
            }
        }
        
        prevPixels = currentPixels;
        texture.loadData(drawPixels);
    }
}

//--------------------------------------------------------------
void ofApp::draw()
{
    // ofBackground(255);
    
    //texture.draw(0, 0);
    
    ofSetColor(255, 10);
    ofDrawRectangle(0, 0, gw, gh);
    
    for (int x = 0; x < gw; x += 5)
    {
        for (int y = 0; y < gh; y += 5)
        {
            float brightness = drawPixels.getColor(x, y).getBrightness();
            
            if (brightness < 20)
            {
                // draw a letter
                ofSetColor(0);
                ofDrawBitmapString("DUST", x, y);
            }
        }
    }
    
    
    string frameStr = "Framerate:: " + ofToString(ofGetFrameRate());
    ofDrawBitmapStringHighlight(frameStr, 10, 10);
    
    string threshStr = "Threshold:: " + ofToString(threshold);
    ofDrawBitmapStringHighlight(threshStr, 25, 25);

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
