#include "Player.h"
#include <iostream>

Player::Player(float xPosition, float zPosition, bool isHero)
	: BoundingBox(Vector3f(xPosition, 0, zPosition), Vector3f(1, 1.8, 1)), position(Vector3f(xPosition, 0, zPosition)), angle(0), score(0), isHero(isHero) {};

void Player::draw() {
	glPushMatrix();
	glTranslated(position.x, 0, position.z);
	applayRotation();
	glTranslated(-position.x, 0, -position.z);
	drawPlayer(position.x, position.z);

	glPopMatrix();
}

void Player::move(float x, float z) {
	position.x += x;

	if (position.x >= 14)
		position.x = 14;
	else if (position.x <= -14)
		position.x = -14;

	BoundingBox::position.x = position.x;

	position.z += z;

	if (position.z >= 15/2)
		position.z = 15/2;
	else if (position.z <= -15/2)
		position.z = -15/2;

	BoundingBox::position.z = position.z;
}

void Player::rotateY() {
	angle += 90;
}

void Player::setAngle(int angle) {
	this->angle = angle;
}

void Player::applayRotation() {
	glRotatef(angle, 0, 1, 0);
}

void Player::animate() {
	angle += 2;
}

void Player::incrementScore() {
	score++;
}

int Player::getScore() {
	return score;
}

void Player::drawPlayer(float xPosition, float zPosition) {
	// Define colors based on the isHero flag
	float skinColors[2][3] = { {1.0f, 0.8f, 0.6f},{0.4f, 0.2f, 0.1f} };
	float torsoColors[2][3] = { {0.1f, 0.1f, 0.8f},{0.8f, 0.1f, 0.1f} };
	float shortsColors[2][3] = { {0.2f, 0.2f, 0.2f},{1.0f, 1.0f, 1.0f} };

	// Head
	glPushMatrix();
	glTranslatef(xPosition, 1.6f, zPosition);
	glColor3fv(skinColors[isHero ? 0 : 1]); // Use skin color
	glutSolidSphere(0.2f, 20, 20);
	glPopMatrix();

	// Torso
	glPushMatrix();
	glTranslatef(xPosition, 1.2f, zPosition);
	glScalef(0.4f, 0.5f, 0.2f);
	glColor3fv(torsoColors[isHero ? 0 : 1]); // Use torso color
	glutSolidCube(1.0f);
	glPopMatrix();

	// Lower Torso (Shorts)
	glPushMatrix();
	glTranslatef(xPosition, 0.9f, zPosition);
	glScalef(0.35f, 0.3f, 0.2f);
	glColor3fv(shortsColors[isHero ? 0 : 1]); // Use shorts color
	glutSolidCube(1.0f);
	glPopMatrix();

	// Left Arm
	glPushMatrix();
	glTranslatef(xPosition - 0.3f, 1.2f, zPosition);
	glRotatef(15, 1, 0, 0);
	glScalef(0.1f, 0.4f, 0.1f);
	glColor3fv(skinColors[isHero ? 0 : 1]); // Use skin color
	glutSolidCube(1.0f);
	glPopMatrix();

	// Right Arm
	glPushMatrix();
	glTranslatef(xPosition + 0.3f, 1.2f, zPosition);
	glRotatef(-15, 1, 0, 0);
	glScalef(0.1f, 0.4f, 0.1f);
	glColor3fv(skinColors[isHero ? 0 : 1]); // Use skin color
	glutSolidCube(1.0f);
	glPopMatrix();

	// Left Leg
	glPushMatrix();
	glTranslatef(xPosition - 0.15f, 0.45f, zPosition);
	glScalef(0.15f, 0.6f, 0.15f);
	glColor3fv(skinColors[isHero ? 0 : 1]); // Use skin color
	glutSolidCube(1.0f);
	glPopMatrix();

	// Right Leg
	glPushMatrix();
	glTranslatef(xPosition + 0.15f, 0.45f, zPosition);
	glScalef(0.15f, 0.6f, 0.15f);
	glColor3fv(skinColors[isHero ? 0 : 1]); // Use skin color
	glutSolidCube(1.0f);
	glPopMatrix();

	// Left Foot
	glPushMatrix();
	glTranslatef(xPosition - 0.15f, 0.15f, zPosition + 0.1f);
	glScalef(0.15f, 0.05f, 0.3f);
	glColor3f(0.1f, 0.1f, 0.1f); // Black shoes
	glutSolidCube(1.0f);
	glPopMatrix();

	// Right Foot
	glPushMatrix();
	glTranslatef(xPosition + 0.15f, 0.15f, zPosition + 0.1f);
	glScalef(0.15f, 0.05f, 0.3f);
	glColor3f(0.1f, 0.1f, 0.1f); // Black shoes
	glutSolidCube(1.0f);
	glPopMatrix();
}
