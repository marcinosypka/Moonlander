#include "Circle.h"

Circle::Circle(Vector3f* position, Vector3f* color, float radius, float resolution, int GL_STRONA) {
	
	this->position = position;
	this->color = color;
	this->radius = radius;
	this->resolution = resolution;
	this->GL_STRONA = GL_STRONA;

}

Circle::~Circle(){}

void Circle::draw() {

	float step = Tools::PI * 2 / resolution;
	glColor3fv(color->toArray());

	glFrontFace(GL_STRONA);
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(position->x, position->y, position->z);
	for (double i = 0.f; i <= 2 * Tools::PI + 0.01; i += step) {
		glVertex3f(position->x +radius * cos(i), position->y, position->z + radius * sin(i));
	}
	glEnd();


}