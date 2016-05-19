#pragma once
#include <windows.h> // Window defines
#include <gl\gl.h> 
#include <gl\glu.h>
//#include "glut.h"

class Vector3f
{
public:
	float x, y, z;

	Vector3f();
	~Vector3f();

	Vector3f(float x, float y, float z);

	const GLfloat* toArray();
	void set(float x, float y, float z);
	Vector3f operator + (Vector3f& vector)
	{
		return Vector3f(x + vector.x, y + vector.y, z + vector.z);
	}

	Vector3f operator = (float A)
	{
		return Vector3f(x = A, y = A, z = A);
	}
	Vector3f operator + (float A)
	{
		return Vector3f(x + A, y + A, z + A);
	}

	Vector3f operator - (Vector3f& vector)
	{
		return Vector3f(x - vector.x, y - vector.y, z - vector.z);
	}

	Vector3f operator - (float A)
	{
		return Vector3f(x - A, y - A, z - A);
	}

	Vector3f operator * (float A)
	{
		return Vector3f(x * A, y * A, z * A);
	}
};


