#include "ofApp.h"

//--http://dada.compart-bremen.de/item/artwork/128-
void ofApp::setup()
{
	//ofBackground(255);
	
	path.setFilled(false);
	path.setStrokeColor(0);
	path.setStrokeWidth(5);
	
	path.moveTo(0, 0);
	
	path2.setFilled(false);
	path2.setStrokeColor(0);
	path2.setStrokeWidth(5);
	
	path2.moveTo(ofGetWidth(), ofGetHeight());
	
	path3.setFilled(false);
	path3.setStrokeColor(0);
	path3.setStrokeWidth(5);
	
	

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw()
{
	//ofBackground(255);
	
	//path.moveTo(0, 0);
	
	if(ofGetMousePressed())
	{
		float randomX = ofRandom(ofGetWidth()/2);
		float randomY = ofRandom(ofGetHeight());
		
		
		path.lineTo(randomX, randomY);
		path2.lineTo(ofGetWidth()-randomX, ofGetHeight()-randomY);
		
		path3.moveTo(randomX, randomY);
		path3.lineTo(ofGetWidth()-randomX, ofGetHeight()-randomY);
	}
	

	path.draw();
	path2.draw();
	path3.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	if(key == ' ')
	{
		path.clear();
		path2.clear();
		path3.clear();
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
