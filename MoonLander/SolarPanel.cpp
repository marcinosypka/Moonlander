#include "SolarPanel.h"



SolarPanel::SolarPanel()
{
	this->position = new Vector3f(0, 30.0f, 0);
	this->width = 100;
	this->height = 0;
	this->depth = 100;

	texture = new Texture("Bitmapy\\checker.bmp");
}


SolarPanel::~SolarPanel()
{
}

void SolarPanel::draw()
{
	glColor3f(1.0f, 1.0f, 1.0f);

	texture->SetLocalTexture();

	glEnable(GL_TEXTURE_2D);

	glBegin(GL_POLYGON);
	glVertex3f(position->x - width, position->y, position->z + depth);
	glTexCoord2d(0.0, 0.0);
	glVertex3f(position->x + width, position->y, position->z + depth);
	glTexCoord2d(0.0, 1.0);
	glVertex3f(position->x + width, position->y, position->z - depth);
	glTexCoord2d(1.0, 1.0);
	glVertex3f(position->x - width, position->y, position->z - depth);
	glTexCoord2d(1.0, 0.0);
	glEnd();

	glDisable(GL_TEXTURE_2D);
}
