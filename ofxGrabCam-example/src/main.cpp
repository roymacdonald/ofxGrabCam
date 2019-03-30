#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
	ofGLWindowSettings settings;
	settings.setGLVersion(3,2);
	settings.setSize(1280, 1024);
	settings.windowMode = OF_WINDOW;

    ofCreateWindow(settings);			// <-------- setup the GL context


	ofRunApp(new ofApp());
}
