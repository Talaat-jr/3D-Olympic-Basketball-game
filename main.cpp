#include "utils.h"
#include "Camera.h"
#include "Basket.h"
#include "Fence.h"
#include "Player.h"
#include "Ground.h"
#include "BasketBall.h"
#include "IceBox.h"
#include "Bench.h"
#include "Podium.h"

#include <iostream>
#include <string>
#include <vector>
#include <SFML/Audio.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <glut.h>

#define GLUT_KEY_ESCAPE 27
#define DEG2RAD(a) (a * 0.0174532925)

//consts
int timer = 50e3;
bool animate = false;

//sounds
sf::Music backgroundSound;
sf::Music collisionSound;
sf::Music collectableSound;
sf::Music animationSound;
sf::Music winSound;
sf::Music loseSound;

Camera camera = Camera(1, 1, 1, 0, 0, 0, 0, 1, 0);
Player player = Player(0,0, true);
Vector3f v = Vector3f(2.0, 3.0, 0.0);
Player opp = Player(1,0, true);
std::vector<Player> opponents;
std::vector<BasketBall> balls;
Basket basket;
Fence fence;
Ground ground;
IceBox icebox;
Bench benches;
Podium podium;

bool isGameWin() {
	return player.getScore() > 3;
}

bool isGameEnd() {
	return timer <= 0 || isGameWin();
}

void drawGameOverScreen() {
	glClearColor(0.1f, 0.1f, 0.3f, 1.0f);

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, 640, 0, 480);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glDisable(GL_LIGHTING);
	glDisable(GL_DEPTH_TEST);

	glColor3f(1.0f, 1.0f, 0.0f);
	glRasterPos2i(250, 240);
	bool gameWon = isGameWin();

	if (gameWon) {
		if (winSound.getStatus() != sf::Sound::Playing)
			winSound.play();
	}
	else {
		if (loseSound.getStatus() != sf::Sound::Playing)
			loseSound.play();
	}
	
	const char* message = gameWon ? "GAME WIN!" : "GAME OVER!";
	for (const char* c = message; *c != '\0'; c++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
	}

	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}

void loadSounds() {
	backgroundSound.openFromFile("sounds/background.wav");
	collisionSound.openFromFile("sounds/collision.wav");
	collectableSound.openFromFile("sounds/collectable.wav");
	animationSound.openFromFile("sounds/animation.wav");
	winSound.openFromFile("sounds/win.wav");
	loseSound.openFromFile("sounds/lose.wav");
 
	backgroundSound.setLoop(true);
	animationSound.setLoop(true);
	winSound.setLoop(true);
	loseSound.setLoop(true);

	backgroundSound.play();
}

void initBalls() {
	int xPositions[] = { -12, -5, 3, 10, -9 };
	int zPositions[] = { 5, -6, 7, -4, 1 };
	for (int i = 0; i < 5; i++)
		balls.push_back(BasketBall(xPositions[i], zPositions[i]));
}

void initOppenets() {
	int xPositions[] = { -6, 0, 7, -4, 2 };
	int zPositions[] = { 3, -5, 0, -2, 4 };
	for (int i = 0; i < 5; i++)
		opponents.push_back(Player(xPositions[i], zPositions[i], false));	
}

void initGame() {
	loadSounds();
	initBalls();
	initOppenets();
}

void setupLights() {
	GLfloat ambient[] = { 0.7f, 0.7f, 0.7, 1.0f };
	GLfloat diffuse[] = { 0.6f, 0.6f, 0.6, 1.0f };
	GLfloat specular[] = { 1.0f, 1.0f, 1.0, 1.0f };
	GLfloat shininess[] = { 50 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);

	GLfloat lightIntensity[] = { 0.7f, 0.7f, 1, 1.0f };
	GLfloat lightPosition[] = { -7.0f, 6.0f, 3.0f, 0.0f };
	glLightfv(GL_LIGHT0, GL_POSITION, lightIntensity);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightIntensity);
}

void setupCamera() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 640 / 480, 0.001, 100);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	camera.look();
}

void checkCollision() {
	for (auto it = balls.begin(); it != balls.end();) {
		if (player.isColliding(*it)) {
			collectableSound.play();
			player.incrementScore();
			it = balls.erase(it);
		}
		else {
			++it;
		}
	}
}

void drawCourt() {
	ground.draw();
	fence.draw();
	fence.animate();
	basket.draw();
	icebox.draw();
	benches.draw();
	podium.draw();

	if (animate) {
		basket.animate();
		icebox.animate();
		benches.animate();
		podium.animate();

	}
}

void drawBalls() {
	for (int i = 0; i < balls.size(); i++) {
		balls[i].draw();
		balls[i].animate();
	}
}

void drawOppenents() {
	for (int i = 0; i < opponents.size(); i++) {
		opponents[i].draw();
		if (animate) opponents[i].animate();
	}
}

void Display() {

	setupCamera();
	setupLights();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if (isGameEnd()) {
		backgroundSound.stop();
		drawGameOverScreen();
	}
	else {
		checkCollision();

		glPushMatrix();
		drawCourt();
		drawBalls();
		player.draw();
		drawOppenents();
		glPopMatrix();
	}

	glFlush();
}

void Timer(int value) {
	double elapsedTime = glutGet(GLUT_ELAPSED_TIME);
	timer = timer - (elapsedTime / 1000);

	glutPostRedisplay();
	glutTimerFunc(1, Timer, 0);
}

void Keyboard(unsigned char key, int x, int y) {
	float d = 1.01;

	switch (key) {
	case 'w':
		camera.moveY(d);
		break;
	case 's':
		camera.moveY(-d);
		break;
	case 'a':
		camera.moveX(d);
		break;
	case 'd':
		camera.moveX(-d);
		break;
	case 'q':
		camera.moveZ(d);
		break;
	case 'e':
		camera.moveZ(-d);
		break;

	case '1':
		camera.setEye(10, d, 0);
		camera.setCenter(0, 0, 0);
		camera.setUp(0, 1, 0);
		break;
	case '2':
		camera.setEye(0, 15, 0);
		camera.setCenter(0, 0, 0);
		camera.setUp(0, 0, 1);
		break;
	case '3':
		camera.setEye(0, 0, 10);
		camera.setCenter(0, 0, 0);
		camera.setUp(0, 1, 0);
		break;
	case '4':
		camera.setEye(1, 1, 1);
		camera.setCenter(0, 0, 0);
		camera.setUp(0, 1, 0);
		break;

	case 'i':
		player.move(d,0);
		player.setAngle(90);
		break;
	case 'k':
		player.move(-d,0);
		player.setAngle(270);
		break;
	case 'j':
		player.move(0,d);
		player.setAngle(0);
		break;
	case 'l':
		player.move(0,-d);
		player.setAngle(180);
		break;
	case 'o':
		player.rotateY();
		break;
	case 'u' :
		if (animationSound.getStatus() != sf::Sound::Playing)
			animationSound.play();
		animate = true;
		break;

	case GLUT_KEY_ESCAPE:
		exit(EXIT_SUCCESS);
	}

	glutPostRedisplay();
}

void KeyboardUp(unsigned char key, int x, int y) {
	switch (key) {
	case 'u':
		animationSound.stop();
		animate = false;
		break;
	}
}

void Special(int key, int x, int y) {
	float a = 1.0;

	switch (key) {
	case GLUT_KEY_UP:
		camera.rotateX(a);
		break;
	case GLUT_KEY_DOWN:
		camera.rotateX(-a);
		break;
	case GLUT_KEY_LEFT:
		camera.rotateY(a);
		break;
	case GLUT_KEY_RIGHT:
		camera.rotateY(-a);
		break;
	}

	glutPostRedisplay();
}

void main(int argc, char** argv) {
	glutInit(&argc, argv);

	glutInitWindowSize(640, 480);
	glutInitWindowPosition(50, 50);

	glutCreateWindow("3D-Basketball Game");
	glutDisplayFunc(Display);
	glutKeyboardFunc(Keyboard);
	glutKeyboardUpFunc(KeyboardUp);
	glutSpecialFunc(Special);
	initGame();
	glutTimerFunc(10, Timer, 0);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);

	glShadeModel(GL_SMOOTH);

	glutMainLoop();
}
