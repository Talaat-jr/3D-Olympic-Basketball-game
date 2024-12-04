#include "IceBox.h"

IceBox::IceBox() {}

void IceBox::draw() {
    glPushMatrix();
    glTranslatef(0.0f, yOffset, 0.0f); // Apply the Y-axis translation to the entire icebox
    drawIcebox(10, 0.18, 10);
    glPopMatrix();
}

void IceBox::animate() {
    // Update the Y-offset for animation
    yOffset += ySpeed * direction;

    // Reverse direction when reaching bounds
    if (yOffset > 1.0f || yOffset < 0.18f) {
        direction = -direction;
    }
}

void IceBox::drawIcebox(float xPosition, float yPosition, float zPosition) {
    // Icebox Bottom (solid)
    glPushMatrix();
    glTranslatef(xPosition, yPosition - 0.25f, zPosition);
    glScalef(1.5f, 0.05f, 1.0f);
    glColor3f(0.8f, 0.9f, 1.0f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Icebox Side Walls (leave top open)
    glPushMatrix();
    glTranslatef(xPosition - 0.75f, yPosition, zPosition); // Left wall
    glScalef(0.05f, 0.5f, 1.0f);
    glColor3f(0.8f, 0.9f, 1.0f);
    glutSolidCube(1.0f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(xPosition + 0.75f, yPosition, zPosition); // Right wall
    glScalef(0.05f, 0.5f, 1.0f);
    glColor3f(0.8f, 0.9f, 1.0f);
    glutSolidCube(1.0f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(xPosition, yPosition, zPosition - 0.5f); // Front wall
    glScalef(1.5f, 0.5f, 0.05f);
    glColor3f(0.8f, 0.9f, 1.0f);
    glutSolidCube(1.0f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(xPosition, yPosition, zPosition + 0.5f); // Back wall
    glScalef(1.5f, 0.5f, 0.05f);
    glColor3f(0.8f, 0.9f, 1.0f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Icebox Lid (Wireframe to show bottles inside)
    glPushMatrix();
    glTranslatef(xPosition, yPosition + 0.75f, zPosition + 0.5f);
    glRotatef(-45.0f, 1.0f, 0.0f, 0.0f); // Rotate to simulate an open lid
    glScalef(1.5f, 0.05f, 1.0f);
    glColor3f(0.8f, 0.9f, 1.0f);
    glutWireCube(1.0f); // Wireframe for lid
    glPopMatrix();

    // Water Bottles inside the Icebox
    int numBottles = 4;
    for (int i = 0; i < numBottles; i++) {
        glPushMatrix();
        glTranslatef(xPosition - 0.5f + (i * 0.3f), yPosition - 0.1f, zPosition); // Position each bottle
        glColor3f(0.2f, 0.3f, 1.0f); // Blue color for water bottle
        GLUquadric* quad = gluNewQuadric();
        gluCylinder(quad, 0.1f, 0.1f, 0.4f, 20, 20); // Cylinder for bottle body
        gluDeleteQuadric(quad);

        // Bottle Cap
        glTranslatef(0.0f, 0.0f, 0.4f); // Move cap to top of the bottle
        glColor3f(0.6f, 0.6f, 0.6f); // Gray for cap
        glutSolidSphere(0.1f, 10, 10); // Cap as small sphere
        glPopMatrix();
    }
}