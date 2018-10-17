#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    grabber.setup(640, 480);
    gw = grabber.getWidth();
    gh = grabber.getHeight();
    
    grabberPix.allocate(gw, gh, OF_PIXELS_RGB);
    texture.allocate(gw, gh, GL_RGB);

}

//--------------------------------------------------------------
void ofApp::update()
{
    float threshold = 150;
    grabber.update();
    
    if (grabber.isFrameNew())
    {
        grabberPix = grabber.getPixels();
        
        for (int x = 0; x < gw; x++)
        {
            for (int y= 0; y < gh; y++)
            {
                // get the brightness of our pixel
                ofColor pixelColor = grabberPix.getColor(x, y);
                float brightness = pixelColor.getBrightness();
                
                // if it is above our threshold
                if (brightness > threshold)
                {
                    // draw it white
                   grabberPix.setColor(x, y, ofColor(255));
                }
                else // if it is below our threshold
                {
                    // do something else... like draw the pixel black
                    grabberPix.setColor(x, y, ofColor(0));
                }

            }
        }
    }
    
    texture.loadData(grabberPix);

}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofBackground(0);
    
    texture.draw(0, 0);
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
