#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	// load a font
	// and set it to get contours
	
	// load(font, size, antialising, full character set,
	// make contours, set simplify, set dpi)
	
	text.load("/Library/Fonts/Arial.ttf", 128, true, true, true);

}

//--------------------------------------------------------------
void ofApp::update()
{

	
}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofBackground(40);
	
	float time = ofGetElapsedTimef();
	float noise = 20 * ofSignedNoise(time * 0.07);
	
	std::string str = "NOISE";
	std::vector<ofPath> paths = text.getStringAsPoints(str);
	
	ofPushMatrix();
	ofTranslate(ofGetWidth()/2 - 150, ofGetHeight()/2);
	
	for (auto path : paths)
	{
		path.setPolyWindingMode(OF_POLY_WINDING_ODD);
		std::vector<ofPolyline> lines = path.getOutline();
	
		float offset = 0.0;
		for (auto& vert : lines[0].getVertices())
		{
			float noise = 20 * ofSignedNoise(time * 0.07 * offset);
			 vert.x = vert.x + noise;
			 vert.y += 20 * sin(time * 0.03 + offset);
		
			ofSetColor(ofColor::steelBlue);
			ofDrawCircle(vert, 3);
		
			offset += 0.5;
		}
	
		for (int i = 0; i < lines.size(); i++)
		{
			ofSetColor(ofColor::white);
			lines[i].draw();
		}
	}
	
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
