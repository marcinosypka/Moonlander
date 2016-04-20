#include "Rectangle1.h"


Rectangle1::Rectangle1(Vector3f* position, Vector3f* color, float width, float height, float depth) {
	this->position = position;
	this->color = color;
	this->width = width;
	this->height = height;
	this->depth = depth;
}
Rectangle1::Rectangle1() {
	this->position = new Vector3f(-300, 0, -300);
	this->color = new Vector3f(0.4f, 0.2f, 0.f);
	this->width = 600;
	this->height = 0;
	this->depth = 600;
}
Rectangle1::~Rectangle1() {
	delete position;
	delete color;

}
void Rectangle1::draw() {

	glColor3fv(color->toArray());

	glBegin(GL_POLYGON);
	glVertex3f(position->x, position->y, position->z);
	glVertex3f(position->x, position->y, position->z + depth);
	glVertex3f(position->x + width, position->y + height, position->z + depth);
	glVertex3f(position->x + width, position->y + height, position->z);
	glEnd();
	glBegin(GL_TRIANGLE_STRIP);

	glEnd();


}