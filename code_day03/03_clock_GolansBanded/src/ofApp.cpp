#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	width = ofGetWidth();
	height = ofGetHeight();
	
	sColors.resize(width);
	mColors.resize(width);
	hColors.resize(width);
	
	ySec0 = 0;
	ySec1 = height/3;
	yMin0 = ySec1 + 1;
	yMin1 = (height * (2.0/3.0));
	yHour0 = yMin1 + 1;
	yHour1 = height;
	
	ofLog() << ySec0;
	ofLog() << ySec1;
	ofLog() << yMin0;
	ofLog() << yMin1;
	ofLog() << yHour0;
	ofLog() << yHour1;
	
}

//--------------------------------------------------------------
void ofApp::update()
{
	updateClock();

}

//--------------------------------------------------------------
void ofApp::draw()
{
	drawClock();

}

float gmod(float a, float b)
{
	return a - (floor(a / b)* b);
}

int sinFunc( float a)
{
	float sina = (1.0 + sin(TWO_PI * a)) * (255.0 * 0.5);
	int val = (int)round(sina);
	
	return val;
}

void ofApp::updateClock()
{
	int seconds = ofGetSeconds();
	int minutes = ofGetMinutes();
	int hours = ofGetHours()%12;
	
	float pct;
	float pctS;
	float pctM;
	float pctH;
	
	for (int i = 0; i < width; i++)
	{
		pct = (float)i / (float)width;
		pctS = pct * seconds;
		pctM = pct * minutes;
		pctH = pct * hours;
		
		sColors[i] = sinFunc(gmod(pctS, 1.0));
		mColors[i] = sinFunc(gmod(pctM, 1.0));
		hColors[i] = sinFunc(gmod(pctH, 1.0));
	}
}

void ofApp:: drawClock()
{
	for (int x = 0; x < width; x++)
	{
		ofSetColor(sColors[x]);
		ofDrawLine(x, ySec0, x, ySec1);
		
		ofSetColor(mColors[x]);
		ofDrawLine(x, yMin0, x, yMin1);

		ofSetColor(hColors[x]);
		ofDrawLine(x, yHour0, x, yHour1);
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
