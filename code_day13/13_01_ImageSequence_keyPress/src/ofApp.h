#pragma once

#include "ofMain.h"

// creates an image sequence that can be made into moive
// either through Quicktime (i hope still ) or running th ffmpeg command -
// ffmpeg -i FRAME_%04d.png -vcodec libx264 -vf format=yuv420p movie.mp4

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    ofVideoGrabber grabber;
    
    bool isRecording = false;
    
    std::vector<ofPixels> frames;
    
		
};
