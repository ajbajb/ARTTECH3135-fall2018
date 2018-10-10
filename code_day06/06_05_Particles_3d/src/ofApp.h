#pragma once

#include "ofMain.h"
#include "Particle3D.h"

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
	
	std::vector<Particle3D> particles;
	std::vector<ofTexture> textures;
	
	glm::vec3 boundingBox;
	glm::vec3 aForce;
	float globalDrag = 0.1;
	ofEasyCam cam;
	
	bool bDrawDebug = false;
		
};
