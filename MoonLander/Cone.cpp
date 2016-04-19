#include "Cone.h"
#include "Tools.h"
#include <iostream>
#include <windows.h>
#include <gl\gl.h> 
#include <gl\glu.h> 
//#include "glut.h"

Cone::Cone(Vector3f* position, Vector3f* color, float height, float upperRadius, float lowerRadius, float resolution)
{
	this->position = position;
	this->color = color;
	this->height = height;
	this->upperRadius = upperRadius;
	this->lowerRadius = lowerRadius;
	this->resolution = resolution;
}


Cone::~Cone()
{
}

void Cone::draw()
{
	float step = Tools::PI * 2 / resolution;

	glColor3fv(color->toArray());

	glBegin(GL_TRIANGLE_STRIP);
	for (float i = 0.0f; i <= Tools::PI * 2 + 0.01; i += step)
	{
		glVertex3f(position->x + lowerRadius * cos(i), position->y, position->z + lowerRadius * sin(i));
		glVertex3f(position->x + upperRadius * cos(i), position->y + height, position->z + upperRadius * sin(i));
	}
	glEnd();
	
}
