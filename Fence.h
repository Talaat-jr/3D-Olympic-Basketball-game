#pragma once

#include <cmath>
#include <glut.h>

class Fence {

public:
	Fence();
	void draw();
	void animate();

private:
	float animationFactor;
	void drawFence();
	void drawFence2();
};