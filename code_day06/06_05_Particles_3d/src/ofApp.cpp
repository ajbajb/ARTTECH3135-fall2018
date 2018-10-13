#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    ofTexture tex0;
    ofTexture tex1;
    ofTexture tex2;
    ofTexture tex3;
    ofTexture tex4;
    ofTexture tex5;
    ofTexture tex6;
    ofTexture tex7;
    ofTexture tex8;
    ofTexture tex9;
    ofTexture tex10;
    ofTexture tex11;
    ofTexture tex12;
    
    ofLoadImage(tex0, "emoji0.png");
    ofLoadImage(tex1, "emoji1.png");
    ofLoadImage(tex2, "emoji2.png");
    ofLoadImage(tex3, "emoji3.png");
    ofLoadImage(tex4, "emoji4.png");
    ofLoadImage(tex5, "emoji5.png");
    ofLoadImage(tex6, "emoji6.png");
    ofLoadImage(tex7, "emoji7.png");
    ofLoadImage(tex8, "emoji8.png");
    ofLoadImage(tex9, "emoji9.png");
    ofLoadImage(tex10, "emoji10.png");
    ofLoadImage(tex11, "emoji11.png");
     ofLoadImage(tex12, "emoji12.png");
    
    std::vector<ofTexture> textures = {tex0, tex1, tex2, tex3, tex4, tex5, tex6,
                                        tex7, tex8, tex9, tex10, tex11, tex12};
    
//    // loading the textures can be done iteratively
//    // using ofDirectory and a for-loop
//    // (this is assuming all the textures are in bin/data folder)
//
//    ofDirectory textureDirectory("");
//    textureDirectory.allowExt("png"); // only allow .png files
//    textureDirectory.listDir();   // populate the ofDirectory object with the file names
//
//    for (int i = 0; i < textureDirectory.size(); i++)
//    {
//        ofLog() << textureDirectory.getPath(i);
//
//        ofTexture texture;
//        ofLoadImage(texture, textureDirectory.getPath(i));
//
//        textures.push_back(texture);
//    }
    
    
	aForce = glm::vec3(0., 0., 0.);
	
	for (int i = 0; i < 500; i++)
	{
        int randomTextureIndex = ofRandom(textures.size());
        
		Particle3D p;
		p.applyForce(aForce);
        p.tex = textures[randomTextureIndex];
        
		particles.push_back(p);
	}
    
    boundingBox = {500, 500, 500};
    cam.setScale(1, -1, 1);
}

//--------------------------------------------------------------
void ofApp::update()
{
	for (auto &p : particles)
	{
		p.applyDrag(globalDrag);
		p.update();
		p.checkBounds(boundingBox);
	}
}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofBackground(20);
	
	cam.begin();
	for (auto &p : particles)
	{
        p.bDrawAxis = bDrawDebug;
		p.draw();
	}
	
	if (bDrawDebug)
	{
		ofDrawAxis(550);
		ofPushStyle();
		ofSetColor(255, 0, 0, 25);
		ofDrawBox(boundingBox.x, boundingBox.y, boundingBox.z);
		ofPopStyle();
	}
	
	cam.end();
    
    string infoStr = "'f' to apply a force. 'd' for debug";
    string camStr = "click and drag to move camera. Two finge scroll to zoom in/out";
    ofDrawBitmapString(infoStr, 20, 20);
    ofDrawBitmapString(camStr, 20, 40);
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	if (key == 'd')
	{
		bDrawDebug =! bDrawDebug;
	}
	
	if (key == 'f')
	{
		for (auto &p : particles)
		{
			aForce.x = ofRandom(-10, 10);
			aForce.y = ofRandom(-10, 10);
			aForce.z = ofRandom(-10, 10);
			p.applyForce(aForce);
		}
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
