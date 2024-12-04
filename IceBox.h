#pragma once
#include "Vector3f.h"
#include <glut.h>

class IceBox {
private:
	Vector3f position;
	float yOffset = 0.18f;
	float ySpeed = 0.01f;
	int direction = 1;
public:
	IceBox();

	void draw();

	void drawIcebox(float xPosition, float yPosition, float zPosition);

	void animate();
};