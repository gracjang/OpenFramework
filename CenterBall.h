#pragma once
#include "ofMain.h"
class CenterBall
{
public:
	CenterBall();
	ofPoint position;
	ofPoint force;
	int radius;
	ofColor color;
	~CenterBall();
};

