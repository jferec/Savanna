#pragma once
//Autor : Jan Ferêc Prowadz¹cy: Mgr Bart³omiej Gajewski
#ifndef ANIMAL_H
#define ANIMAL_H
#include<iostream>
#include<vector>
#include "cocos2d.h"
#include "ui\CocosGUI.h"
#include "Stats.h"


USING_NS_CC;

using namespace std;
using namespace ui;
class CTile;
class MapScene;
class CAnimal//klasa zwierzat
{

public:

	
	CAnimal();
	virtual ~CAnimal() { cout << "Zwierze o ID:" << m_ID << "usuniêto" << endl;
	CStats::setNumberOfDeaths(CStats::getNumberOfDeaths() + 1);
	};//destruktor zwierz¹t
	void Recover();
	void Drink();////////////////////////////////////////////////////
	void Eat();//////////////////////////////////////////////////////
	int getPosX() { return m_PosX; };///////////////////GETTERY OBIEKTÓW CANIMAL
	int getPosY() { return m_PosY; };///////////////////
	int getAge() { return m_Age; };/////////////////////
	int getID() { return m_ID; };///////////////////////
	int getAnimalID() { return m_AnimalID; };
	unsigned int getHealth() { return m_Health; };
	unsigned int getThirst() { return m_Thirst; };
	unsigned int getHunger() { return m_Hunger; };
	unsigned int getFertility() { return m_Fertility; };
	bool getOnTheWay() { return m_OnTheWay; };
	bool getReadyToReproduce() { return m_ReadyToReproduce; };
	void setAge(unsigned int value);
	void setHealth(unsigned int value);
	void setThirst(unsigned int value);
	void setHunger(unsigned int value);
	void setPosX(unsigned int value);
	void setPosY(unsigned int value);
	void setFertility(unsigned int value);
	void setReadyToReproduce(bool value);
	void setOnTheWay(bool value);
	void setAnimalID(int value);
	void setMale(bool value);
	bool getMale() { return m_Male; };//////////////////
	Sprite *animalsprite;
	void GetOlder();
	void Die();
	void PhysicalNeeds();
	virtual void Logic() {};
	bool CheckIfWater(int x, int y);
	void AfterReproduction();
	typedef bool f_type(int, int);


private://POLA OBIEKTÓW CNANIMAL:

	
	bool m_Male;//////////////////P£EÆ
	int m_Age;////////////////////WIEK
	int m_ID;/////////////////////ID ZWIERZECIA
	int m_PosX;///////////////////POZYCJA X NA MAPIE
	int m_PosY;///////////////////POZYCJA Y NA MAPIE
	string m_SpeciesName;/////////NAZWA ZWIERZECIA
	unsigned int m_Health;////////ZDROWIE
	unsigned int m_Thirst;////////PRAGNIENIE
	unsigned int m_Hunger;////////G£ÓD
	unsigned int m_Fertility;/////P£ODNOŒÆ
	bool m_OnTheWay;//////////////CZY ZWIERZAK JEST W DRODZE?
	bool m_ReadyToReproduce;
	int m_AnimalID;


};//poprawic CTile
#endif ANIMAL_H
