#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofSetBackgroundAuto(false);
	
	note1.load("Electronic_Piano_Notes/A.wav");
	notes.push_back(note1);
	note2.load("Electronic_Piano_Notes/C#.wav");
	notes.push_back(note2);
	note3.load("Electronic_Piano_Notes/E.wav");
	notes.push_back(note3);
	note4.load("Electronic_Piano_Notes/2A.wav");
	notes.push_back(note4);
	
	for (auto note : notes)
	{
		note.setVolume(0.7);
		note.setMultiPlay(false);
	}
	

}

//--------------------------------------------------------------
void ofApp::update()
{
	
	// xPos is GLOBAL, which means it is valid everywhere in our program
	// Lets incriment xPos by xSpeed every update() loop
	xPos += xSpeed * xDirection;
	
	// Do the same thing for y
	yPos += ySpeed * yDirection;
	
	// If our ball reaches the edge of the screen, go the opposite direction
	// lets check our right edge
	if (xPos > ofGetWidth())
	{
		// lets change the background color
		backgroundColor = ofColor(ofRandom(255), ofRandom(255), ofRandom(255), 20);
		
		notes[0].play();
		
		// lets have Xspeed increase everytime it hits the right wall
		xSpeed += 1;
		xDirection *= -1;
	}
	
	// lets check out left edge
	if (xPos < 0)
	{
		// change the color
		backgroundColor = ofColor(ofRandom(255), ofRandom(255), ofRandom(255), 20);
		
		
		xSpeed += 1; // increase the speed!
		
		notes[3].play();
		
		// change direction
		xDirection *= -1;
	}
	// check our botton edge
	if (yPos > ofGetHeight())
	{
		// change the color
		backgroundColor = ofColor(ofRandom(255), ofRandom(255), ofRandom(255), 20);
		
		notes[1].play();
		
		ySpeed += 1;
		yDirection *= -1;
	}
	
	// check our top edge
	if (yPos < 0)
	{
		// change the color
		backgroundColor = ofColor(ofRandom(255), ofRandom(255), ofRandom(255), 20);
		
		notes[2].play();
		ySpeed += 1;
		yDirection *= -1;
	}
}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofSetColor(backgroundColor);
	ofFill();
	ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
	
	// This is like std::cout, take care of std::endl;
	ofLog() << xPos;
	// about same thing is std::cout << xPos << std::endl;
	
	ofSetColor(ofColor::hotPink);
	ofFill();
	ofDrawCircle(xPos, yPos, 20); // use xPos to set the x-position for
											// our circle
}
















