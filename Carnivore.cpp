#include "Carnivore.h"

#include "MapScene.h"

CCarnivore::CCarnivore()
{
}


CCarnivore::~CCarnivore()
{
	cout << " Usuwam miesozerce" << endl;
}

void CCarnivore::Move()
{

	if (getOnTheWay() == true)
	{

	}

	else if (getFertility() >= 100 && getOnTheWay() == false)
	{//PROG PLODNOSCI IDZIE DO MIEJSCA ROZMNAZANIA CHARAKTYRYSTYCZNEGO DLA DANEGO GATUNKU
		setOnTheWay(true);//ZWIERZE JEST GOTOWE DO ROZMNOZENIA
		int x, y;
		switch (getAnimalID()) {//STREFY GODOW DO POPRAWIENIA
		case 1:
		{
			x = 10;
			y = 6;

		}break;
		case 2:
		{
			x = 20;
			y = 12;

		}break;
		case 3:
		{
			x = 30;
			y = 18;

		}break;
		case 4:
		{
			x = 40;
			y = 24;

		}break;
		case 5:
		{
			x = 50;
			y = 30;

		}break;
		}
		setPosX(x);
		setPosY(y);
		auto action = MoveTo::create(0.3, Point((120 + 4 * x), (75 + 4 * y)));
		animalsprite->runAction(action);
	}
	else if (getHunger() > 50)//glodny drapieznik
	{
		int x = 0, y = 0;
		bool done = false;//poszukiwanie zwierzecia w zasiegu ataku
		for (list<CAnimal*>::iterator it = MapScene::animals.begin(); it != MapScene::animals.end(); ++it)
		{
			if ((*it) != this && (abs((*it)->getPosX() - getPosX()) + abs((*it)->getPosY() - getPosY()) < 4))
			{
				x = (*it)->getPosX() - getPosX(); y = (*it)->getPosY() - getPosY();
				(*it)->setHealth(0);//po¿arty
				Recover();
				done = true;
			}

			//poszukiwanie zwierzecia w zasiegu wzroku
			else if ((*it) != this && abs((*it)->getPosX() - getPosX()) + abs((*it)->getPosY() - getPosY()) < 15)
			{//jesli odleglosc jest wystarczajaco mala zapisz jej roznice
				x = (*it)->getPosX() - getPosX(); y = (*it)->getPosY() - getPosY();
				done = true;
			}
			
			if (done == true) break;	
		}//wyciagniecie znaku z roznicy odleglosci miedzy celem
		if (done == true) {
			if (x != getPosX())
				x > getPosX() ? x = 1 : x = -1;

			if (y != getPosY())
				y > getPosY() ? y = 1 : y = -1;
		}
		else//jesli nic nie znajdzie idz losowo
		{
			x = rand() % 3 - 1; y = rand() % 3 - 1;
		}
			auto action = MoveBy::create(0.3, Point(Vec2(4 * x, 4 * y)));
			animalsprite->runAction(action);
			setPosX(getPosX() + x);
			setPosY(getPosY() + y);
			
		}


	else if (getThirst() > 50)//jesli pragnienie
	{
		int x = 0, y = 0, miny = rand() % 10 - 4, minx=rand() % 10 - 4;
		for (int i = -4; i < 5; i++) {
			for (int j = -4; j < 5; j++)
			{

				if (MapScene::spriteArray[abs(getPosX() + i)][abs(getPosY() + j)].getIsWater() && abs(getPosY() + j) < 40 && abs(getPosX() + i) < 60)
				{
						x = i; y = j;
						if (minx < i)
							minx = x;
						if (miny < y)
							miny = y;
					}
				

			}
			x = minx; y = miny;
		}
		
			x > getPosX() ? x = 1 : x = -1;
			y > getPosY() ? y = 1 : y = -1;
		if (getPosX() != x || getPosY() != y) {
			auto action = MoveBy::create(0.3, Point(Vec2(4 * x, 4 * y)));
			animalsprite->runAction(action);
			setPosX(getPosX() + x);
			setPosY(getPosY() + y);
		}

	}
	else if (getPosX() > 0 && getPosX() < 59 && getPosY() > 0 && getPosY() < 39) {
		//PORUSZANIE SIE DLA PLODNOSCI < 100, glodu <50, pragnienia <50
		int a, b;
		
			a = (rand() % 3 - 1);
			b = (rand() % 3 - 1);
			setPosX(getPosX() + a);
			setPosY(getPosY() + b);
			
		
		auto action = MoveBy::create(0.3, Point(Vec2(4 * a, 4 * b)));
		animalsprite->runAction(action);
	}
	else if (getPosX() == 0 || getPosX() == 59 || getPosY() == 0 || getPosY() == 39) {//GRANICE POZA KTORE ZWIERZE NIE MOZE WYJSC
																					  //PORUSZANIE SIE NA GRANICY MAPY
		int a = 0, b = 0;
		switch (getPosX())
		{
		case 0: { a = 1;  } break;
		case 59: { a = -1;  } break;
		}

		switch (getPosY())
		{
		case 0: { b = 1; } break;
		case 39: {	b = -1; } break;
		}

		
			setPosX(getPosX() + a);
			setPosY(getPosY() + b);
			auto action = MoveBy::create(0.3, Point(Vec2(4 * a, 4 * b)));
			animalsprite->runAction(action);
		


	}

};