#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    grabber.setDesiredFrameRate(60);
    grabber.setup(640, 480);
    
    // Pre-allocate some memory.
    frames.reserve(8192);

}

//--------------------------------------------------------------
void ofApp::update()
{
    grabber.update();
    
    if (grabber.isFrameNew() && isRecording)
    {
        frames.push_back(grabber.getPixels());
    }

}

//--------------------------------------------------------------
void ofApp::draw()
{
    grabber.draw(0,0);
    
    if (isRecording)
    {
        ofDrawBitmapStringHighlight("# Frames: " + ofToString(frames.size()), 20, 20, ofColor::red);
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    if (key == ' ')
    {
        if (isRecording)
        {
            std::string templateFilename = ofGetTimestampString() + "/FRAME_{FRAME_NUMBER}.png";
            
            for (auto i = 0; i < frames.size(); ++i)
            {
                auto filename = templateFilename;
                ofStringReplace(filename, "{FRAME_NUMBER}", ofToString(i, 4, '0'));
                ofSaveImage(frames[i], filename);
            }
        }
        else
        {
            frames.clear();
            frames.reserve(8192);
        }
        
        isRecording = !isRecording;
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
