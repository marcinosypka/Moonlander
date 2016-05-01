#include "Line.h"


Line::Line(Vector3f* vertexA, Vector3f* vertexB, Vector3f* color, float lineWidth) {
	this->vertexA = vertexA;
	this->vertexB = vertexB;
	this->color = color;
	this->lineWidth = lineWidth;

}
Line::Line() {
	this->vertexA = new Vector3f(0, 0, 0);
	this->vertexB = new Vector3f(10, 10, 10);
	this->color = new Vector3f(0.4f, 0.2f, 0.f);
	this->lineWidth = 2.5;
}
Line::~Line() {
	delete vertexA;
	delete vertexB;
	delete color;

}
void Line::draw() {

	glColor3fv(color->toArray());
	glLineWidth(lineWidth);
	glBegin(GL_LINES);
	glVertex3f(vertexA->x, vertexA->y, vertexA->z);
	glVertex3f(vertexB->x, vertexB->y, vertexB->z);
	glEnd();

}