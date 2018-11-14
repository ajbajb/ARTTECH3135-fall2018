#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
    
    ofGLFWWindowSettings settings;
    settings.setGLVersion(3, 2);
    settings.decorated = true;
    settings.setSize(1024, 768);
    settings.setPosition({0, 0});
    ofCreateWindow(settings);
    
	ofRunApp(new ofApp());
}
