#pragma once

#include <string>
#include <glut.h>

void color(short r, short g, short b);

void color(long hex);

void drawText(const std::string& text, int x, int y, int color);