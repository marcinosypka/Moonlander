#include "World.h"

//http://anttweakbar.sourceforge.net/doc/

World::World()
{
	gravity = Tools::moonA / Tools::scale;
	timestep = Tools::refreshFreq;
	zoom = -400.f;
	shipVelocity.x = 0.0f;
	shipVelocity.y = 0.0f;
	shipVelocity.z = 0.0f;
	position = 0.0f; 
	refuel = false;
}

float World::getFuel()
{
	return moonlander.fuelLeft();
}
void World::tryRefuel()
{
	if ((moonlander.position()).y == 0)
		moonlander.refuel();
}

World::~World()
{
}
Vector3f World::getVelocity()
{
	return moonlander.v();
}
Vector3f World::getPosition()
{
	return moonlander.position();
}
void World::initiate()
{

}

void World::changeCamera(int zooming)
{
	zoom += zooming;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, 1000 / 1000, 1.0, 10000.0f);
	glTranslatef(0.0f, 0.0f, zoom);
}

void World::render()
{
	moonlander.checkEngines(control);
	/*if (position <= -70.0f)
	{
		position = -70.0f;
		velocity = 0.0f;
	}
	if (engineOn) {
		velocity += timestep * shipA;
	}   
	velocity += timestep * gravity;
	position += timestep * (velocity + timestep * gravity / 2);
	*/
	moonlander.calcPosition();
	for (int i = 0; i < automaticallyDrawnShapes.size(); i++)
	{
		//tutaj powinny siê rysowaæ tylko obiekty których nie trzeba modyfikowaæ w ¿aden sposób
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glTranslatef(moonlander.pos.x, moonlander.pos.y, moonlander.pos.z);
		automaticallyDrawnShapes[i]->draw();
		glPopMatrix();
	}
	
	//tutaj rysujemy rêcznie, wprowadzaj¹c transformacje
	
	glMatrixMode(GL_MODELVIEW_MATRIX);	//macierz widoku modelu
	glPushMatrix();						//pobierasz aktualna macierz


	//glRotatef(-20.0f, 0.0f, 1.0f, 0.0f);
	glTranslatef(moonlander.pos.x, 13.1f + moonlander.pos.y, 44.5f + moonlander.pos.z);
	manuallyDrawnShapes[0]->draw();		//rysowanie obiektu
	glPopMatrix();						//przywracasz macierz poprzedni¹ - tê normaln¹, nie zmodyfikowan¹

	glPushMatrix();						
	glTranslatef(moonlander.pos.x, 13.1f + moonlander.pos.y, -44.5f + moonlander.pos.z);
	manuallyDrawnShapes[0]->draw();		
	glPopMatrix();

	glPushMatrix();					
	glTranslatef(moonlander.pos.x, 13.1f + moonlander.pos.y, moonlander.pos.z);
	manuallyDrawnShapes[0]->draw();
	glPopMatrix();

	glPushMatrix();						
	glTranslatef(moonlander.pos.x, 13.1f + moonlander.pos.y, moonlander.pos.z);
	manuallyDrawnShapes[0]->draw();		
	glPopMatrix();

	//drawing ground
	manuallyDrawnShapes[1]->draw();

}

void World::populate()
{
	//Shape *shape = new Cone();
	//automaticallyDrawnShapes.push_back(shape);		//tutaj dodaje shape do automatycznie rysowanego wektora

	//Cone *cone1 = new Cone(new Vector3f(0.0f, 7.0f, 0.0f), new Vector3f(0.0, 0.0f, 0.0f), 5.0f, 50.0f, 44.0f, 20);
	//cone1->setPart(0.7f);		//ustawiasz w jakiej czesci ma sie wyrysowac stozek
	
	//lowest past
	automaticallyDrawnShapes.push_back(new Cone(new Vector3f(0.0f, 7.0f, 0.0f), new Vector3f(0.1f, 0.3f, 0.4f), 6.0f, 40.0f, 34.0f, 32));
	automaticallyDrawnShapes.push_back(new Cone(new Vector3f(0.0f, 13.0f, 0.0f), new Vector3f(0.0f, 0.6f, 0.8f), 30.0f, 44.0f, 50.0f, 32));
	automaticallyDrawnShapes.push_back(new Cone(new Vector3f(0.0f, 43.0f, 0.0f), new Vector3f(0.2f, 0.3f, 0.5f), 13.0f, 35.0f, 44.0f, 32));
	automaticallyDrawnShapes.push_back(new Cone(new Vector3f(0.0f, 56.0f, 0.0f), new Vector3f(0.1f, 0.2f, 0.4f), 25.0f, 35.0f, 35.0f, 32));

	// gorna kopu³a
	//automaticallyDrawnShapes.push_back(new Cone(new Vector3f(0.0f, 81.0f, 0.0f), new Vector3f(0.0f, 0.1f, 0.2f), 5.0f, 30.0f, 35.0f, 32));
	automaticallyDrawnShapes.push_back(new Cone(new Vector3f(0.0f, 81.0f, 0.0f), new Vector3f(0.0f, 0.1f, 0.4f), 15.0f, 30.0f, 35.0f, 32));
	automaticallyDrawnShapes.push_back(new Cone(new Vector3f(0.0f, 96.0f, 0.0f), new Vector3f(0.0f, 0.1f, 0.6f), 15.0f, 13.0f, 30.0f, 32));
	automaticallyDrawnShapes.push_back(new Cone(new Vector3f(0.0f, 111.0f, 0.0f), new Vector3f(0.0f, 0.1f, 0.8f), 10.0f, 0.0f, 13.0f, 32));


	automaticallyDrawnShapes.push_back(new Cone(new Vector3f(0.0f, 13.0f, 0.0f), new Vector3f(1.0f, 0.5f, 0.0f), 0.0f, 50.0f, 34.0f, 32));

	//nogi
	automaticallyDrawnShapes.push_back(new Line(new Vector3f(-sin(Tools::PI / 4) * 45, 13.f, -cos(Tools::PI / 4) * 45), new Vector3f(-sin(Tools::PI / 4) * 45 - 10, -30.f, -cos(Tools::PI / 4) * 45 - 10), new Vector3f(0.f, 0.f, 0.f), 5.5f));
	automaticallyDrawnShapes.push_back(new Roller(new Vector3f(-sin(Tools::PI / 4) * 45 - 10, -30.f, -cos(Tools::PI / 4) * 45 - 10), new Vector3f(0.f, 0.f, 0.f), 10.f, 30.f, 5.f));

	automaticallyDrawnShapes.push_back(new Line(new Vector3f(sin(Tools::PI *3/4) * 45, 13.f, cos(Tools::PI * 3 / 4) * 45), new Vector3f(sin(Tools::PI * 3 / 4) * 45 + 10, -30.f, cos(Tools::PI * 3 / 4) * 45 - 10), new Vector3f(0.f, 0.f, 0.f), 5.5f));
	automaticallyDrawnShapes.push_back(new Roller(new Vector3f(sin(Tools::PI * 3 / 4) * 45 + 10, -30.f, cos(Tools::PI * 3 / 4) * 45 - 10), new Vector3f(0.f, 0.f, 0.f), 10.f, 30.f, 5.f));

	automaticallyDrawnShapes.push_back(new Line(new Vector3f(sin(Tools::PI * 7 / 4) * 45, 13.f, cos(Tools::PI  * 7 / 4) * 45), new Vector3f(sin(Tools::PI * 7 / 4) * 45 - 10, -30.f, cos(Tools::PI * 7 / 4) * 45 + 10), new Vector3f(0.f, 0.f, 0.f), 5.5f));
	automaticallyDrawnShapes.push_back(new Roller(new Vector3f(sin(Tools::PI * 7 / 4) * 45 - 10, -30.f, cos(Tools::PI * 7 / 4) * 45 + 10), new Vector3f(0.f, 0.f, 0.f), 10.f, 30.f, 5.f));

	automaticallyDrawnShapes.push_back(new Line(new Vector3f(sin(Tools::PI / 4) * 45, 13.f, cos(Tools::PI / 4) * 45), new Vector3f(sin(Tools::PI / 4) * 45 + 10, -30.f, cos(Tools::PI / 4) * 45 + 10), new Vector3f(0.f, 0.f, 0.f), 5.5f));
	automaticallyDrawnShapes.push_back(new Roller(new Vector3f(sin(Tools::PI / 4) * 45 + 10, -30.f, cos(Tools::PI / 4) * 45 + 10), new Vector3f(0.f, 0.f, 0.f), 10.f, 30.f, 5.f));

	
	automaticallyDrawnShapes.push_back(new SolarPanel());
	
	

	//shapes imitating engines
	Cone *cone = new Cone(new Vector3f(0.0f, 0.0f, 0.0f), new Vector3f(0.6f, 0.7f, 0.8f), 27.0f, 0.0f, 13.0f, 32);
	//cone->setPart(0.4f);
	cone->setBottomIsShown(true);
	Shape *shape = cone;
	manuallyDrawnShapes.push_back(shape);

	//pod³o¿e
	manuallyDrawnShapes.push_back(new Rectangle1());
	

}