#pragma once
#include <vector>
#include <Windows.h>
#include <gl\gl.h> 
#include <gl\glu.h> 

class Shape
{
protected:
	std::vector < std::vector <GLfloat> > vertexes;
	Shape();
	~Shape();
public:
	virtual void draw() = 0;
};

