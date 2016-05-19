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
#include "MoonLander.h"


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
	bool control[5];
	void changeCamera(int zooming);

	

private:
	std::vector<Shape*> automaticallyDrawnShapes;
	std::vector<Shape*> manuallyDrawnShapes;
	float gravity;
	float timestep;
	float velocity = 0;
	float shipA = 3.00f;
	float shipV = 0;
	float zoom;
	MoonLander moonlander;
	
	
};

