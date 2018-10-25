#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    ofSetBackgroundAuto(false);
    grabber.setup(640, 480);
    
    pixels.allocate(grabber.getWidth(), grabber.getHeight(), OF_PIXELS_RGB);
    texture.allocate(grabber.getWidth(), grabber.getHeight(), GL_RGB);
    
    gui.setup();
    gui.add(threshold.set("threshold", 127., 0., 1000.));
    gui.add(selectedColor.set("color", ofColor(255, 0, 0), ofColor(0,0), ofColor(255, 255)));
    
    cam.setScale(1, -1, 1);
    
}

//--------------------------------------------------------------
void ofApp::update()
{
    if (points.size() > 1000)
    {
        points.clear();
    }
    
    grabber.update();
    if (grabber.isFrameNew())
    {
        pixels = grabber.getPixels();
        for (int x = 0; x < grabber.getWidth(); x++)
        {
            for (int y = 0; y < grabber.getHeight(); y++)
            {
                //get me the color
                ofColor current = pixels.getColor(x, y);
                
                // distance from our selected color and our current color
                float colorDistance = ofDist(selectedColor->r,
                                             selectedColor->g,
                                             selectedColor->b,
                                             current.r, current.g, current.b);
                
                // if the distance is large enough
                if (colorDistance > threshold)
                {
                    pixels.setColor(x, y, ofColor(0));
                }
                else
                {
                    pixels.setColor(x, y, ofColor(255));
                    
                    int z = ofMap(current.getBrightness(), 0, 255, -1000, 1000);
                    glm::vec3 point(x, y, z);
                    points.push_back(point);
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
    
    int halfWidth = grabber.getWidth()/2;
    int halfHeight = grabber.getHeight()/2;
    ofSetColor(255);
    texture.draw(0, 0, halfWidth, halfHeight);
    
    ofEnableDepthTest();
    cam.begin();
    for (int i = 0; i < points.size(); i += 10)
    {
        glm::vec3 currentPoint = points[i];
        
        for (int j = 0; j < points.size(); j += 10)
        {
            glm::vec3 nextPoint = points[j];
            
            float distance = glm::distance(currentPoint, nextPoint);
            
            ofSetColor(255, 100);
            if (distance > 1000.)
            {
                ofDrawLine(currentPoint, nextPoint);
            }
            
        }
        //ofDrawCircle(currentPoint, 2);
    }
    cam.end();
    ofDisableDepthTest();
    
//    for (int x = 0; x < pixels.getWidth(); x++)
//    {
//        for (int y = 0; y < pixels.getHeight(); y++)
//        {
//            if (pixels.getColor(x,y).r >= 250)
//            {
//                ofColor grabberColor = grabber.getPixels().getColor(x,y);
//
//                ofPushMatrix();
//                ofTranslate(halfWidth, 0);
//                ofSetColor(grabberColor);
//                ofDrawCircle(x, y, 2);
//                ofPopMatrix();
//            }
//        }
//    }
    
    // showinf our slected color
//    ofSetColor(selectedColor);
//    ofFill();
//    ofDrawRectangle(20, 20, 40, 40);
    
    gui.draw();
    ofDrawBitmapString(ofToString(ofGetFrameRate()), 10, 10);
    ofDrawBitmapString(ofToString(points.size()), 10, 25);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    ofBackground(25);

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
