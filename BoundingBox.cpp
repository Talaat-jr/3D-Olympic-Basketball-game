#include "BoundingBox.h"

BoundingBox::BoundingBox(Vector3f& position, Vector3f& size)
    : position(position), size(size) {}

Vector3f BoundingBox::getPosition() {
    return position;
}

Vector3f BoundingBox::getStart() {
    return position - size / 2;
}

Vector3f BoundingBox::getSize() {
    return size;
}

Vector3f BoundingBox::getEnd() {
    return position + size / 2;
}

bool BoundingBox::isColliding( BoundingBox& other) {
    if (getSize().length() == 0 || other.getSize().length() == 0) {
        return false;
    }

    Vector3f thisStart = getStart();
    Vector3f otherStart = other.getStart();
    Vector3f thisEnd = getEnd();
    Vector3f otherEnd = other.getEnd();

    return (thisStart.x <= otherEnd.x && thisEnd.x >= otherStart.x) &&
        (thisStart.y <= otherEnd.y && thisEnd.y >= otherStart.y) &&
        (thisStart.z <= otherEnd.z && thisEnd.z >= otherStart.z);
}
