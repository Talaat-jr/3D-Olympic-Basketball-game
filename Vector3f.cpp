#include "Vector3f.h"

Vector3f::Vector3f(float _x, float _y, float _z)
	: x(_x), y(_y), z(_z) {};

Vector3f Vector3f::operator+(Vector3f& v) {
	return Vector3f(x + v.x, y + v.y, z + v.z);
}

Vector3f Vector3f::operator-(Vector3f& v) {
	return Vector3f(x - v.x, y - v.y, z - v.z);
}

Vector3f Vector3f::operator*(float n) {
	return Vector3f(x * n, y * n, z * n);
}

Vector3f Vector3f::operator/(float n) {
	return Vector3f(x / n, y / n, z / n);
}

Vector3f Vector3f::unit() {
	return *this / sqrt(x * x + y * y + z * z);
}

Vector3f Vector3f::cross(Vector3f v) {
	return Vector3f(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
}

float Vector3f::length() {
	return std::sqrt(x * x + y * y + z * z);
}