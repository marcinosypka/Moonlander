#include "SolarPanel.h"



SolarPanel::SolarPanel()
{
	this->position = new Vector3f(-10.0f, 60.0f, 32.0f);
	this->width = 20;
	this->height = 20;
	this->depth = 5;

	texture = new Texture("Bitmapy\\Panel.bmp");
}


SolarPanel::~SolarPanel()
{
}

void SolarPanel::draw()
{
	glColor3f(0.7f, 0.7f, 0.9f);
	glBegin(GL_POLYGON);
	glVertex3f(position->x, position->y, position->z);
	glVertex3f(position->x, position->y, position->z + depth);
	glVertex3f(position->x, position->y + height, position->z + depth);
	glVertex3f(position->x, position->y + height, position->z);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(position->x, position->y + height, position->z);
	glVertex3f(position->x, position->y + height, position->z + depth);
	glVertex3f(position->x + width, position->y + height, position->z + depth);
	glVertex3f(position->x + width, position->y + height, position->z);
	glEnd();

	glFrontFace(GL_CW);
	glBegin(GL_POLYGON);
	glVertex3f(position->x + width, position->y, position->z);
	glVertex3f(position->x + width, position->y, position->z + depth);
	glVertex3f(position->x + width, position->y + height, position->z + depth);
	glVertex3f(position->x + width, position->y + height, position->z);
	glEnd();

	glFrontFace(GL_CW);
	glBegin(GL_POLYGON);
	glVertex3f(position->x, position->y, position->z);
	glVertex3f(position->x, position->y, position->z + depth);
	glVertex3f(position->x + width, position->y, position->z + depth);
	glVertex3f(position->x + width, position->y, position->z);
	glEnd();

	glFrontFace(GL_CCW);
	glBegin(GL_POLYGON);
	glVertex3f(position->x, position->y, position->z );
	glVertex3f(position->x, position->y + height, position->z );
	glVertex3f(position->x + width, position->y + height, position->z );
	glVertex3f(position->x + width, position->y, position->z );
	glEnd();


	glColor3f(1.0f, 1.0f, 1.0f);

	texture->SetLocalTexture();
	glEnable(GL_TEXTURE_2D);
	glFrontFace(GL_CW);
	glBegin(GL_POLYGON);
	glVertex3f(position->x, position->y, position->z + depth);
	glTexCoord2d(0.0, 0.0);
	glVertex3f(position->x, position->y + height, position->z + depth);
	glTexCoord2d(0.0, 1.0);
	glVertex3f(position->x + width, position->y + height, position->z + depth);
	glTexCoord2d(1.0, 1.0);
	glVertex3f(position->x + width, position->y, position->z + depth);
	glTexCoord2d(1.0, 0.0);
	glEnd();

	glDisable(GL_TEXTURE_2D);

}
