#include "CenterBall.h"



CenterBall::CenterBall()
{
	position.x = ofGetWidth() / 2;
	position.y = ofGetHeight() / 2;
	radius = 30;
	color = ofColor::black;
}


CenterBall::~CenterBall()
{
}
