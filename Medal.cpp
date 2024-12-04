#include "Medal.h"

Medal::Medal(Vector3f& position, Vector3f& size)
	: BoundingBox(position, size), angle(0) {};

void Medal::draw() {
	glTranslated(position.x, position.y, position.z);
	glRotated(angle, 0, 1, 0);
	glTranslated(-position.x, -position.y, -position.z);
	drawOlympicMedal(position.x, position.y, position.z);
}

void Medal::animate() {
	angle += 2;
}

void Medal::drawMedal(float xPosition, float yPosition, float zPosition) {
	// Medal Base
	glPushMatrix();
	glTranslatef(xPosition, yPosition, zPosition); // Position the medal base
	glColor3f(0.9f, 0.7f, 0.0f);                   // Gold color
	glutSolidTorus(0.02f, 0.2f, 30, 30);           // Main disk (torus with small inner radius)
	glPopMatrix();

	// Medal Ring (Edge)
	glPushMatrix();
	glTranslatef(xPosition, yPosition + 0.01f, zPosition); // Slightly raised to create an edge
	glColor3f(0.8f, 0.6f, 0.0f);                           // Slightly darker gold
	glutSolidTorus(0.04f, 0.21f, 30, 30);                  // Outer ring for edge effect
	glPopMatrix();

	// Ribbon Loop
	glPushMatrix();
	glTranslatef(xPosition, yPosition + 0.2f, zPosition);  // Position at the top of the medal
	glScalef(0.1f, 0.05f, 0.05f);                         // Scale to resemble a small rectangular loop
	glColor3f(0.8f, 0.4f, 0.0f);                          // Darker color for contrast
	glutSolidCube(1.0f);
	glPopMatrix();
}

void Medal::drawOlympicMedal(float xPosition, float yPosition, float zPosition) {
	// Medal Base (Yellow Disk)
	glPushMatrix();
	glTranslatef(xPosition, yPosition, zPosition);
	glColor3f(1.0f, 0.84f, 0.0f); // Yellow color for gold medal
	GLUquadric* quad = gluNewQuadric();
	gluCylinder(quad, 1.1f, 0.1f, 0.1f, 20, 20); // Disk for the medal base
	gluDeleteQuadric(quad);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(xPosition, yPosition, zPosition);
	glColor3f(1.0f, 0.84f, 0.0f); // Yellow color for gold medal
	glutSolidTorus(0.0, 2.0, 20, 1); // Disk for the medal base
	glPopMatrix();

	// Olympic Rings Setup
	float ringRadius = 0.25f; // Radius for each ring
	float ringThickness = 0.05f; // Thickness for each ring (torus inner radius)

	// Positions for the Olympic rings (offsets based on layout)
	float positions[5][3] = {
		{-0.6f, 0.2f, 0.1f}, // Blue (leftmost)
		{-0.3f, 0.2f, 0.1f}, // Black
		{0.0f, 0.2f, 0.1f},  // Red (rightmost)
		{-0.45f, -0.1f, 0.1f}, // Yellow (below blue and black)
		{-0.15f, -0.1f, 0.1f}  // Green (below black and red)
	};

	// Colors for the Olympic rings (blue, black, red, yellow, green)
	float colors[5][3] = {
		{0.0f, 0.0f, 1.0f}, // Blue
		{0.0f, 0.0f, 0.0f}, // Black
		{1.0f, 0.0f, 0.0f}, // Red
		{1.0f, 1.0f, 0.0f}, // Yellow
		{0.0f, 1.0f, 0.0f}  // Green
	};

	// Draw each ring as a torus
	for (int i = 0; i < 5; i++) {
		glPushMatrix();
		glTranslatef(xPosition + positions[i][0], yPosition + positions[i][1], zPosition + positions[i][2]);
		glColor3fv(colors[i]);
		//glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotate to lay flat on the medal
		glutSolidTorus(ringThickness, ringRadius, 20, 20);
		glPopMatrix();
	}
}