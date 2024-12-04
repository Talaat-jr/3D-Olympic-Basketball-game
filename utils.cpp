#include "utils.h"

void color(long hex) {
    short r = (hex >> 16) & 0xFF;
    short g = (hex >> 8) & 0xFF;
    short b = hex & 0xFF;
    color(r, g, b);
}

void color(short r, short g, short b) {
    glColor3d(r / 255.0, g / 255.0, b / 255.0);
}

void drawText(const std::string& text, int x, int y, int c) {
    color(c);
    glRasterPos2d(0, 0);
    for (char i : text) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, i);
    }
}