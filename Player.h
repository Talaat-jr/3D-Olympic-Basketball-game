#pragma once

#include "BoundingBox.h"
#include <glut.h>

class Player : public BoundingBox{
private:
	Vector3f position;
	Vector3f size;
	int angle;
	bool isHero;
	int score;

	void drawPlayer(float xPosition, float zPosition);
public:
	Player(float xPosition, float zPosition, bool isHero);

	void draw();

	void move(float x, float z);

	void rotateY();

	void applayRotation();

	void animate();

	int getScore();

	void incrementScore();

	void setAngle(int angle);
};