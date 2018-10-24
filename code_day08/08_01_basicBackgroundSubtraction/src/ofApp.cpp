#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    grabber.setup(640, 480);
    gw = grabber.getWidth();
    gh = grabber.getHeight();
    
    grayPixels.allocate(gw, gh, OF_PIXELS_GRAY);
    grayTexture.allocate(gw, gh, GL_LUMINANCE);
    
    backgroundPixels.allocate(gw, gh, OF_PIXELS_GRAY);
    backgroundTexture.allocate(gw, gh, GL_LUMINANCE);
    
    diffPixels.allocate(gw, gh, OF_PIXELS_GRAY);
    diffTexture.allocate(gw, gh, GL_LUMINANCE);
    
    finalPixels.allocate(gw, gh, OF_PIXELS_GRAY);
    finalTexture.allocate(gw, gh, GL_LUMINANCE);
}

//--------------------------------------------------------------
void ofApp::update()
{
    threshold = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 255, true);
    grabber.update();
    
    if (grabber.isFrameNew())
    {
        // step one convert color to grayScale
        for (int x = 0; x < gw; x++)
        {
            for (int y = 0; y < gh; y++)
            {
                int brightness = grabber.getPixels().getColor(x, y).getBrightness();
                grayPixels.setColor(x, y, brightness);
            }
        }
        
        // step 2 grab a background when you hit space ' '
        if (ofGetKeyPressed(' '))
        {
            backgroundPixels = grayPixels;
        }
        
        // step 3 compare background pix with current gray Pix
        // to create a "foreground"
        for (int x = 0; x < gw; x++)
        {
            for (int y = 0; y < gh; y++)
            {
                int currentBrightness = grayPixels.getColor(x, y).getBrightness();
                int backgroundBrightness = backgroundPixels.getColor(x, y).getBrightness();
                
                int absDiff = std::abs(currentBrightness - backgroundBrightness);
                
                if (absDiff > threshold)
                {
                    diffPixels.setColor(x, y, ofColor(currentBrightness));
                }
                else
                {
                    diffPixels.setColor(x, y, ofColor(0));
                }
            }
        }
        
        grayTexture.loadData(grayPixels);
        backgroundTexture.loadData(backgroundPixels);
        diffTexture.loadData(diffPixels);
        
    }
}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofBackground(25);
    
    int halfWidth = gw/2;
    int halfHeight = gh/2;
    grabber.draw(0, 0, halfWidth, halfHeight);
    grayTexture.draw(halfWidth, 0, halfWidth, halfHeight);
    backgroundTexture.draw(0, halfHeight, halfWidth, halfHeight);
    diffTexture.draw(halfWidth, halfHeight, halfWidth, halfHeight);
    
    string threshStr = "Threshold::" + ofToString(threshold);
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
