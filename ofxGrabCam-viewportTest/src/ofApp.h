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
	struct Sphere{
		glm::vec3 position;
		ofColor color;
	};
	vector<Sphere> spheres;
	//
	////
	
	bool useViewport;
	ofRectangle viewport;
};
