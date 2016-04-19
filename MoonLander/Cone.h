#pragma once
#include "Vector3f.h"
#include "Shape.h"

class Cone : public Shape
{
public:
	Cone(Vector3f* position, Vector3f* color, float height, float upperRadius, float lowerRadius, float resolution);
	~Cone();

	void draw();

private:
	Vector3f* position;
	Vector3f* color;
	float height;
	float upperRadius;
	float lowerRadius;
	float resolution;

	
};

