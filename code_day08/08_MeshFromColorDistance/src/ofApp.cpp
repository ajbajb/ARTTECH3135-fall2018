#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    grabber.setup(640, 480);
    gw = grabber.getWidth();
    gh = grabber.getHeight();
    
    pixels.allocate(gw, gh, OF_PIXELS_RGB);
    texture.allocate(gw, gh, GL_RGB);
    pixels.set(0);
    
    cam.setScale(1, -1, 1);
    
    gui.setup();
    gui.add(threshold.set("theshold", 200, 0, 1000));
    gui.add(extrusion.set("extrusion", 200, 0, 1000));
    gui.add(selectedColor.set("selected color", ofColor(255, 0, 0), ofColor(0, 0), ofColor(255, 255)));
    
    // setup the mesh
    // this is one way we can do it that is uncomplicted.
    // we know that we will never have MORE verticies than pixels in the grabber
    // so rather than dynamically adding/removing verticies in the mesh every frame
    // we will just add all the verticies in setup, and keep the number constant
    // then just set all the vertices we dont want to see to black
    // it messes up how the mesh is drawn, but is very efficient
    
    mesh.setMode(OF_PRIMITIVE_LINES);  // try: OF_PRIMITIVE_POINTS
    glEnable(GL_POINT_SMOOTH);
    glPointSize(3);
    for (int x = 0; x < gw; x++)        // iterate over width and height and create a vertex point
    {                                   // at every location
        for ( int y = 0; y < gh; y++)
        {
            glm::vec3 vertexPoint(x,y,0);
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
                
                // get the vertex at this index
                glm::vec3 currentVert = mesh.getVertex(index);
                if (colorDistance > threshold)
                {
                    pixels.setColor(x, y, ofColor(0));
                    
                    // if out color distance is large than we the z position for the vertex
                    // all the way to the back and its color to transparent black
                    
                    currentVert.z = -extrusion;
                    mesh.setVertex(index, currentVert);
                    mesh.setColor(index, ofColor(0, 0));
                }
                else
                {
                    // if the color distance is close,
                    // we set the z position based on the pixels brightness
                    // and get the color of the grabber at that position
                    // and set the color of the vertex to that color
                    
                    int brightness = currentColor.getBrightness();
                    int currentZ = ofMap(brightness, 0, 255, -extrusion, extrusion);
                    
                    currentVert.z = currentZ;
                    mesh.setVertex(index, currentVert);
                    mesh.setColor(index, ofColor(currentColor, 150));
                    
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
    
    int halfWidth = gw/2;
    int halfHeight = gh/2;
    
    grabber.draw(0, 0, halfWidth, halfHeight);
    texture.draw(halfWidth, 0, halfWidth, halfHeight);
    
    ofEnableDepthTest();
    // draw our mesh in between our 3d camera
    cam.begin();
        ofPushMatrix();
        ofTranslate(-halfWidth, -halfHeight, 0);
        mesh.draw();
        ofPopMatrix();
    cam.end();
    
    ofDisableDepthTest();
    
    gui.draw();
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
