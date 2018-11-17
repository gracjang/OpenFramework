#include "ofApp.h"
#define NBALLS 10
//--------------------------------------------------------------
struct Ball {
	ofPoint position;  
	ofPoint force;
	int radius;            
	ofColor color;      
	 
};


Ball groupOfBalls[NBALLS];

//--------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(60);
	for (int i = 0; i < NBALLS; i++) {
		setBall(i);
	}
}

//--------------------------------------------------
void ofApp::update() {
	for (int i = 0; i < NBALLS; i++) {
		groupOfBalls[i].position = groupOfBalls[i].position + groupOfBalls[i].force;
		checkPosition(i);
	}

}

//--------------------------------------------------
void ofApp::draw() {
	for (int i = 0; i < NBALLS; i++) {
		ofSetColor(groupOfBalls[i].color);
		ofDrawCircle(groupOfBalls[i].position, groupOfBalls[i].radius);
	}
}
void ofApp::checkPosition(int i) {
	if ((groupOfBalls[i].position.x - groupOfBalls[i].radius) < 0) {
		groupOfBalls[i].force.x = abs(groupOfBalls[i].force.x);
	}
	if ((groupOfBalls[i].position.y - groupOfBalls[i].radius) < 0) {
		groupOfBalls[i].force.y = abs(groupOfBalls[i].force.y);
	}

	if ((groupOfBalls[i].position.x + groupOfBalls[i].radius) > ofGetWidth()) {
		groupOfBalls[i].force.x = -groupOfBalls[i].force.x;
	}

	if ((groupOfBalls[i].position.y + groupOfBalls[i].radius) > ofGetHeight()) {
		groupOfBalls[i].force.y = -groupOfBalls[i].force.y;
	}
}
void ofApp::setBall(int i) {
	groupOfBalls[i].color = ofColor::fromHsb(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255));
	groupOfBalls[i].force.x = ofRandom(-8, 8);
	groupOfBalls[i].force.y = ofRandom(-8, 8);
	groupOfBalls[i].radius = ofRandom(10, 30);
	groupOfBalls[i].position.x = ofRandom(0,ofGetWidth() - groupOfBalls[i].radius);
	groupOfBalls[i].position.y = ofRandom(0, ofGetHeight() - groupOfBalls[i].radius);
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
