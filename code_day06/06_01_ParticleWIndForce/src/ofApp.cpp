#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    // make few or mke many
    int NUM_PARTICLES = 200;
    
	for (int i = 0; i < NUM_PARTICLES; i++)
	{
		Particle tempP;
		tempP.position = glm::vec3(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), 0);
		tempP.acceleration = glm::vec3(ofRandom(0.2), ofRandom(0.2), 0);
		tempP.color = ofColor(ofRandom(255), ofRandom(255), ofRandom(255), 137);
		tempP.radius = ofRandom(3, 25);
		
		particles.push_back(tempP);
	}
}

//--------------------------------------------------------------
void ofApp::update()
{
	glm::vec3 persistForce(0.05, 0.03, 0);
	glm::vec3 windForce(0, 0, 0);
	
	//range for loop to interate over all our elements in particles
	for (auto &p : particles)
	{
        // the wind only "blows" when we press the mouse
        // and only applied then also
		if (ofGetMousePressed())
		{
			bWind = true;
			
			windForce = glm::vec3(-0.55, -0.65, 0);
			
			p.applyForce(windForce);
		}
	
		p.applyForce(persistForce);
		
		// check right
		if (p.position.x + p.radius > ofGetWidth())
		{
            p.acceleration.x *= -1;
			p.velocity.x *= -1;
			p.position.x = ofGetWidth() - p.radius;
		}
		
		// check left
		if (p.position.x - p.radius < 0)
		{
            p.acceleration.x *= -1;
			p.velocity.x *= -1;
			p.position.x = 0 + p.radius;
		}
		
		// check top
		if (p.position.y - p.radius < 0)
		{
			p.acceleration.y *= -1;
			p.velocity.y *= -1;
			p.position.y = 0 + p.radius;
		}
		
		// check bottom
		if (p.position.y + p.radius > ofGetHeight())
		{
			p.acceleration.y *= -1;
			p.velocity.y *= -1;
			p.position.y = ofGetHeight() - p.radius;
		}
		
		p.update();
	
//		ofLog() << "accel= " << p.acceleration;
//		ofLog() << "velo= " << p.velocity;
	}
}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofBackground(40);
	
	// with range for loop
	// you create a varible called p
	for (auto &p : particles)
	{
		p.draw();
	}
	
	// "normal" for-loop
//    for( int i= 0; i < particles.size(); i++)
//    {
//        particles[i].draw;
//    }
	
	if(bWind)
	{
		ofPushStyle();
		ofSetColor(255, 0, 255);
		
		ofDrawBitmapString("WIND!!!!!", ofGetWidth()/2, ofGetHeight()/2);
		ofPopStyle();
	}
	
	bWind = false;
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
