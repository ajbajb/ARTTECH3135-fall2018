#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    grabber.setup(640, 480);
    
    gw = grabber.getWidth();
    gh = grabber.getHeight();
    
    pix.allocate(gw, gh, OF_PIXELS_RGB);
    texture.allocate(gw, gh, GL_RGB);
    
    pix.set(0);
}

//--------------------------------------------------------------
void ofApp::update()
{
    grabber.update();
    
    if (grabber.isFrameNew())
    {
        for (int x = 0; x < gw; x++)
        {
            for (int y = 0; y < gh; y++)
            {
                if (x <= gw-1 )
                {
                    ofColor prevColor = pix.getColor(x+1, y);
                    ofColor currentColor = grabber.getPixels().getColor(x, y);
                
                    ofColor lerpedColor = prevColor.getLerped(currentColor, 0.001);
                    pix.setColor(x, y, lerpedColor);
                }
                else
                {
                    ofColor grabberColor = grabber.getPixels().getColor(x, y);
                    pix.setColor(x,y, grabberColor);
                }
                
            }
        }
    }
    
    texture.loadData(pix);
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
