#include "Vector3f.h"

Vector3f::Vector3f()
{
	
}

Vector3f::~Vector3f()
{
}

Vector3f::Vector3f(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

const GLfloat* Vector3f::toArray()
{
	GLfloat array[3] = { x, y, z };
	return array;
}