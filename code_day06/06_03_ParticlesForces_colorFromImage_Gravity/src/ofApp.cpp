#include "ofApp.h"

// NET force equals mass times acceleration
// drag force = (velocity * velocity) * dragCo * (velocity.normalized) * -1
// gravity force =
// ( gravityCo * mass1 * mass2 / (distance * diastance) ) * normralized(attractor position - particle position)
//--------------------------------------------------------------
void ofApp::setup()
{
	image.load("Fairytale.jpg");
	
	for( int y = 0; y < image.getHeight(); y += 6)
	{
		for( int x = 0; x < image.getWidth(); x += 6)
		{
			ofColor pixelColor;
			pixelColor = image.getColor(x, y);
			
			Particle p;
			p.position = glm::vec3(x, y, 0);
			p.velocity = glm::vec3(0.001, 0, 0);
			p.radius = ofRandom(2, 6);
			p.color = ofColor(pixelColor, 50);
			
			particles.push_back(p);
		}
	}
}

//--------------------------------------------------------------
void ofApp::update()
{
	glm::vec3 mousePos(ofGetMouseX(), ofGetMouseY(), 0);
	
	for (auto &p : particles)
	{
		// a drag force=============================================
		float dragCo = 0.04;
		glm::vec3 dragMagnitude = (p.velocity * p.velocity) * dragCo;
		glm::vec3 dragDirection = glm::normalize(p.velocity) * -1;
		glm::vec3 drag = dragMagnitude * dragDirection;
		// ==========================================================
		
		
		//===our own "not so great" gravity========================
		glm::vec3 gravityForce;
		
		float distance = glm::distance(mousePos, p.position);
		glm::vec3 directionVec = mousePos - p.position;
		glm::vec3 direction = glm::normalize(directionVec);
		
		float magnitude = distance * 0.02;
		gravityForce = magnitude * direction * forceDirection;
		// ===================================================
		
		glm::vec3 awesomeGravityForce;
		
		awesomeGravityForce = computeGravity(p, mousePos) * forceDirection;
		
		if (ofGetMousePressed())
		{
			p.applyForce(awesomeGravityForce);
		}
		
		p.applyForce(drag); //apply drag every frame
		p.update();
	}
}
//=====end-of=update=========

//==our gravity function==============================================
glm::vec3 ofApp::computeGravity(Particle &part, glm::vec3 &attractor)
{
	float gravityConst = 10;
	
	// get the direction (normalized vector) form particle to attractor
	glm::vec3 direction = glm::normalize(attractor - part.position);
	
	// get the distance from attractor to particle
	float distance = glm::distance(attractor, part.position);
	// clamp it!
	distance = ofClamp(distance, 5, 25);
	
	// compute the magnitude of the force using the mass of the particle and gravity constant
	float magnitude = (gravityConst * part.mass) / (distance * distance);
	
	// a force has direction and magnitude
	glm::vec3 gravity = direction * magnitude;

	return gravity;
}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofEnableBlendMode(OF_BLENDMODE_ADD);
	ofBackground(0);
	
	// loop through all our particels YAYAYAYAYAYA
	
	//range for loop!!!!!
	for (auto &p : particles)
	{
		p.draw();
	}
	
	ofPushStyle();
	ofSetColor(255);
	
	string frameString = "FrameRate= " + ofToString(ofGetFrameRate());
	ofDrawBitmapString(frameString, 20, 20);
	
	string particleString = "Particle Number= " + ofToString(particles.size());
	ofDrawBitmapString(particleString, 20, 40);
    
    string infoStr = "Press 'q' for gravity. 'w' for repulsion. Space to start over";
    ofDrawBitmapString(infoStr, 20, ofGetHeight() - 20);
    
	ofPopStyle();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	if (key == 'q')
	{
		forceDirection = 1;
	}
	
	if (key == 'w')
	{
		forceDirection = -1;
	}
	
    if (key == ' ')
    {
        // clear all particles!
        particles.clear();
        
        // make "new" ones at start locations
        for( int y = 0; y < image.getHeight(); y += 6)
        {
            for( int x = 0; x < image.getWidth(); x += 6)
            {
                ofColor pixelColor;
                pixelColor = image.getColor(x, y);
            
                Particle p;
                p.position = glm::vec3(x, y, 0);
                p.velocity = glm::vec3(0.001, 0, 0);
                p.radius = ofRandom(2, 6);
                p.color = ofColor(pixelColor, 50);
            
                particles.push_back(p);
            }
        }
    
        ofLog() << particles.size();
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
