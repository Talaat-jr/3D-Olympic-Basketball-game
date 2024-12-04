#include "Basket.h"

void Basket::draw() {
	drawBackboard(13.0f);       // Right side backboard
	drawBackboard(-13.0f);      // Left side backboard
	drawHoop(12.75f, 0.0f);      // Right side hoop
	drawHoop(-12.75f, 0.0f);     // Left side hoop
	drawPole(13.5f, 0.0f);      // Right side pole
	drawPole(-13.5f, 0.0f);     // Left side pole
}

void Basket::animate() {
	basketColorR += colorChangeSpeed;
	basketColorG += colorChangeSpeed * 1.5f; // Slightly faster change for variety
	basketColorB += colorChangeSpeed * 0.5f; // Slower change for variety

	// Loop colors back to 0 when they exceed 1
	if (basketColorR > 1.0f || basketColorR < 0.0f) colorChangeSpeed = -colorChangeSpeed;
	if (basketColorG > 1.0f) basketColorG -= 1.0f;
	if (basketColorB > 1.0f) basketColorB -= 1.0f;
}

void Basket::drawBackboard(float xPosition) {
	glPushMatrix();
	glTranslatef(xPosition, 3.0f, 0.0f); // Position the backboard
	glScalef(0.1f, 1.0f, 1.8f);          // Scale to make a thin rectangle
	glColor3f(basketColorR, basketColorG, basketColorB);
	glutSolidCube(1.0f);                 // Use a cube for the backboard
	glPopMatrix();
}

void Basket::drawHoop(float xPosition, float zPosition) {
	glPushMatrix();
	glTranslatef(xPosition, 2.8f, zPosition); // Position the hoop slightly below the backboard
	glRotatef(-90, 1, 0, 0);                 // Rotate to make the cylinder vertical
	glColor3f(basketColorR, basketColorG, basketColorB);
	glutSolidTorus(0.05, 0.25, 20, 20);      // Inner radius, outer radius, slices, stacks
	glPopMatrix();
}

void Basket::drawPole(float xPosition, float zPosition) {
	glPushMatrix();
	glTranslatef(xPosition, 0.0f, zPosition); // Position the pole
	glRotatef(-90, 1, 0, 0);                 // Rotate to make the cylinder vertical
	glColor3f(basketColorR, basketColorG, basketColorB);

	GLUquadric* quad = gluNewQuadric();
	gluCylinder(quad, 0.1f, 0.1f, 3.0f, 20, 20); // Base radius, top radius, height, slices, stacks

	gluDeleteQuadric(quad);
	glPopMatrix();
}