#include "Bench.h"

Bench::Bench() {}

//void Bench::draw() {
//	for (float z = -5.0f; z <= 5.0f; z += 2.5f) {
//		drawBench(z, -10.0f);   // Left side benches
//		drawBench(-z, 10.0f);    // Right side benches
//	}
//}
//
//void Bench::animate() {
//	// No animation needed for the bench
//}

void Bench::draw() {
	for (float z = -5.0f; z <= 5.0f; z += 2.5f) {
		drawBench(z, -10.0f + benchOffset); // Left side benches oscillate along Z-axis
		drawBench(-z, 10.0f - benchOffset); // Right side benches oscillate along Z-axis
	}
}

void Bench::animate() {
	// Update the offset for oscillation
	benchOffset += benchSpeed * benchDirection;

	// Reverse direction if it goes out of bounds
	if (benchOffset > 2.0f || benchOffset < -2.0f) {
		benchDirection = -benchDirection;
	}
}

void Bench::drawBench(float xPosition, float zPosition) {
	// Bench seat
	glPushMatrix();
	glTranslatef(xPosition, 0.5f, zPosition); // Position the seat
	glScalef(1.5f, 0.2f, 0.5f);               // Scale to make a rectangular seat
	glColor3f(0.5f, 0.35f, 0.05f);            // Brown color for the bench seat
	glutSolidCube(1.0f);
	glPopMatrix();

	// Bench backrest
	glPushMatrix();
	glTranslatef(xPosition, 1.0f, zPosition - 0.3f); // Position the backrest slightly behind the seat
	glScalef(1.5f, 0.4f, 0.1f);                      // Scale for the backrest
	glColor3f(0.5f, 0.35f, 0.05f);
	glutSolidCube(1.0f);
	glPopMatrix();

	// Bench legs (4 small cubes)
	float legHeight = 0.5f;
	float legOffsetX = 0.6f;
	float legOffsetZ = 0.2f;

	for (float offsetX = -legOffsetX; offsetX <= legOffsetX; offsetX += 2 * legOffsetX) {
		for (float offsetZ = -legOffsetZ; offsetZ <= legOffsetZ; offsetZ += 2 * legOffsetZ) {
			glPushMatrix();
			glTranslatef(xPosition + offsetX, legHeight / 2, zPosition + offsetZ); // Position each leg
			glScalef(0.1f, legHeight, 0.1f);  // Scale to make small leg cubes
			glColor3f(0.3f, 0.2f, 0.1f);      // Darker brown for the legs
			glutSolidCube(1.0f);
			glPopMatrix();
		}
	}
}