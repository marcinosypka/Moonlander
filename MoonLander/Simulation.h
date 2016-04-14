#pragma once
#include "RESOURCE.H"
#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>            // Window defines
#include <gl\gl.h>              // OpenGL
#include <gl\glu.h>             // GLU library
#include <math.h>				// Define for sqrt
#include <stdio.h>
#include "resource.h"			// About box resource identifiers.



class Simulation
{
//###################  STATIC VARIABLES  ##########################


	GLfloat xRot;// = 0.0f;
	GLfloat yRot;// = 0.0f;
	GLsizei lastHeight;
	GLsizei lastWidth;

//################### MEMBERS#######################################





//################### METHODS ######################################
	
	void ChangeSize(GLsizei w, GLsizei h);
	void SetupRC();
	void ReduceToUnit(float vector[3]);
	void calcNormal(float v[3][3], float out[3]);
	void RenderScene(void);
	void SetDCPixelFormat(HDC hDC);
	
	
public: 
	Simulation();
	
	static void run();
};
