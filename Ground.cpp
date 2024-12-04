#include "Ground.h"

Ground::Ground() 
	: x(0), z(0), width(28), length(15) {}

void Ground::draw() {
	drawCourtFloor();
	drawCourtLines();
}

void Ground::drawCourtFloor() {
	glPushMatrix();
	glScaled(28, 0, 15);
	//color(209, 168, 96);
	color(1, 1, 1);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glScaled(28*2, 0, 15*2);
	glColor3f(1.0f, 1.0f, 1.0f);
	glutSolidCube(1);
	glPopMatrix();
}

void Ground::drawCourtLines() {
	glColor3f(1.0f, 1.0f, 1.0f);

	// Draw outer boundary
	glBegin(GL_LINE_LOOP);
	glVertex3f(-14.0f, 0.01f, -7.5f);
	glVertex3f(14.0f, 0.01f, -7.5f);
	glVertex3f(14.0f, 0.01f, 7.5f);
	glVertex3f(-14.0f, 0.01f, 7.5f);
	glEnd();

	// Center circle
	float centerRadius = 1.8f;
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 360; i += 10) {
		float theta = i * 3.14159f / 180;
		float x = centerRadius * cos(theta);
		float z = centerRadius * sin(theta);
		glVertex3f(x, 0.01f, z);
	}
	glEnd();

	// Free-throw lanes (left side)
	glBegin(GL_LINE_LOOP);
	glVertex3f(-14.0f, 0.01f, -3.5f);
	glVertex3f(-10.0f, 0.01f, -3.5f);
	glVertex3f(-10.0f, 0.01f, 3.5f);
	glVertex3f(-14.0f, 0.01f, 3.5f);
	glEnd();

	// Free-throw lanes (right side)
	glBegin(GL_LINE_LOOP);
	glVertex3f(14.0f, 0.01f, -3.5f);
	glVertex3f(10.0f, 0.01f, -3.5f);
	glVertex3f(10.0f, 0.01f, 3.5f);
	glVertex3f(14.0f, 0.01f, 3.5f);
	glEnd();
}