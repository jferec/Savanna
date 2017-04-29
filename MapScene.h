#pragma once
#ifndef MAPSCENE_H
#define MAPSCENE_H
#include "c:\Users\Jan\Desktop\MyCppGame\proj.win32\Tile.h"

#include <string.h>


USING_NS_CC;

using namespace ui;
using namespace std;
class CAnimal;

class MapScene : public cocos2d::Layer
{

public:

	static cocos2d::Scene* createScene();

	virtual bool init();

	// a selector callback
	void GoBack(Ref *pSender);//FUNKCJA POWROTU
	void textFieldEvent3(Ref *sender, ui::TextField::EventType type);////TEXT FIELD EVENTY
	void textFieldEvent4(Ref *sender, ui::TextField::EventType type);
	void textFieldEvent5(Ref *sender, ui::TextField::EventType type);
	void textFieldEvent6(Ref *sender, ui::TextField::EventType type);
	void textFieldEvent7(Ref *sender, ui::TextField::EventType type);
	void textFieldEvent8(Ref *sender, ui::TextField::EventType type);/////////////////////
	void touchEvent(Ref *sender, Widget::TouchEventType type);////////TOUCH EVENTY DO BUTTONOW
	void touchEvent1(Ref *sender, Widget::TouchEventType type);//////
	void touchEvent2(Ref *sender, Widget::TouchEventType type);
	void touchEvent3(Ref *sender, Widget::TouchEventType type);
	void touchEvent4(Ref *sender, Widget::TouchEventType type);
	void touchEvent5(Ref *sender, Widget::TouchEventType type);//////
	static CTile spriteArray[60][40];
	static list <CAnimal*> animals;
	void AddAnimal(bool male, int age, int posX, int posY, int a);//EDYTUJ~!!!!!!
	void AddRandomAnimal();
	Layer* layer;
	bool male;//////////////////////////////////
	unsigned int age, posx, posy, IDdelete;/////ZMIENNE DO TWORZENIA ZWIERZAT
	void AddRandomWater();////////////FUNKCJE DO OBS£UGI MAPY
	void AddRandomTree();
	void Reproduce();
	void DeleteID(int id);
	void Clean();/////////////////////
	void TimerMethod(float dt);//////WYSWIETLANIE LISTY ZWIERZAT
	void UptadeFunction(float dt);
	Label *label8;// deklaracja napisu, aby moc go uzywac
	string animalList;////STRING NA LISTE ZWIERZAT


	// implement the "static create()" method manually
	CREATE_FUNC(MapScene);
};

#endif MAPSCENE_H
