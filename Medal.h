#pragma once

#include "BoundingBox.h"
#include <glut.h>

class Medal : public BoundingBox {
private:
	Vector3f position;
	Vector3f size;
	int angle;

	void drawMedal(float xPosition, float yPosition, float zPosition);

	void drawOlympicMedal(float xPosition, float yPosition, float zPosition);

public:
	Medal(Vector3f& position, Vector3f& size);

	void draw();

	void animate();

};