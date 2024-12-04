#pragma once

#include <glut.h>

class Podium {
public:
	Podium();
	void draw();
	void animate();

private:
	float scaleFactors[3] = { 1.0f, 1.0f, 1.0f };
	float scaleSpeed[3] = { 0.005f, 0.007f, 0.006f };
	float scaleDirection[3] = { 1.0f, 1.0f, 1.0f };
	void drawPodium(float xPosition, float yPosition, float zPosition);
};