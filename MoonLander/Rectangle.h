#pragma once
#include "Vector3f.h"
#include "Shape.h"
#include "Tools.h"
#include <iostream>
#include <windows.h>
#include <gl\gl.h> 
#include <gl\glu.h> 

class Rectangle : public Shape {

public:
	Rectangle();
	Rectangle(Vector3f* position, Vector3f* color, float height,float width);
	~Rectangle();
	virtual void draw();
private:
	Vector3f* position;
	Vector3f* color;
	float height;
	float width;
};