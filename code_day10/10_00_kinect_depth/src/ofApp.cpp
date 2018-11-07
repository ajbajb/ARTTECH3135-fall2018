#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    // open up a connection to our kinect device
    // with just one device, it wi always be device 0
    kinect.open(0);
    
    //allocate pixels and texture
    depthPixels.allocate(512, 424, OF_PIXELS_GRAY);
    depthTexture.allocate(512, 424, GL_LUMINANCE);
    
    colorPixels.allocate(512, 424, OF_PIXELS_RGB);
    finalTexture.allocate(512, 424, GL_RGB);
    
    // setup our gui
    gui.setup();
    gui.add(kinect.params);
    
    bDebug = true;
}

//--------------------------------------------------------------
void ofApp::update()
{
    kinect.update();
    
    if (kinect.isFrameNew())
    {
        // do stuff
        // grab the kinect depth pixels
        // and put them in an ofPixels
        depthPixels = kinect.getDepthPixels();

        for (int x = 0; x < depthPixels.getWidth(); x++)
        {
            for (int y = 0; y < depthPixels.getHeight(); y++)
            {
                int brightness = depthPixels.getColor(x, y).getBrightness();
                
                if (brightness <= 0)
                {
                    colorPixels.setColor(x, y, ofColor::hotPink);
                }
                else
                {
                    colorPixels.setColor(x, y, ofColor::limeGreen);
                }
            }
        }
        
        // load pixels into an ofTexture
        depthTexture.loadData(depthPixels);
        finalTexture.loadData(colorPixels);
    }
}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofBackground(0);
    
    ofPushMatrix();
    
    ofTranslate(ofGetWidth()/2 - finalTexture.getWidth()/2, ofGetHeight()/2 - finalTexture.getWidth()/2);
    finalTexture.draw(0, 0);
    
    ofPopMatrix();
    
    // draw the "debug" window
    if (bDebug)
    {
        depthTexture.draw(0, 0);
        gui.draw();
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    if (key == 'g')
    {
        bDebug = !bDebug;
    }
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
