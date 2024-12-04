#pragma once

#include <glut.h>

class Bench {

private:
	float benchOffset = 0.0f;
	float benchSpeed = 0.05f;
	float benchDirection = 1.0f;
public:
	Bench();
	void draw();
	void drawBench(float xPosition, float zPosition);
	void animate();
};