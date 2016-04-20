#pragma once
#include "Vector3f.h"
#include "Shape.h"
#include "Tools.h"
#include <iostream>
#include <windows.h>
#include <gl\gl.h> 
#include <gl\glu.h> 

class Rectangle1 : public Shape {

public:
	Rectangle1();
	Rectangle1(Vector3f* position, Vector3f* color, float height,float width, float depth);
	~Rectangle1();
	virtual void draw();
private:
	Vector3f* position;
	Vector3f* color;
	float height;
	float width;
	float depth;
};