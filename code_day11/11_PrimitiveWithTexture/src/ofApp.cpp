#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    // load our texture
    ofDisableArbTex();
    tex.load("5Asset1@4x.png");
    
    // this will be our "prototype sphere" that we will not touch
    // but will "reset" the position of the verticies of our drawn mesh
    protoSphere.setRadius(ofGetWidth() * 0.2);
    protoSphere.setPosition(0, 0, 0);
    protoSphere.mapTexCoordsFromTexture(tex.getTexture());
    
    // this is the mesh we will deform, apply our texture to
    // and draw to the screen.
    // its verticies will be set from our prototype sphere and then deformed with a sin function
    deformMeshSphere.setMode(OF_PRIMITIVE_TRIANGLES);
    

}

//--------------------------------------------------------------
void ofApp::update()
{
    // get all the faces from the protype icoSphere.
    // a face is just a collection of points that make up a triangle in the sphere
    // a sphere mesh is collection of triangles
    // so we grab all the triangle that make up our sphere and put them in a vector
    vector<ofMeshFace> triangles = protoSphere.getMesh().getUniqueFaces();
    
    float time = ofGetElapsedTimeMillis();
    // speed of displacement
    float speed = 0.004;
    // strength of displacement mapped to mouse position here
    float strength = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 50);
    // offset will be based on the position of the vertex in the sphere
    int offset;
    
    //iterate through our triangle vector
    glm::vec3 faceNormal;
    for (int i = 0; i < triangles.size(); i++)
    {
        // get one triangle face from the vector
        faceNormal = triangles[i].getFaceNormal();
        
        // and set the vertex points in that triangle
        for (int j = 0; j < 3; j++)
        {
            offset = j*i;
            float displacement = strength * sin(time * speed + (j*i));
            glm::vec3 tempVert = triangles[i].getVertex(j) + faceNormal * displacement;
            triangles[i].setVertex(j, tempVert);
        }
    }
    
    // and set the points of out drawn sphere from the vector of deformed triangles
    //sphere.getMesh().setFromTriangles(triangles);
    deformMeshSphere.setFromTriangles(triangles);

}

//--------------------------------------------------------------
void ofApp::draw()
{
    
    ofBackground(200);
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    // we have to flip our y-axis otherwise the texture will be applied upside down :(
    ofScale(1, -1, 1);
    tex.getTexture().bind();
    // now draw the spehere
    deformMeshSphere.draw();
    tex.getTexture().unbind();
    ofPopMatrix();
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
