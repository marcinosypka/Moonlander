#include "World.h"



World::World()
{

}


World::~World()
{
}

void World::initiate()
{

}

void World::render()
{
	for (int i = 0; i < shapes.size(); i++)
	{
		shapes[i]->draw();
	}
}

void World::populate()
{
	
	shapes.push_back(new Cone());
	shapes.push_back(new Circle());
	shapes.push_back(new Roller());
}