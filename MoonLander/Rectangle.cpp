#include "Rectangle.h"

Rectangle::Rectangle() {

}
Rectangle::Rectangle(Vector3f* position, Vector3f* color, float width, float height) {
	this->position = position;
	this->color = color;
	this->width = width;
	this->height = height;
	
}
Rectangle::~Rectangle() {

}
void Rectangle::draw() {

	glColor3fv(color->toArray());

	glBegin(GL_TRIANGLE_STRIP);
	glEnd();


}