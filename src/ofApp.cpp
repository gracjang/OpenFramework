#include "ofApp.h"
#define NBALLS 1000  // declarate count of balls, global variable !
/* Struct of Ball */

struct Ball {
	ofPoint position;  
	ofPoint force;
	int radius;            
	ofColor color;      
	ofPoint areoForce;
};


Ball groupOfBalls[NBALLS];

//--------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(60);
	/*Create a balls*/
	for (int i = 0; i < NBALLS; i++) {
		setBall(i);
	}
}

//--------------------------------------------------
void ofApp::update() {
	for (int i = 0; i < NBALLS; i++) {
		
		groupOfBalls[i].position = groupOfBalls[i].position + groupOfBalls[i].force;
		checkPosition(i);

		/*
		-------------- BLOCK OF EXERCIES 3 ----------------------
		
		SetAreoDynamicForce(i);
		groupOfBalls[i].position += groupOfBalls[i].areoForce;
		
		*/

		/* BLOCK OF EXERCISE 4 (UNComment create black ball in center -> method draw() )

			RepulsionForce(i, 30, 0.4)
		
		*/
			

		

		
	}

}

//--------------------------------------------------
void ofApp::draw() {
	
	for (int i = 0; i < NBALLS; i++) {
		ofSetColor(groupOfBalls[i].color);
		ofDrawCircle(groupOfBalls[i].position, groupOfBalls[i].radius);
	}
	
	/* CREATE BLACK BALL IN CENTER OF WINDOW ( EXERCISE 4 )
	

	ofSetColor(World.color);
	ofDrawCircle(World.position, World.radius);

	*/
}

/* Check if statment for ball and touch a max and min value of screen size */
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

/* SET AREO DYNAMIC FORCE */
void ofApp::SetAreoDynamicForce(int i) {

	groupOfBalls[i].areoForce = -6 * PI * groupOfBalls[i].force * groupOfBalls[i].radius * 0.02 * 0.004;
}

/* Properties of Balls ( everything is random ) - every ball is unique */
void ofApp::setBall(int i) {
	groupOfBalls[i].color = ofColor::fromHsb(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255));
	groupOfBalls[i].force.x = ofRandom(-20, 8);
	groupOfBalls[i].force.y = ofRandom(-20, 8);
	groupOfBalls[i].radius = ofRandom(3, 18);
	groupOfBalls[i].position.x = ofRandom(0,ofGetWidth() - groupOfBalls[i].radius);
	groupOfBalls[i].position.y = ofRandom(0, ofGetHeight() - groupOfBalls[i].radius);
	
}

// --------------------------------------------------------------


/* RepulsionForce to center */
void ofApp::RepulsionForce(int i, int radius, float scale) {
	ofVec2f mWorld;
	ofVec2f Object;
	Object.set(groupOfBalls[i].position.x, groupOfBalls[i].position.y);
	mWorld.set(World.position.x , World.position.y);
	ofVec2f diff = mWorld - Object;
	float length = diff.length(); 
		float stronger = 1 - (length / radius);
		diff.normalize();
		groupOfBalls[i].force.x = (groupOfBalls[i].force.x / length) + diff.x;
		groupOfBalls[i].force.y = (groupOfBalls[i].force.y / length) + diff.y;
		if (length < 1) {
			groupOfBalls[i].force.x = 0;
			groupOfBalls[i].force.y = 0;
	
		}
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
