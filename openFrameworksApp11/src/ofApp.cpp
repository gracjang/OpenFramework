#include "ofApp.h"
#define NBALLS 15  // declarate count of balls, global variable !
/* Struct of Ball */

struct Ball {
	ofPoint position;  
	ofPoint force;
	ofPoint velocity;
	ofPoint acceleration;
	int mass;
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
		//RepulsionForce(i, 30, 0.4);
		groupOfBalls[i].acceleration = groupOfBalls[i].force / groupOfBalls[i].mass;
		groupOfBalls[i].velocity = groupOfBalls[i].velocity + groupOfBalls[i].acceleration * delaTime;
		groupOfBalls[i].position = groupOfBalls[i].position + groupOfBalls[i].velocity * delaTime;
		SetAreoDynamicForce(i);
		groupOfBalls[i].velocity += (groupOfBalls[i].areoForce /groupOfBalls[i].mass) * delaTime;
		checkPosition(i);

		/*
		-------------- BLOCK OF EXERCIES 3 ----------------------
		
		SetAreoDynamicForce(i);
		
		
		*/

		

	}

}

//--------------------------------------------------
void ofApp::draw() {
	
	for (int i = 0; i < NBALLS; i++) {
		ofSetColor(groupOfBalls[i].color);
		ofDrawCircle(groupOfBalls[i].position, groupOfBalls[i].radius);
	}
	
	ofSetColor(World.color);
	ofDrawCircle(World.position, World.radius);

	
}

/* Check if statment for ball and touch a max and min value of screen size */
void ofApp::checkPosition(int i) {
	if ((groupOfBalls[i].position.x - groupOfBalls[i].radius) < 0) {
		groupOfBalls[i].velocity.x = abs(groupOfBalls[i].velocity.x);
	}
	if ((groupOfBalls[i].position.y - groupOfBalls[i].radius) < 0) {
		groupOfBalls[i].velocity.y = abs(groupOfBalls[i].velocity.y);
	}

	if ((groupOfBalls[i].position.x + groupOfBalls[i].radius) > ofGetWidth()) {
		groupOfBalls[i].velocity.x = -(groupOfBalls[i].velocity.x);
	}

	if ((groupOfBalls[i].position.y+ groupOfBalls[i].radius) > ofGetHeight()) {
		groupOfBalls[i].velocity.y = -(groupOfBalls[i].velocity.y);
	}
}

/* SET AREO DYNAMIC FORCE */
void ofApp::SetAreoDynamicForce(int i) {

	groupOfBalls[i].areoForce = -6 * PI * groupOfBalls[i].velocity * groupOfBalls[i].radius * 0.01 ;
}

/* Properties of Balls ( everything is random ) - every ball is unique */
void ofApp::setBall(int i) {
	groupOfBalls[i].color = ofColor::fromHsb(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255));
	groupOfBalls[i].mass = ofRandom(1, 5);
	groupOfBalls[i].velocity.x = ofRandom(10, 800);
	groupOfBalls[i].velocity.y = ofRandom(10, 800);
	groupOfBalls[i].radius = ofRandom(5, 18);
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
	diff.normalize();
	float length = diff.length(); 
	ofPoint gravityForce;
		gravityForce = 4210 * (1 / (length*length)) * diff;
	
	groupOfBalls[i].force = gravityForce - groupOfBalls[i].acceleration;
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


// Fq = A * 1/d^2 * r^2;
// V = V + (Fg/m * dT);  (acceleration);
// position = position + position + v *dT; 
// v- wektor
// a = G * m1*m2
// Fg = wektor