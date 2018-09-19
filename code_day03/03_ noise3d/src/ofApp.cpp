#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofBackground(0);
	float distX = (40*sin(ofGetElapsedTimef()*0.05 + 1.2)) * 0.001;
	float distY = (40*sin(ofGetElapsedTimef()*0.05 + 1.3)) * 0.001;
	float distZ = (40*sin(ofGetElapsedTimef()*0.05 )) * 0.001;

	
	cam.begin();
	ofEnableDepthTest();
	for(int x=0; x<100; x+=2)
	{
		for(int y=0; y<100; y+=2)
		{
			for(int z=0; z<100; z+=2)
			{
				float greyScale = ofNoise(x*distX, y*distY, z*distZ) * 255;
				
				ofSetColor(ofColor::fromHsb(greyScale, 75, 200));
				ofFill();
				glm::vec3 location(x,y,-z);
				ofDrawRectangle(location, 2, 2);
			}
		}
	}
	cam.end();

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
