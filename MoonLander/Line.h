#pragma once
#include "Vector3f.h"
#include "Shape.h"
#include "Tools.h"
#include <iostream>
#include <windows.h>
#include <gl\gl.h> 
#include <gl\glu.h> 

class Line : public Shape {

public:
	Line();
	Line::Line(Vector3f* vertexA, Vector3f* vertexB, Vector3f* color, float lineWidth);
	~Line();
	virtual void draw();
private:
	Vector3f* vertexA;
	Vector3f* vertexB;
	Vector3f* color;
	float lineWidth;
};