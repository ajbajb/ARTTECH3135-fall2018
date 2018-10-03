#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	font.load("/Library/Fonts/Arial.ttf", 225);
	std::string text = "SASSY";
	
	// points.resize(NUM_POINTS);
	
	mask.allocate(ofGetWidth(), ofGetHeight());
	
	mask.begin();
	ofClear(0);
	
	ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
	ofSetColor(0);
	font.drawString(text, font.stringWidth(text) * -0.57, font.stringHeight(text) * 0.5);
	mask.end();
	
	mask.readToPixels(pix);
	
}

//--------------------------------------------------------------
void ofApp::update()
{
	ofSeedRandom(200);

}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofBackground(0);
	
	std::vector<glm::vec2> setPoints;
	while (setPoints.size() < NUM_POINTS)
	{
		// get a random point of the  pixel mask
		// test if the mask is balck or white
		// if it is black, add that point to our setPoints array

		float xPos = ofRandom(ofGetWidth());
		float yPos = ofRandom(ofGetHeight());
		ofColor pixelColor = pix.getColor(xPos, yPos);

		if (pixelColor == ofColor(0))
		{
			// before we add it, lets change the position a little
			// with noise
			
			float time = ofGetElapsedTimef();
			float scale = 20;
			
			float noiseX = ofNoise(ofRandom(NUM_POINTS), time * 0.05);
			float noiseY = ofNoise(ofRandom(NUM_POINTS), time * 0.05);
			
			float xOff = ofMap(noiseX, 0, 1, -scale, scale);
			float yOff = ofMap(noiseY, 0, 1, -scale, scale);
			
			xPos += xOff;
			yPos += yOff;
			
			setPoints.push_back(glm::vec2(xPos, yPos));
		}
	}
	
	mask.draw(0, 0);
	drawPointsSimple(setPoints);
	drawPointsConnected(setPoints);

}

void ofApp::drawPointsSimple(std::vector<glm::vec2> points)
{
	for (auto point : points)
	{
		ofPushStyle();
		ofSetColor(ofColor::darkCyan);
		ofFill();
		ofDrawCircle(point, 3);
		ofPopStyle();
	}
}

void ofApp::drawPointsConnected(std::vector<glm::vec2> points)
{
	
	// drawing line between a point and every other point within a certian distance
	float distThresh = 40;
	
	for (int i = 0; i < points.size(); i++)
	{
		glm::vec2 point = points[i];
		
		float hue = ofMap(i, 0, points.size(), 0, 255);
		
		for (int j = 0; j < points.size(); j++)
		{
			glm::vec2 otherPoint = points[j];
			
			float dist = glm::distance(point, otherPoint);
			
			if (dist > 4 and dist < distThresh)
			{
				ofSetColor(ofColor::fromHsb(hue, 100, 255, 110));
				ofDrawLine(point, otherPoint);
			}
		}
	}
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
