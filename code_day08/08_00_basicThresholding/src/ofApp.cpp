#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    grabber.setup(640, 480);
    gw = grabber.getWidth();
    gh = grabber.getHeight();
    
    grayPixels.allocate(gw, gh, OF_PIXELS_GRAY);
    grayTexture.allocate(gw, gh, GL_LUMINANCE);
}

//--------------------------------------------------------------
void ofApp::update()
{
    threshold = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 255, true);
    
    grabber.update();
    
    if (grabber.isFrameNew())
    {
        for (int x = 0; x < gw; x++)
        {
            for (int y = 0; y < gh; y++)
            {
                // ofColor pixelColor = grabber.getPixels().getColor(x, y);
                int brightnessValue = grabber.getPixels().getColor(x, y).getBrightness();
                
                // if brightness is above our threshold
                if (brightnessValue > threshold)
                {
                    // set the grabber Pix to white
                    grayPixels.setColor(x, y, ofColor(0));
                }
                else  // else black
                {
                    grayPixels.setColor(x, y, ofColor(brightnessValue));
                }
            }
        }
        grayTexture.loadData(grayPixels);
    }
}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofBackground(25);
    
    int halfw = gw/2;
    int halfh = gh/2;
    // draw the raw camera feed
    // grabber.draw(0, 0, halfw, halfh);
    
    // draw next to the thresholded texture
    // grayTexture.draw(halfw, 0);
    
    for (int x = 0; x < gw; x += 20)
    {
        for (int y = 0; y < gh; y += 20)
        {
            int brightness = grayPixels.getColor(x, y).getBrightness();
            // map brightness to rotation amount
            int rotation = ofMap(brightness, 0, 255, 0, 180);
            //set squares color from the original cameras color
            ofColor originalColor = grabber.getPixels().getColor(x, y);
            
            ofPushMatrix();
            ofTranslate(x, y);
            ofRotateXDeg(rotation);
            ofSetColor(originalColor);
            ofDrawRectangle(0-10, 0-10, 20, 20);
            ofPopMatrix();
        }
    }
    
    // display our threshold value
    string threshStr = "Threshold:: " + ofToString(threshold);
    ofDrawBitmapStringHighlight(threshStr, 10, 10);
    

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
