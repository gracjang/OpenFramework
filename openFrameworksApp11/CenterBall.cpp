#include "CenterBall.h"



CenterBall::CenterBall()
{
	position.x = ofGetWidth() / 2;
	position.y = ofGetHeight() / 2;
	radius = 10;
	mass = 2000;
	color = ofColor::black;
}


CenterBall::~CenterBall()
{
}
