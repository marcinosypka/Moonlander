#pragma once
#include "Vector3f.h"
#include "Shape.h"
#include "Circle.h"
#include "Tools.h"
#include <iostream>
#include <windows.h>
#include <gl\gl.h> 
#include <gl\glu.h> 


class Roller : public Shape {

public:

	Roller(Vector3f* position, Vector3f* color, float radius, float resolution,float height);
	Roller();
	~Roller();
	virtual void draw();

private:
	Vector3f* position;
	Vector3f* color;
	Vector3f *topCirclepossition;
	float radius;
	float resolution;
	float height;
	Circle *top;
	Circle *bottom;
	bool topIsShown = true;
	bool bottomIsShown = true;

};