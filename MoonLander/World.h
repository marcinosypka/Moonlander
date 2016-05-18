#pragma once
#include <vector>
#include "Shape.h"
#include "Cone.h"
#include "Circle.h"
#include "Roller.h"
#include "Rectangle1.h"
#include "Line.h"
#include "Tools.h"
#include "SolarPanel.h"


class World
{
public:
	World();
	~World();

	void render();
	void populate();

	void initiate();
	float position;
	Vector3f shipVelocity;
	bool engineOn =false;

	void changeCamera(int zooming);

private:
	std::vector<Shape*> automaticallyDrawnShapes;
	std::vector<Shape*> manuallyDrawnShapes;
	float gravity = -16.2f;
	float timestep = 0.04;
	float time = 0;
	float velocity = 0;
	float shipA = 30.0f;
	float shipV = 0;
	
	float zoom = -400.0f;
	
	
};

