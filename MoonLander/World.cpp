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
	glTranslatef(60.0f, 0.0f, 0.0f);	//wszelkie operacje
	glRotatef(30.0f, 1.0f, 0.0f, 0.0f);
	manuallyDrawnShapes[0]->draw();		//rysowanie obiektu
	glPopMatrix();						//przywracasz macierz poprzedni¹ - tê normaln¹, nie zmodyfikowan¹
	
}

void World::populate()
{
	Shape *shape = new Cone();
	automaticallyDrawnShapes.push_back(shape);		//tutaj dodaje shape do automatycznie rysowanego wektora


	Cone *cone1 = new Cone(new Vector3f(0.0f, 0.0f, 0.0f), new Vector3f(1.0, 0.0f, 0.0f), 50.0f, 10.0f, 60.0f, 32);
	cone1->setPart(0.7f);		//ustawiasz w jakiej czesci ma sie wyrysowac stozek
	Shape *shape1 = cone1;
	manuallyDrawnShapes.push_back(shape1);			//dodaje shape do recznie rysowanego wektora
}