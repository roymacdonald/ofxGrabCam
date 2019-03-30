#pragma once

#include "ofMain.h"

#include "ofxGrabCam.h"

class ofApp : public ofBaseApp{

public:
	void setup();
	void update();
	void draw();

	void keyPressed  (int key);
	void randomiseViewport();
	
	ofxGrabCam camera;
	
	////
	//scene
	vector<glm::vec3> positions;
	vector<ofColor> colours;
	//
	////
	
	bool useViewport;
	ofRectangle viewport;
	ofMatrix4x4 savedPose;
};
