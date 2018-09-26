#include "ofApp.h"

//--------------------------------------------------------------

// important things for vector
// 1. getting the value at the index with [index]
// 2. using push_back(value) to ADD to the end of the vector
// 3. getting the size of the vector with .size()
// 4. clearing the vector with .clear()
// 5. making sure you can declare a vector

void ofApp::setup()
{
	
	// a generating 100 random numbers
	// adn putting them into myNumber vector
	for (int i = 0; i < 100; i++)
	{
		int randomNumber = ofRandom(255); // generate a reandom #, store it in the variable
		
		myNumbers.push_back(randomNumber);  // put that number in myNumbers
		
		// .push_back() will put the number at the end of our vector
		
	}
	
	// for however large my vector is print out the number at that index
//	for (int i = 0; i < myNumbers.size(); i++)  //size() returns how many elements are in the vector
//	{
//		std::cout << "Number at index " << i << "= " << myNumbers[i] <<std::endl;  // access the elements with the [index we want]
//	}
	int i = 2;
	std::cout << "Number at index " << i << "= " << myNumbers[i] <<std::endl;
	

}

//--------------------------------------------------------------
void ofApp::update()
{

}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofBackground(50);
	for (int i = 0; i < myNumbers.size(); i++)
	{
		int hue = myNumbers[i];  //setting the hue from the myNumbers array
		// std::cout << hue << std::endl;
		
		
		ofSetColor(ofColor::fromHsb(hue, 255, 255));
		ofFill();
		ofDrawCircle(i*8, 200, 5);
	}

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	//whenever I press a key I will generate 100 new randomNumbers
	string print = "new numbers";
	ofLog() << print;
	
	// option 1
	// we can either clear the vector and push_back new numbers
	myNumbers.clear();
	for (int i = 0; i < 100; i++)
	{
		int randomNumber = ofRandom(255);
		
		myNumbers.push_back(randomNumber);  // and push them back into my number vector
	}
	
	//option 2
	// we can replace every value at that index
//	for (int i = 0; i < 100; i++)
//	{
//		int randomNumber = ofRandom(255);
//		myNumbers[i] = randomNumber;
//	}

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
