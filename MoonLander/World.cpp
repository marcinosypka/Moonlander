#include "World.h"



World::World()
{

}


World::~World()
{
}

void World::initiate()
{

}

void World::render()
{
	for (int i = 0; i < automaticallyDrawnShapes.size(); i++)
	{
		//tutaj powinny siê rysowaæ tylko obiekty których nie trzeba modyfikowaæ w ¿aden sposób
		automaticallyDrawnShapes[i]->draw();
	}
	
	//tutaj rysujemy rêcznie, wprowadzaj¹c transformacje

	glMatrixMode(GL_MODELVIEW_MATRIX);	//macierz widoku modelu
	glPushMatrix();						//pobierasz aktualna macierz


	//glRotatef(-20.0f, 0.0f, 1.0f, 0.0f);
	glTranslatef(0.0f, 13.1f, 44.5f);
	manuallyDrawnShapes[0]->draw();		//rysowanie obiektu
	glPopMatrix();						//przywracasz macierz poprzedni¹ - tê normaln¹, nie zmodyfikowan¹

	glPushMatrix();						
	glTranslatef(0.0f, 13.1f, -44.5f);
	manuallyDrawnShapes[0]->draw();		
	glPopMatrix();

	glPushMatrix();					
	glTranslatef(44.5f, 13.1f, 0.0f);
	manuallyDrawnShapes[0]->draw();
	glPopMatrix();

	glPushMatrix();						
	glTranslatef(-44.5f, 13.1f, 0.0f);
	manuallyDrawnShapes[0]->draw();		
	glPopMatrix();

	
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
	automaticallyDrawnShapes.push_back(new Cone(new Vector3f(0.0f, 43.0f, 0.0f), new Vector3f(0.2f, 0.3f, 0.5f), 13.0f, 25.0f, 44.0f, 32));
	automaticallyDrawnShapes.push_back(new Cone(new Vector3f(0.0f, 56.0f, 0.0f), new Vector3f(0.1f, 0.2f, 0.4f), 25.0f, 25.0f, 25.0f, 32));
	automaticallyDrawnShapes.push_back(new Cone(new Vector3f(0.0f, 81.0f, 0.0f), new Vector3f(0.0f, 0.1f, 0.2f), 10.0f, 0.0f, 25.0f, 32));
	automaticallyDrawnShapes.push_back(new Circle(new Vector3f(0.0f, 13.0f, 0.0f), new Vector3f(1.0f, 0.5f, 0.0f), 50.0f, 32));
	automaticallyDrawnShapes.push_back(new Rectangle1());
	automaticallyDrawnShapes.push_back(new Circle(new Vector3f(0.0f, 13.0f, 0.0f), new Vector3f(1.0f, 0.5f, 0.0f), 50.0f, 32));
	//automaticallyDrawnShapes.push_back(new Line(new Vector3f(0.f, 0.f, 0.f), new Vector3f(100.f, 100.f, 100.f), new Vector3f(0.f, 0.f, 0.f),2.5f));
	//shapes imitating engines
	Cone *cone = new Cone(new Vector3f(0.0f, 0.0f, 0.0f), new Vector3f(0.6f, 0.7f, 0.8f), 27.0f, 0.0f, 13.0f, 32);
	//cone->setPart(0.4f);
	cone->setBottomIsShown(true);
	Shape *shape = cone;
	manuallyDrawnShapes.push_back(shape);

}