#pragma once
#include <vector>
#include "Shape.h"
#include "Cone.h"


class World
{
public:
	World();
	~World();

	void render();
	void populate();

	void initiate();

private:
	std::vector<Shape*> shapes;
};

