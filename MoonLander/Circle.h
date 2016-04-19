#pragma once
#include "Vector3f.h"
#include "Shape.h"
#include "Tools.h"
#include <iostream>
#include <windows.h>
#include <gl\gl.h> 
#include <gl\glu.h> 

class Circle : public Shape {
public:

	Circle(Vector3f* position, Vector3f* color, float radius=10, float resolution=20, int GL_STRONA = GL_CCW);
	~Circle();
	virtual void draw();

private:
	Vector3f* position;
	Vector3f* color;
	float radius;
	float resolution;
	int GL_STRONA;



};
