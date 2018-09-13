#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	seed = 10;
	ofBackground(0);
	ofSetBackgroundAuto(false);
	
	for(int i=0; i<7; i++)
	{
		ofColor c;
		c.setHsb(ofRandom(255), ofRandom(60, 200), ofRandom(160, 255));
		colors.push_back(c);
	}
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofSeedRandom(ofGetMouseX());
	
	int width = ofGetWidth();
	int height = ofGetHeight();
	int xSpacing = width/6;
	int ySpacing = height/6;
	float size = ySpacing/3;
	
	//offset border... this doesnt work too well
	int offset = 30;
	
	float poop = ofRandom(width);
	int y = height/2;
	
	ofSetColor(0, 0, 0, 5);
	ofDrawRectangle(0, 0, width, height);

	for(int y = offset; y< height; y+=ySpacing)
	{
		for(int x = offset; x < width; x+=xSpacing)
		{
			glm::vec2 origin(0 + ofRandom(size), 0 + ofRandom(size));
			glm::vec2 p1((origin.x + size)+ofRandom(-size,size), origin.y + ofRandom(-size,size));
			glm::vec2 p2(origin.x + size + ofRandom(-size,size), origin.y + size + ofRandom(-size,size));
			glm::vec2 p3(origin.x + ofRandom(-size,size), origin.y+size + ofRandom(-size,size));
			glm::vec2 p4 = origin;
			
			int index = ofRandom(colors.size());
			ofColor myColor = colors[index];
			
			ofPath path;
			path.setFilled(false);
			path.setStrokeColor(myColor);
			path.setStrokeWidth(2);
	
			path.clear();
			ofPushMatrix();
				ofTranslate(x, y);
				path.moveTo(origin);
				path.lineTo(p1);
				path.lineTo(p2);
				path.lineTo(p3);
				path.lineTo(p4);
	
				path.draw();
			ofPopMatrix();
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	seed = ofRandom(-1000, 1000);
	//ofSeedRandom(ofGetMouseX());
	

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
