#include "Herbivore.h"
#include <cmath>
#include "MapScene.h"



void CHerbivore::Move() {
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

	else if (getHunger() > 50)
	{
		int x = 0, y = 0;
		for (int i = -5; i < 5; i++) {
			for (int j = -5; j < 5; j++)
			{

				if (MapScene::spriteArray[abs(getPosX() + i)][abs(getPosY() + j)].getIsFlora() && abs(getPosY() + j) < 40 && abs(getPosX() + i) < 60)
				{
				
						x = abs(getPosX() + i); y = abs(getPosX() + j);
				}

			}
		}
		if (x != getPosX())
			x > getPosX() ? x = 1 : x = -1;

		if (y != getPosY())
			y > getPosY() ? y = 1 : y = -1;
		if (getPosX() != x || getPosY() != y) {
			auto action = MoveBy::create(0.3, Point(Vec2(4 * x, 4 * y)));
			animalsprite->runAction(action);
			setPosX(getPosX() + x);
			setPosY(getPosY() + y);
		}
	}
	else if (getThirst() > 50)
	{
		int x = 0, y = 0;
		for (int i = -5; i < 5; i++) {
			for (int j = -5; j < 5; j++)
			{

				if (MapScene::spriteArray[abs(getPosX() + i)][abs(getPosY() + j)].getIsWater() && abs(getPosY() + j) < 40 && abs(getPosX() + i) < 60)
				{
				
						x = abs(getPosX() + i); y = abs(getPosY() + j);

				}

			}
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
		{//PORUSZANIE SIE NA GRANICY MAPY
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

			if (a != 0 || b != 0) {
				setPosX(getPosX() + a);
				setPosY(getPosY() + b);
				auto action = MoveBy::create(0.3, Point(Vec2(4 * a, 4 * b)));
				animalsprite->runAction(action);
			}
		}

	}
}





CHerbivore::CHerbivore()
{
}


CHerbivore::~CHerbivore()
{
	cout << " Usuwam roslinozerce" << endl;
}
