#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include <iostream>
#include "ui\CocosGUI.h"
#include "C:\Users\Jan\Desktop\MyCppGame\proj.win32\Animal.h"
#include "c:\Users\Jan\Desktop\MyCppGame\proj.win32\MapScene.h"
#include "EndGameScene.h"
#include "Stats.h"


//SCENA ZE STATYSTYKAMI


USING_NS_CC;

using namespace ui;
using namespace std;

string EndGameScene::stats = "";//INICJACJA STATIC STRINGA

Scene* EndGameScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = EndGameScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool EndGameScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}


	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	Vector<MenuItem*> MenuItems;//wektor przechowuj¹cy itemy menu, z ktorego utworzymy menu pozniej
								/////////////////////////////

	//LABEL CONFIG DO NAPISOW
	TTFConfig labelConfig;
	labelConfig.fontSize = 25;
	labelConfig.outlineSize = 2;
	labelConfig.fontFilePath = "fonts/Marker Felt.ttf";

	auto label = Label::createWithTTF(labelConfig, "STATYSTYKI");

	// position the label on the center of the screen
	label->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height - label->getContentSize().height));

	// add the label as a child to this layer
	this->addChild(label, 1);

	// add savanna background
	auto sprite = Sprite::create("savanna.jpg");

	// position the sprite on the center of the screen (savanna background)
	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	// add the sprite as a child to this layer(-5 to be displayed first)
	this->addChild(sprite, -5);


	// add a "close" icon to exit the progress. MenuItem responsible for closing the window and exiting the program from the scene.
	auto closeItem = MenuItemImage::create(
						"zakoncz.png", "zakoncz.png",
		CC_CALLBACK_1(EndGameScene::menuCloseCallback, this));

//TWORZENIE MENU

	closeItem->setPosition(Vec2(0, 0));
	closeItem->setAnchorPoint(Vec2(0.5, 0.5));
	closeItem->setPosition(Vec2(visibleSize.width / 3, -visibleSize.height / 3));
	MenuItems.pushBack(closeItem);
	auto menu = Menu::createWithArray(MenuItems);
	menu->setPosition(Vec2(visibleSize.width / 2.0, visibleSize.height / 1.5));
	this->addChild(menu, 6);
//KONIEC TWORZENIA MENU
//TWORZENIE STRINGA DO WYSWIETLENIA STATYSTYK ZGROMADZONYCH PRZEZ KLASE
	stats.append("Liczba wszystkich zwierzat :");
	stats += to_string(CStats::getNumberOfAnimals());///////LICZBA WSZYSTKICH ZWIERZAT
	stats.append("\nLiczba zgonow :");
	stats += to_string(CStats::getNumberOfDeaths());////////LICZBA ZGONOW
	stats.append("\nLiczba posilkow :");
	stats += to_string(CStats::getNumberOfEating());////////LICZBA POSILKOW
	stats.append("\nLiczba spozyc wody :");
	stats += to_string(CStats::getNumberOfDrinking());//////LICZBA SPOZYC WODY
	stats.append("\nLiczba rozmnozen :");
	stats += to_string(CStats::getNumberOfReproductions());//LICZBA ROZMNOZEN
	stats.append("\nCzas symulacji :");
	stats += to_string(CStats::getSimulationTime());/////////CZAS SYMULACJI


	label1 = Label::createWithTTF(" ", "fonts/CaviarDreams.ttf", 20);
	label1->enableBold();
	label1->setString(stats);
	label1->setPosition(Vec2(visibleSize.width / 2.0, visibleSize.height / 1.5));
	this->addChild(label1, 10);


	return true;
}

void EndGameScene::menuCloseCallback(Ref* pSender) // event listener to close menu item.
{
	//Close the cocos2d-x game scene and quit the application
	CStats::setGeneratedID(100000);
	CStats::setNumberOfAnimals(0);
	CStats::setNumberOfDrinking(0);
	CStats::setNumberOfDeaths(0);
	CStats::setNumberOfEating(0);
	CStats::setSimulationTime(0);
	CStats::setTotalAge(0);
	CStats::setNumberOfReproductions(0);
	EndGameScene::stats.clear();
	auto scene = HelloWorld::createScene();
	Director::getInstance()->replaceScene(scene);


#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif

	/*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

	//EventCustom customEndEvent("game_scene_close_event");
	//_eventDispatcher->dispatchEvent(&customEndEvent);


}
