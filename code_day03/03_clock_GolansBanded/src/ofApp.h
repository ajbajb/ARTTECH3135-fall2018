#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
	
		void updateClock();
		void drawClock();

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
	
		std::vector<int> sColors;
		std::vector<int> mColors;
		std::vector<int> hColors;
	
				int ySec0;
				int ySec1;
				int yMin0;
				int yMin1;
				int yHour0;
				int yHour1;
				
				int mil, sec, minut, hr;
				
				int width;
				int height;
				
	
	
		
};
