#include "BasketBall.h"

BasketBall::BasketBall(float xPosition, float zPosition)
	: BoundingBox(Vector3f(xPosition, 1, zPosition), Vector3f(0.5, 0.5, 0.5)), xPosition(xPosition), zPosition(zPosition), angle(0) {};

void BasketBall::draw() {
    glPushMatrix();
    glTranslated(xPosition, 1.0, zPosition);
    glRotated(angle, 0.0, 1.0, 0.0);
    drawBasketball(0.0f, 0.0f, 0.0f);
    glPopMatrix();
}

void BasketBall::animate() {
    angle += 2;
    if (angle >= 360) {
        angle -= 360;
    }
}

void BasketBall::drawBasketball(float xPosition, float yPosition, float zPosition) {
    // Basketball Body (Sphere)
    glPushMatrix();
    glColor3f(1.0f, 0.5f, 0.0f);
    glutSolidSphere(0.5f, 30, 30);
    glPopMatrix();

    // Horizontal Stripe (Torus 1)
    glPushMatrix();
    glRotatef(90, 1.0f, 0.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glutSolidTorus(0.02f, 0.5f, 20, 20);
    glPopMatrix();

    // Vertical Stripe (Torus 2)
    glPushMatrix();
    glRotatef(90, 0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glutSolidTorus(0.02f, 0.5f, 20, 20);
    glPopMatrix();

    // Additional Vertical Stripe (Torus 3)
    glPushMatrix();
    glRotatef(90, 0.0f, 0.0f, 1.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glutSolidTorus(0.02f, 0.5f, 20, 20);
    glPopMatrix();
}