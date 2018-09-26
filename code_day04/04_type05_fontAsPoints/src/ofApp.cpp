#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	std::string text = "NOISE BLOCK";
	words = ofSplitString(text, " ");
	font.load("/Library/Fonts/Chalkduster.ttf", 100, true, true, true);
	
}

//--------------------------------------------------------------
void ofApp::update()
{
	

}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofBackground(50);
	
	ofPushMatrix();
	ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
	
	// get the path of the letters. each letter will be a seperate path
	vector<ofPath> paths = font.getStringAsPoints(words[0]);
	for (auto path : paths)
	{
		path.setPolyWindingMode(OF_POLY_WINDING_ODD); // set the poly winding mode because it it not set as default
		
		// break out the paths to polylines. store it in a vector
		std::vector<ofPolyline> tempLines = path.getOutline();
		// break out the lines in the polyline
		for (auto line : tempLines)
		{
			int i = 0;
			ofColor c = ofColor::fromHsb(ofRandom(200), 255, 255);
			
			for( auto point : line) // break out the points for eachline
			{
				if (i % 2 == 0)
				{
					float time  = ofGetElapsedTimef();
					float maxOffset = 50;
				
					point.x = point.x + (maxOffset/2 + maxOffset/2 * sin(time * 0.05 * i));
					point.y = point.y * 2;
				
					ofSetColor(c);
					ofDrawCircle(point, 1);
				}
				i++;
			}
		}
	}
	ofPopMatrix();
	
	font.drawStringAsShapes(words[0], 200, 200);

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
