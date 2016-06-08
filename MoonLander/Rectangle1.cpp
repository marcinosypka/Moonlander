#include "Rectangle1.h"


Rectangle1::Rectangle1(Vector3f* position, Vector3f* color, float width, float height, float depth) {
	this->position = position;
	this->color = color;
	this->width = width;
	this->height = height;
	this->depth = depth;
}
Rectangle1::Rectangle1() {
	this->position = new Vector3f(0, -30.0f, 0);
	this->color = new Vector3f(0.4f, 0.2f, 0.f);
	this->width = 10000;
	this->height = 0;
	this->depth = 10000;


}
Rectangle1::~Rectangle1() {
	delete position;
	delete color;

}
void Rectangle1::draw() {

	glColor3fv(color->toArray());
	//glColor3f(1.0f, 1.0f, 1.0f);



	glEnable(GL_TEXTURE_2D);
	glFrontFace(GL_CCW);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(position->x - width, position->y, position->z + depth);
	glTexCoord2d(0, 1);
	glVertex3f(position->x + width, position->y, position->z + depth);
	glTexCoord2d(1, 1);
	glVertex3f(position->x + width, position->y, position->z - depth);
	glTexCoord2d(1, 0);
	glVertex3f(position->x - width, position->y, position->z - depth);
	
	glEnd();

	glDisable(GL_TEXTURE_2D);

}