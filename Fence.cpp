#include "Fence.h"

Fence::Fence() :
	animationFactor(0.0f) {};

void Fence::draw() {
	drawFence();
	drawFence2();
}

void Fence::animate() {
	animationFactor += 0.05f; // Adjust speed of color change
	if (animationFactor > 360.0f) {
		animationFactor -= 360.0f; // Keep within a reasonable range
	}
}

void Fence::drawFence() {
	float red = 0.5f + 0.5f * sin(animationFactor);
	float green = 0.5f + 0.5f * sin(animationFactor + 2.0f);
	float blue = 0.5f + 0.5f * sin(animationFactor + 4.0f);

	glColor3f(red, green, blue);

	float fenceHeight = 5.0f;

	// Vertical lines for the fence
	glBegin(GL_LINES);
	for (float x = -14.0f; x <= 14.0f; x += 1.5f) {
		// Front side
		glVertex3f(x, 0.0f, -7.5f);
		glVertex3f(x, fenceHeight, -7.5f);

		// Back side
		glVertex3f(x, 0.0f, 7.5f);
		glVertex3f(x, fenceHeight, 7.5f);
	}
	for (float z = -7.5f; z <= 7.5f; z += 1.5f) {
		// Left side
		glVertex3f(-14.0f, 0.0f, z);
		glVertex3f(-14.0f, fenceHeight, z);

		// Right side
		glVertex3f(14.0f, 0.0f, z);
		glVertex3f(14.0f, fenceHeight, z);
	}
	glEnd();

	// Horizontal lines for the fence
	glBegin(GL_LINES);
	for (float y = 1.0f; y <= fenceHeight; y += 1.0f) {
		// Front side
		glVertex3f(-14.0f, y, -7.5f);
		glVertex3f(14.0f, y, -7.5f);

		// Back side
		glVertex3f(-14.0f, y, 7.5f);
		glVertex3f(14.0f, y, 7.5f);

		// Left side
		glVertex3f(-14.0f, y, -7.5f);
		glVertex3f(-14.0f, y, 7.5f);

		// Right side
		glVertex3f(14.0f, y, -7.5f);
		glVertex3f(14.0f, y, 7.5f);
	}
	glEnd();
}

void Fence::drawFence2() {
	float red = 0.5f + 0.5f * sin(animationFactor);
	float green = 0.5f + 0.5f * sin(animationFactor + 2.0f);
	float blue = 0.5f + 0.5f * sin(animationFactor + 4.0f);

	glColor3f(red, green, blue);

	float fenceHeight = 5.0f;
	float postThickness = 0.1f;  // Thickness of each fence post

	// Draw vertical fence posts
	for (float x = -14.0f; x <= 14.0f; x += 1.5f) {
		for (float y = 0.5f; y <= fenceHeight; y += 1.0f) {
			glPushMatrix();
			glTranslatef(x, y, -7.5f);         // Front side
			glScalef(postThickness, 1.0f, postThickness);
			glutSolidCube(1.0f);               // Cube as thin vertical post
			glPopMatrix();

			glPushMatrix();
			glTranslatef(x, y, 7.5f);          // Back side
			glScalef(postThickness, 1.0f, postThickness);
			glutSolidCube(1.0f);
			glPopMatrix();
		}
	}

	for (float z = -7.5f; z <= 7.5f; z += 1.5f) {
		for (float y = 0.5f; y <= fenceHeight; y += 1.0f) {
			glPushMatrix();
			glTranslatef(-14.0f, y, z);       // Left side
			glScalef(postThickness, 1.0f, postThickness);
			glutSolidCube(1.0f);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(14.0f, y, z);        // Right side
			glScalef(postThickness, 1.0f, postThickness);
			glutSolidCube(1.0f);
			glPopMatrix();
		}
	}

	// Draw horizontal fence rails
	for (float y = 0.5f; y <= fenceHeight; y += 1.0f) {
		glPushMatrix();
		glTranslatef(0.0f, y, -7.5f);         // Front side
		glScalef(28.0f, postThickness, postThickness);
		glutSolidCube(1.0f);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.0f, y, 7.5f);          // Back side
		glScalef(28.0f, postThickness, postThickness);
		glutSolidCube(1.0f);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-14.0f, y, 0.0f);        // Left side
		glScalef(postThickness, postThickness, 15.0f);
		glutSolidCube(1.0f);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(14.0f, y, 0.0f);         // Right side
		glScalef(postThickness, postThickness, 15.0f);
		glutSolidCube(1.0f);
		glPopMatrix();
	}
}