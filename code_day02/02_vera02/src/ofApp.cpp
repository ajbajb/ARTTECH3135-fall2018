#include "ofApp.h"

//--Vera-Molnar-Disparation-1989-------------------------------
//--http://dada.compart-bremen.de/item/artwork/130 //----------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofSeedRandom(ofGetMouseX());
	
	ofPath path;
	path.setFilled(false);
	path.setStrokeColor(0);
	path.setStrokeWidth(2);
	
	int border = 12;
	int drawingWidth = ofGetWidth()-(border*2);
	int drawingHeight = ofGetHeight()-(border*2);
	
	path.moveTo(border, border);
	path.lineTo(drawingWidth, border);
	path.lineTo(drawingWidth, drawingHeight);
	path.lineTo(border, drawingHeight);
	path.lineTo(border, border);
	
	float xSpacing = drawingWidth/9.0;
	float ySpacing = drawingHeight/9.0;
	
	int lineNumber = 1;
	for(int y = 0; y<drawingHeight-ySpacing; y+=ySpacing)
	{
		int linePoints = ofMap(lineNumber, 1, 9, 15, 3);
		
		for(int x = 0; x<drawingWidth-xSpacing; x+=xSpacing)
		{
			path.moveTo(ofRandom(border+x, xSpacing+x), ofRandom(border+y,ySpacing+y));
		
			for(int i=0; i<linePoints; i++)
			{
				path.lineTo(ofRandom(x, xSpacing+x), ofRandom(y, ySpacing+y));
			}
		}
		
		lineNumber += 1;
	}
	
	path.draw();
}

//--------------------------------------------------------------

