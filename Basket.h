#pragma once

#include <glut.h>

class Basket {

public:
	void draw();
	void animate();

private:
	float basketColorR = 1.0f, basketColorG = 1.0f, basketColorB = 1.0f;
	float colorChangeSpeed = 0.01f;
	void drawBackboard(float xPosition);
	void drawHoop(float xPosition, float zPosition);
	void drawPole(float xPosition, float zPosition);
};