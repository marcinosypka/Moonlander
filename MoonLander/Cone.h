#pragma once
#include "Vector3f.h"
#include "Shape.h"
#include "Tools.h"
#include <iostream>
#include <windows.h>
#include <gl\gl.h> 
#include <gl\glu.h> 

class Cone : public Shape
{
public:
	Cone();
	Cone(Vector3f* position, Vector3f* color, float height, float upperRadius, float lowerRadius, float resolution);
	~Cone();

	virtual void draw();

	void setPart(float part);

private:
	Vector3f* position;
	Vector3f* color;
	float height;
	float upperRadius;
	float lowerRadius;
	float resolution;
	float part;
	
};

