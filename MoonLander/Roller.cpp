#include "Roller.h"

Roller::Roller(Vector3f* position, Vector3f* color, float radius, float resolution, float height) {

	this->position = position;
	this->color = color;
	this->radius = radius;
	this->resolution = resolution;
	this->height = height;
	bottom = new Circle(position, color, radius, resolution);
	topCirclepossition = new Vector3f(position->x, position->y + height, position->z);
	top = new Circle(topCirclepossition, color, radius, resolution,GL_CW);
}

Roller::~Roller() {
	delete topCirclepossition;
}

void Roller::draw() {
	if (topIsShown) {
		top->draw();
	}
	if (bottomIsShown) {
		bottom->draw();
	}
	glFrontFace(GL_CCW);

	float step = Tools::PI * 2 / resolution;
	glColor3fv(color->toArray());

	glBegin(GL_TRIANGLE_STRIP);
	for (float i = 0.0f; i <= Tools::PI * 2 + 0.01; i += step)
	{
		glVertex3f(position->x + radius * cos(i), position->y,position->z + radius * sin(i));
		glVertex3f(position->x + radius * cos(i), position->y + height, position->z + radius * sin(i));
	}
	glEnd();

}