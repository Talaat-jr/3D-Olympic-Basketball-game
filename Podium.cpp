#include "Podium.h"

Podium::Podium() {}

void Podium::draw() {
	glPushMatrix();
	glTranslated(16, 0, 0);
	glRotated(90, 0, 1, 0);
	glTranslated(-16, 0, 0);
	drawPodium(18.0f, 0.0f, 5.0f);
	glPopMatrix();

}

void Podium::animate() {
	// Update scaling factors for each block
	for (int i = 0; i < 3; i++) {
		scaleFactors[i] += scaleSpeed[i] * scaleDirection[i];

		// Reverse direction if scaling factor exceeds bounds
		if (scaleFactors[i] > 1.2f || scaleFactors[i] < 0.8f) {
			scaleDirection[i] = -scaleDirection[i];
		}
	}
}

void Podium::drawPodium(float xPosition, float yPosition, float zPosition) {
	// Podium Base Heights
	float heights[3] = { 0.2f, 0.3f, 0.1f };
	float positions[3] = { -2.0f, 0.0f, 2.0f };
	float colors[3][3] = { { 1.0f, 0.0f, 0.0f }, { 0.0f, 1.0f, 0.0f }, { 0.0f, 0.0f, 1.0f } };

	// Draw Podium Blocks
	for (int i = 0; i < 3; i++) {
		glPushMatrix();
		glTranslatef(xPosition + positions[i], yPosition + (4* heights[i] / 2), zPosition);
		glScalef(2 * scaleFactors[i], 4 * heights[i] * scaleFactors[i], 3 * 0.6f * scaleFactors[i]);
		glColor3fv(colors[i]);
		glutSolidCube(1.0f);
		glPopMatrix();
	}
}