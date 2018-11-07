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
    
    ofLoadImage(puppyPixels, "kandp.jpg");
    puppyPixels.resize(gw, gh);
    puppyTexture.allocate(puppyPixels.getWidth(), puppyPixels.getHeight(), GL_RGBA);
    
    maskPixels.allocate(puppyPixels.getWidth(), puppyPixels.getHeight(), OF_PIXELS_GRAY);

}

//--------------------------------------------------------------
void ofApp::update()
{
    grabber.update();
    
    if (grabber.isFrameNew())
    {
        // fill the grayPix with the new grabber frame
        for (int x = 0; x < gw; x++)
        {
            for (int y = 0; y < gh; y++)
            {
                ofColor c = grabber.getPixels().getColor(x, y).getBrightness();
                grayPixels.setColor(x, y, c);
            }
        }
        
        // save a "background" frame
        if (ofGetKeyPressed(' ') == true)
        {
            backgroundPixels = grayPixels;
        }
        
        // subtract the background from the camera gray
        // and "create" a foreground
        for (int x = 0; x < gw; x++)
        {
            for (int y = 0; y < gh; y++)
            {
                int grayscaleBrightness = grayPixels.getColor(x, y).getBrightness();
                int backgroundBrightness = backgroundPixels.getColor(x, y).getBrightness();
                int absDiff = std::abs(grayscaleBrightness - backgroundBrightness);
                
                if (absDiff > 50)
                {
                    diffPixels.setColor(x, y, ofColor(255));
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
        
        puppyTexture.loadData(puppyPixels);
        puppyTexture.setAlphaMask(diffTexture);
    }

}

//--------------------------------------------------------------
void ofApp::draw()
{
    grabber.draw(0, 0, gw/2, gh/2);
    grayTexture.draw(gw/2, 0, gw/2, gh/2);

    backgroundTexture.draw(0, gh/2, gw/2, gh/2);
    diffTexture.draw(gw/2, gh/2, gw/2, gh/2);
    
    puppyTexture.draw(ofGetMouseX() - gw/2, ofGetMouseY() - gh/2, gw, gh);
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
