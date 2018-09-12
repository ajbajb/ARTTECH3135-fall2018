#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	// load some images to be ready to display, etc
	img1.load("kitty.png");
	
	
	ofSetRectMode(OF_RECTMODE_CENTER);
	
	ofBackground(ofColor::pink);
	ofSetBackgroundAuto(false);
	
	player.load("meow.wav");
	player.setMultiPlay(true);
	player.setVolume(0.5);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw()
{
	if(ofGetMousePressed(OF_MOUSE_BUTTON_LEFT))
	{
		float hue = ofRandom(255);
		ofSetColor(ofColor::fromHsb(hue, 180, 255));
		int size = ofRandom(10, 250);
		
		img1.draw(ofGetMouseX(), ofGetMouseY(), size, size);
		
		player.play();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	if(key == ' ')
	{
		ofColor c = ofColor::fromHsb(ofRandom(255), 180, 255);
		ofClear(c);
	}
	
	if(key == 's')
	{
		ofSaveScreen("screenShot_"+ofGetTimestampString()+".png");
		
		std::cout<<"Screen Saved! Good Work!"<<std::endl;
	}
}















