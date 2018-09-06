#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	redValue = 0;
	greenValue = 0;
	blueValue = 0;
	
	hueValue = 0;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofColor myColor;
	//if we are using RGB color
	//myColor is composed of three componets
	//which are the three color channels R, G, B that have values 0-255
	//values do wrap
	
//	redValue = redValue + 1;
//	greenValue += 0.5;
//	blueValue -= 1.5;
//
//	myColor.r = redValue;
//	myColor.g = greenValue;
//	myColor.b = blueValue;
	
	//if setting HSB use .setHsb values are 0-255, but do not wrap
	hueValue += 1;
	
	myColor.setHsb(hueValue, 255, 255);
	
	ofBackground(myColor);
	
	//if this thing is true
	if(hueValue > 255)
	{
		//do this thing inside this block
		hueValue = 0;
		
		//then exit the block
	}
}
