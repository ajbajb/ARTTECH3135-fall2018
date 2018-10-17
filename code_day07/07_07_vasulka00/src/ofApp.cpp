#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	std::vector<ofVideoDevice> devices = grabber.listDevices();
	if (devices.size() > 0)
	{
		for (auto device : devices)
		{
			if (device.bAvailable)
			{
				ofLog() << device.id << ": " << device.deviceName;
			}
		}
	}
	else
	{
		ofLog() << "No devies found!";
	}
	
	grabber.setDeviceID(1);
	grabber.setup(640, 480);
	grabberWidth = grabber.getWidth();
	grabberHeight = grabber.getHeight();
	
	lines.resize(grabberHeight/spacing);
	
	// add a polyline for everyline of the screen
	for (std::size_t y = 0; y < grabberHeight; y += spacing)
	{
		ofPolyline line;
		lines.push_back(line);
	}
	
	tex.allocate(grabberWidth, grabberHeight, GL_RGBA);
	
	gui.setup();
	gui.add(threshold.set("threshold", 100.0, 0.0, 255.0));
	gui.add(scale.set("height scale", 0.0, 0.0, 1.0));
	gui.add(smooth.set("smoothing", 2, 0, 20));
	bDrawGui = true;
	
}

//--------------------------------------------------------------
void ofApp::update()
{
	grabber.update();
	
	if (grabber.isFrameNew())
	{
		// clear the vertices in the polylines
		for (auto& line : lines)
		{
			line.clear();
		}
		
		// get the camera  pixels
		ofPixels pix = grabber.getPixels();
		
		for (std::size_t y = 0; y < grabberHeight; y += spacing)
		{
			for (std::size_t x = 0; x < grabberWidth; x++)
			{
				float brightness = pix.getColor(x, y).getBrightness();
				
				if (brightness > threshold)
				{
					// add vertex to that lines polyline
					// at the place
					int index = y/spacing;
					lines[index].addVertex(x, y - (brightness * scale));
				}
			}
		}
	}

}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofBackground(0);
	ofBlendMode(OF_BLENDMODE_ADD);
	
	ofSetColor(255, 80);
	ofSetLineWidth(3);
	ofPushMatrix();
		ofTranslate(150, 250);
		for (auto& line : lines)
		{
			line = line.getSmoothed(smooth);
			line.draw();
		}
	ofPopMatrix();
	
	
	
	if (bDrawGui)
	{
		ofSetColor(255);
		string frameStr = "Framerate:: " + ofToString(ofGetFrameRate());
		ofDrawBitmapString(frameStr, ofGetWidth() - 200, 20);
		gui.draw();
	}

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	if(key == 'g')
	{
		bDrawGui =! bDrawGui;
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
