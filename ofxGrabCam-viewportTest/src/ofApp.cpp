#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	for (int i=0; i<100; i++)
	{
		positions.push_back(glm::vec3(ofRandom(-10, 10),
									ofRandom(-10, 10),
									ofRandom(-10, 10)));
		
		colours.push_back(ofColor(ofRandom(100) + 100,
								  ofRandom(100) + 100,
								  ofRandom(100) + 100));
	}
	
	ofBackground(100, 100, 100);
	ofEnableSmoothing();
	
	// You might need to do this in the future if openFrameworks changes currently it's done automatically in the constructor, but this may be too early for openFrameworks (if the current situation changes)
	// camera.init();
	
	randomiseViewport();
	useViewport = false;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	////
	//draw scene
	if (useViewport)
		camera.begin(viewport);
	else
		camera.begin();
	ofSetColor(255,100,100);
	ofDrawGrid(10.0f, 5.0f, true);
	
	auto p = positions.begin();
	auto c = colours.begin();
	for (; p != positions.end(); p++, c++)
	{
		ofSetColor(*c);
		ofDrawSphere(p->x, p->y, p->z, 1);
	}
	//demonstrate resiliance to stray matrices
	ofRotateDeg(ofRandom(360), 0, 1, 0);
	camera.end();
	//
	////

	if (useViewport) {
		ofPushStyle();
		ofSetColor(255,255,255);
		ofNoFill();
		ofDrawRectangle(viewport);
		ofPopStyle();
	}
	
	ofSetColor(0,0,0);
	
	int row = 1;
	ofDrawBitmapString("ofxGrabCam", 10, row++ * 15);
	ofDrawBitmapString("Drag with left mouse to orbit", 10, row++ * 15);
	ofDrawBitmapString("Drag with right mouse to zoom", 10, row++ * 15);
	ofDrawBitmapString("Hold 'h' and drag with left mouse to pan", 10, row++ * 15);
	ofDrawBitmapString("Press 'r' to reset", 10, row++ * 15);

	row++;
	
	ofDrawBitmapString("This example", 10, row++ * 15);
	ofDrawBitmapString("Press 'c' to toggleCursorDraw", 10, row++ * 15);
	ofDrawBitmapString("Press 'u' to  toggleFixUpwards", 10, row++ * 15);
	ofDrawBitmapString("Press [SPACE] to randomise viewport", 10, row++ * 15);
	ofDrawBitmapString("Press [v] to toggle viewport " + (useViewport ? string("[x]") : string("[ ]")), 10, row++ * 15);
	
	//demonstrate resiliance to stray matrices
	ofRotateDeg(ofRandom(360), 0, 1, 0);
	ofScale(ofRandom(30), ofRandom(30));
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	
	if (key==' ')
		randomiseViewport();
	
	if (key=='v')
		useViewport ^= true;
	
	if (key=='c')
		camera.toggleCursorDrawEnabled();
	
	if (key=='u')
		camera.toggleFixUpDirectionEnabled();
	
}
//--------------------------------------------------------------
void ofApp::randomiseViewport() {
	viewport.x = ofRandom(0,ofGetWidth()/2);
	viewport.y = ofRandom(0,ofGetHeight()/2);
	viewport.width = ofRandom(256, ofGetWidth() - viewport.x);
	viewport.height = ofRandom(256, ofGetHeight() - viewport.y);
}

