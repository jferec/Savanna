//Autor : Jan Ferêc Prowadz¹cy: Mgr Bart³omiej Gajewski
#include <cstdlib>
#include "C:\Users\Jan\Desktop\MyCppGame\proj.win32\Animal.h"
#include "C:\Users\Jan\Desktop\MyCppGame\proj.win32\MapScene.h"
#include <time.h>
#include <string>
#include "cocos2d.h"
#include "ui\CocosGUI.h"
#include "Stats.h"
#include <iostream>

using namespace std;
USING_NS_CC;



//FUNKCJA ODPOWIEDZIALNA ZA PORUSZANIE
/*void CAnimal::Move(){
	if (getOnTheWay() == true)
	{
		
	}
	else if (getFertility() >= 100 && getOnTheWay() == false)
	{//PROG PLODNOSCI IDZIE DO MIEJSCA ROZMNAZANIA CHARAKTYRYSTYCZNEGO DLA DANEGO GATUNKU
		setOnTheWay(true);//ZWIERZE JEST GOTOWE DO ROZMNOZENIA
		int x, y;
		switch (getSpieces()) {//STREFY GODOW DO POPRAWIENIA
		case CAnimal::Slon:
		{
			x = 10;
			y = 6;

		}break;
		case CAnimal::Szakal:
		{
			x = 20;
			y = 12;

		}break;
		case CAnimal::Lew:
		{
			x = 30;
			y = 18;

		}break;
		case CAnimal::Sep:
		{
			x = 40;
			y = 24;

		}break;
		case CAnimal::Zyrafa:
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


	else if (getPosX() > 0 && getPosX() < 59 && getPosY() > 0 && getPosY() < 39) {
		//PORUSZANIE SIE DLA PLODNOSCI < 100;

		int a = (rand() % 3 - 1);
		int b = (rand() % 3 - 1);
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
				auto action = MoveBy::create(0.3, Point(Vec2(4*a, 4*b)));
				animalsprite->runAction(action);
			}
		}

	}
}*/


void CAnimal::setPosX(unsigned int value)
{
	m_PosX = value;
}

void CAnimal::setAnimalID(int value)
{
	m_AnimalID = value;
}

void CAnimal::setPosY(unsigned int value)
{
	m_PosY = value;
}

void CAnimal::Drink()
{
	for (int i = -1; i < 2; i++) {
		for(int j = 1; j<2; j++){
			if (MapScene::spriteArray[abs(getPosX()+i)][abs(getPosY()+j)].getIsWater()&& abs(getPosX() + i)<60 && abs(getPosY() + j)<40)
			{
				this->m_Thirst = 0;
				CStats::setNumberOfDrinking(CStats::getNumberOfDrinking() + 1);
			}
		
		}
	}

}
void CAnimal::Eat()
{
	for (int i = -1; i < 2; i++) {
		for (int j = 1; j<2; j++) {
			if (MapScene::spriteArray[abs(getPosX() + i)][abs(getPosY() + j)].getIsFlora() && abs(getPosX() + i)<60 && abs(getPosY() + j)<40)
			{
				this->m_Hunger = 0;
				CStats::setNumberOfEating(CStats::getNumberOfEating() + 1);
			}

		}
	}

}
void CAnimal::Recover()
{
	this->m_Health = 100;
	this->m_Hunger = 0;
	this->m_Thirst = 0;
}
void CAnimal::setHealth(unsigned int value)
{
	m_Health = value;
}
void CAnimal::setThirst(unsigned int value)
{
	m_Thirst = value;

}

void CAnimal::setHunger(unsigned int value)
{

	m_Hunger = value;

}

void CAnimal::setAge(unsigned int value)
{

	m_Age = value;

}

void CAnimal::setMale(bool a)
{

	m_Male = a;

}

void CAnimal::setFertility(unsigned int value)
{

	m_Fertility = value;

}
void CAnimal::setOnTheWay(bool value)
{
	m_OnTheWay = value;
}
void CAnimal::setReadyToReproduce(bool value)
{
	m_ReadyToReproduce = value;
}

void CAnimal::GetOlder()
{
	setAge(getAge() + 1);
	CStats::setTotalAge(CStats::getTotalAge() + 1);
}

void CAnimal::Die()
{
		cout << "Zwierze umarlo";
		(animalsprite)->removeFromParentAndCleanup(true);
}

void CAnimal::PhysicalNeeds()
{
	Eat();
	Drink();
	GetOlder();
	//P£ODNOŒÆ ROSN¥CA W CZASIE
	setFertility(getFertility() + 1);
	if (getHealth() > 100)
		setHealth(100);
	//JEDZENIE I PICIE ORAZ ICH WPLYW NA PUNKTY ¯YCIA
	if (getHunger() != 100)
	{
		setHunger(getHunger() + 1);
	}
	else
		setHealth(getHealth() - 5);
	if (getThirst() != 100)
	{
		setThirst(getThirst() + 1);
	}
	else {
		setHealth(getHealth() - 5);
	}
}


void CAnimal::AfterReproduction()//ZEROWANIE PLODNOSCI PO ROZMNOZENIU
{
	setOnTheWay(false);
	setFertility(0);

}




CAnimal::CAnimal()//konstruktor wykorzystywany do
																					 //manualnego tworzenia obiektu CAnimal

{////////////PRZYPISYWANIE ZMIENNYCH I WYŒWIETLENIE KOMUNIKATU O UTWORZENIU OBIEKTU CANIMAL/////////////////////////////
	srand(time(NULL));
	//m_Male = male;
	//m_Age = age;
	m_ID = CStats::IDGenerator();
	//m_PosX = posX;
	//m_PosY = posY;;
	m_Hunger = 0;
	m_Thirst = 0;
	m_Health = 100;
	m_Fertility = 0;
	m_OnTheWay = false;
	std::cout << " Stworzyles zwierze" << std::endl;
	

}



