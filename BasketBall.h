#pragma once

#include "BoundingBox.h"
#include <glut.h>

class BasketBall : public BoundingBox {
	

private:
	float xPosition;
	float zPosition;
	int angle;

	void drawBasketball(float xPosition, float yPosition, float zPosition);

public:
	BasketBall(float xPosition, float zPosition);
	void draw();

	void animate();
};