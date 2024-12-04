#pragma once

#include "utils.h"
#include <glut.h>

class Ground {

private:
	float x;
	float z;
	float width;
	float length;

public:
	Ground();

	void draw();

	void drawCourtFloor();

	void drawCourtLines();
};