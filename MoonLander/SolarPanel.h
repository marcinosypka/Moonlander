#pragma once
#include "Vector3f.h"
#include "Shape.h"
#include "Circle.h"
#include "Tools.h"
#include <iostream>
#include <windows.h>
#include <gl\gl.h> 
#include <gl\glu.h> 
#include "Texture.h"

class SolarPanel : public Shape
{
public:
	SolarPanel();
	~SolarPanel();
	virtual void draw();

private:
	Vector3f* position;
	Vector3f* color;
	float width;
	float height;
	float depth;
	Texture *texture;

};

