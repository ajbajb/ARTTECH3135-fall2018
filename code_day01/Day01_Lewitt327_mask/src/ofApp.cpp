#include "ofApp.h"

//_Wall Drawing #327_ - On a black wall, a white trapezoid within which
//are white vertical parallel lines and a white square within which are
//white horizontal parallel lines. The vertical lines within the trapezoid
//do not enter the square, and the horizontal lines within the square
//do not enter the trapezoid.

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw()
{
	//On a black wall...
	ofBackground(0);
	
	//====================
	//a white trapezoid...
	//=====================
	
	//Get the width and height of the screen
	int width = ofGetWidth(); //an int is a whole number- 1, 72
	int height = ofGetHeight();
	
	//Get the center of our x-dimention
	//float is short for 'floating point'. 3.141725, 400.0
	//centerX is a float in case I need to divide a non-even number
	float centerX = width/2;
	
	//get the center of y
	float centerY = height/2;
	
	
	//ofGetMouseX() means get the x position of our mouse
	//float centerX = ofGetMouseX();
	// same for Y
	//float centerY = ofGetMouseY();
	
	//set the top width of the trap
	float topWidth = 300;
	
	//set the bottom width of the trap
	float bottomWidth = 600;
	
	//set the height of the trap
	float trapHeight = 500;
	
	//my four points of the trap
	//a vec2 contains an x,y pair denoting a point in 2d space
	glm::vec2 p0;
	glm::vec2 p1;
	glm::vec2 p2;
	glm::vec2 p3;
	
	//set the coord for p0
	p0.x = centerX - topWidth/2;
	p0.y = centerY - trapHeight/2;
	
	//set the coord for p1
	p1.x = centerX + topWidth/2;
	p1.y = centerY - trapHeight/2;
	
	//p2
	p2.x = centerX + bottomWidth/2;
	p2.y = centerY + trapHeight/2;
	
	//p3
	p3.x = centerX - bottomWidth/2;
	p3.y = centerY + trapHeight/2;
	
	
	//now lets draw the line segments for the trap from these 4 points
	//dont fill anything in
	ofNoFill();
	
	//set my "line" color to white
	ofSetColor(255);
	
	//now draw the lines
	ofDrawLine(p0, p1);
	ofDrawLine(p1, p2);
	ofDrawLine(p2, p3);
	ofDrawLine(p3, p0);
	
	//====================================
	//"within which are white vertical parallel lines..."
	//=====================================
	
	//lets create a variable to set the space between the lines;
	//so that a line will be drawn every "spacing" pixels
	int spacing = 8;
	
	//set the coord for where the vertical lines will start and end on the x-axis
	int lineStart = (centerX - bottomWidth/2) + 1;
	int lineEnd = centerX + bottomWidth/2;
	
	//for loop!
	//whatever is inside the brackets gets executed
	//as long as the middle statement is TRUE
	//after we execute the code inside the squiggly braces we incriment x by a certian amount
	// in this case "spacing"
	for(int x = lineStart; x < lineEnd; x += spacing)
	{
		// we will use x to set the x position of our vertical line
		//the lines will start vertically at the top line of the trap
		//and end at the bottom line
		ofDrawLine(x, centerY-trapHeight/2, x, centerY+trapHeight/2);
	}

	//To mask out the parts of the line that are drawn outside the trap
	//we will create 2 triangles that are filled in the same color as the background
	
	ofFill();
	ofSetColor(0);
	//make a mask point from where p3 is on the x-axis
	//and where p0 is on the y-axis
	glm::vec2 maskLeft(p3.x, p0.y);
	ofDrawTriangle(p0, p3, maskLeft);

	//draw the right mask
	glm::vec2 maskRight(p2.x, p1.y);
	ofDrawTriangle(p1, p2, maskRight);
	
	//---------------------------
	//a white square...
	//---------------------------
	
	//set will draw square relative to its center
	//(rather than the defualt which draws from the topleft corner
	ofSetRectMode(OF_RECTMODE_CENTER);
	
	//set the size of the square
	int squareSize = 202;
	
	//create the starting point of the square
	glm::vec2 rectPoint(centerX, centerY);
	
	//draw a square mask! to mask out the lines that would be drawn though the square
	ofFill();
	ofSetColor(0);
	ofDrawRectangle(rectPoint, squareSize, squareSize);
	
	//now draw the square outline!
	ofNoFill();
	ofSetColor(255);
	ofDrawRectangle(rectPoint, squareSize, squareSize);
	
	//--------
	//within which are white horizontal parallel lines...
	//---------
	
	//Where do the horizontal lines start?
	int hLineStart = centerY - squareSize/2;
	//Where do they end?
	int hLineEnd = centerY + squareSize/2;
	
	for(int i = hLineStart; i < hLineEnd; i += spacing)
	{
		ofSetColor(255);
		ofDrawLine(centerX-squareSize/2, i, centerX+squareSize/2, i);
	}
	
	
	
	//The vertical lines within the trapezoid
	//do not enter the square, and the horizontal lines within the square
	//do not enter the trapezoid.
	//===========================
	//Did that already....
	
	///...done
	
}
