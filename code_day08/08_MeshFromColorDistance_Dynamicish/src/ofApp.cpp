#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    grabber.setup(320, 240);
    gw = grabber.getWidth();
    gh = grabber.getHeight();
    
    pixels.allocate(gw, gh, OF_PIXELS_RGB);
    texture.allocate(gw, gh, GL_RGB);
    pixels.set(0);
    
    cam.setScale(1, -1, 1);
    
    gui.setup();
    gui.add(threshold.set("theshold", 0, 0, 1000));
    gui.add(extrusion.set("extrusion", 200, 0, 1000));
    gui.add(selectedColor.set("selected color", ofColor(255, 0, 0), ofColor(0, 0), ofColor(255, 255)));
    
    // setup the mesh
    // this is one way we can do it that is uncomplicted.
    // we know that we will never have MORE verticies than pixels in the grabber
    // so rather than dynamically adding/removing verticies in the mesh every frame
    // we will just add all the verticies in setup, and keep the number constant
    // then just set all the vertices we dont want to see to black
    
    // In this example, we are also going to use INDICIES
    // which determine how the mesh vertiecs are connected
    // each vertex that is within our threshold will be connected together
    // but the ones that are not in our threshold (the ones we set to black)
    // will not get connected to the main mesh
    
    // please check out https://openframeworks.cc/documentation/3d/ofMesh/
    mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);  // try: OF_PRIMITIVE_LINES
    glEnable(GL_POINT_SMOOTH);
    glPointSize(3);
    mesh.enableIndices();
    
    for (int x = 0; x < gw; x++)        // iterate over width and height and create a vertex point
    {                                   // at every location
        for ( int y = 0; y < gh; y++)
        {
            glm::vec3 vertexPoint(x*2,y*2,0);
            mesh.addVertex(vertexPoint);

            mesh.addColor(ofColor(0, 0));
        }
    }
}

//--------------------------------------------------------------
void ofApp::update()
{
    grabber.update();
    
    if (grabber.isFrameNew())
    {
        mesh.clearIndices();
        pixels = grabber.getPixels();
        
        for (int x = 0; x < gw; x++)
        {
            for (int y = 0; y < gh; y++)
            {
                // get the index of the mesh at the x, y location
                // index = y + (x*height)
                int index = y + (x * gh);
                
                ofColor currentColor = pixels.getColor(x, y);
                
                float colorDistance = ofDist(selectedColor->r,
                                             selectedColor->g,
                                             selectedColor->b,
                                             currentColor.r,
                                             currentColor.g,
                                             currentColor.b);
                
                glm::vec3 currentVertex = mesh.getVertex(index);
                if (colorDistance > threshold)
                {
                    pixels.setColor(x, y, ofColor(0));
                    currentVertex.z = -extrusion - 10;
                    mesh.setVertex(index, currentVertex);
                }
                else
                {
                    // if the color distance is close,
                    // we set the z position based on the pixels brightness
                    // and get the color of the grabber at that position
                    // and set the color of the vertex to that color
                    
                    int brightness = currentColor.getBrightness();
                    int zSet = ofMap(brightness, 0, 255, -extrusion, extrusion);
                    
                    currentVertex.z = zSet;
                    mesh.setVertex(index, currentVertex);
                    mesh.setColor(index,ofColor(currentColor, 150));
                    mesh.addIndex(index);
                    
                    pixels.setColor(x, y, ofColor(255));
                }
            }
        }
        
        texture.loadData(pixels);
    }
}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofBackground(20);
    
    ofPushMatrix();
    ofTranslate(220, 0);
    grabber.draw(0, 0, gw, gh);
    texture.draw(gw, 0, gw, gh);
    ofPopMatrix();
    
    ofEnableDepthTest();
    // draw our mesh in between our 3d camera
    cam.begin();
        ofPushMatrix();
        ofTranslate(-gw, -gh, 0);
        mesh.draw();
        ofPopMatrix();
    cam.end();
    
    ofDisableDepthTest();
    
    gui.draw();
    
    string frameStr = "FrameRate::" + ofToString(ofGetFrameRate());
    ofDrawBitmapString(frameStr, ofGetWidth() - 150, 20);
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
