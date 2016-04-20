#include "Cone.h"

//#include "glut.h"

Cone::Cone(Vector3f* position, Vector3f* color, float height, float upperRadius, float lowerRadius, float resolution)
{
	this->position = position;
	this->color = color;
	this->height = height;
	this->upperRadius = upperRadius;
	this->lowerRadius = lowerRadius;
	this->resolution = resolution;
	this->part = 1.0f;
	bottom = new Circle(position, color, lowerRadius, resolution);
	topCirclepossition = new Vector3f(position->x, position->y + height, position->z);
	top = new Circle(topCirclepossition, color, upperRadius, resolution, GL_CW);
}

Cone::Cone()
{
	this->position = new Vector3f(0.0f, 0.0f, 0.0f);
	this->color = new Vector3f(0.0f, 0.0f, 0.0f);
	this->height = 40.f;
	this->upperRadius = 0.0f;
	this->lowerRadius = 30.0f;
	this->resolution = 16;
	this->part = 1.0f;
	bottom = new Circle(position, color, lowerRadius, resolution);
	topCirclepossition = new Vector3f(position->x, position->y + height, position->z);
	top = new Circle(topCirclepossition, color, upperRadius, resolution, GL_CW);
}

Cone::~Cone()
{
}

void Cone::setPart(float part)
{
	this->part = part;
}

void Cone::setTopIsShown(bool shown)
{
	topIsShown = shown;
}
void Cone::setBottomIsShown(bool shown)
{
	bottomIsShown = shown;
}

void Cone::draw()
{
	if (topIsShown) {
		top->draw();
	}
	if (bottomIsShown) {
		bottom->draw();
	}

	float step = Tools::PI * 2 / resolution;

	glColor3fv(color->toArray());

	glBegin(GL_TRIANGLE_STRIP);
	for (float i = 0.0f; i <= (Tools::PI * 2 + 0.01) * part; i += step)
	{
		glVertex3f(position->x + lowerRadius * cos(i), position->y, position->z + lowerRadius * sin(i));
		glVertex3f(position->x + upperRadius * cos(i), position->y + height, position->z + upperRadius * sin(i));
	}
	glEnd();
	
}
