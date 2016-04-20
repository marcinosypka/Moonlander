#pragma once
#include <vector>
#include "Shape.h"
#include "Cone.h"
#include "Circle.h"
#include "Roller.h"
#include "Rectangle1.h"



class World
{
public:
	World();
	~World();

	void render();
	void populate();

	void initiate();

private:
	std::vector<Shape*> automaticallyDrawnShapes;
	std::vector<Shape*> manuallyDrawnShapes;
};

