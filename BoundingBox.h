#pragma once

#include "Vector3f.h"
#include <cmath>

class BoundingBox {
public:
	Vector3f position;
	Vector3f size;

	BoundingBox( Vector3f& position,  Vector3f& size);

	Vector3f getPosition() ;
	Vector3f getStart() ;
	Vector3f getSize() ;
	Vector3f getEnd() ;

	bool isColliding( BoundingBox& other) ;
};