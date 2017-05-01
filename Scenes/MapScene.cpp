
#include "HelloWorldScene.h"
#include <iostream>
#include "ui\CocosGUI.h"
#include <cstdlib>
#include "C:\Users\Jan\Desktop\MyCppGame\proj.win32\Animal.h"
#include "C:\Users\Jan\Desktop\MyCppGame\proj.win32\MapScene.h"
#include "HelloWorldScene.h"
#include <vector>
#include <list>
#include "cocos2d.h"
#include <time.h>
#include "EndGameScene.h"
#include "Stats.h"
#include "Vulture.h"
#include "Lion.h"
#include "Crocodile.h"
#include "Hippo.h"
#include "Giraffe.h"
USING_NS_CC;

using namespace ui;
using namespace std;

CTile a;
CTile MapScene::spriteArray[60][40] = { a };
CAnimal* p = new CVulture;
list <CAnimal*> MapScene::animals = { p };

class CAnimal;


Scene* MapScene::createScene()
{
	// 'scene' is an autorelease object
	Scene* MapScene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = MapScene::create();

	// add layer as a child to scene
	MapScene->addChild(layer);

	// return the scene
	return  MapScene;
}

// on "init" you need to initialize your instance
bool MapScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}
	srand(time(NULL));
	//MapScene::AnimalsArray;
	cout << "INICJUJE MAPSCENE";
	
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	Vector<MenuItem*> MenuItems;//wektor przechowuj¹cy itemy menu, z ktorego utworzymy menu pozniej
					
	//labelConfig DO NAPISOW
	TTFConfig labelConfig;
	labelConfig.fontSize = 30;
	labelConfig.outlineSize = 2;
	labelConfig.fontFilePath = "fonts/Marker Felt.ttf";
	//LABEL TYTU£OWY
	auto label = Label::createWithTTF(labelConfig, "MAPA");

	// position the label on the center of the screen
	label->setPosition(Vec2(origin.x + visibleSize.width / 2,
	origin.y + visibleSize.height - label->getContentSize().height));

	// add the label as a child to this layer
	this->addChild(label, 1);



//TWORZENIE MENU Z PRZYCISKIEM COFNIJ

	auto secondMenuItem = MenuItemImage::create("cofnij.png",
		"cofnij.png",
		CC_CALLBACK_1(MapScene::GoBack, this));
	MenuItems.pushBack(secondMenuItem);
	secondMenuItem->setPosition(Point(visibleSize.width * 4 / 5, (visibleSize.height / 5)));
	auto menu = Menu::createWithArray(MenuItems);
	menu->setPosition(Point(0, 0));
	this->addChild(menu, 1);

	//LABELE DODAJ ZWIERZE

	labelConfig.fontSize = 12;
	labelConfig.outlineSize = 0;
	labelConfig.fontFilePath = "fonts/Roboto-Thin.ttf";

	auto label1 = Label::createWithTTF(labelConfig, "Wiek:");
	label1->setAnchorPoint(Vec2(0.0, 0.0));
	label1->setPosition(Vec2(visibleSize.width *7.8 / 10, visibleSize.height * 9.6 / 10));
	this->addChild(label1);

	auto label3 = Label::createWithTTF(labelConfig, "Gatunek:");
	label3->setAnchorPoint(Vec2(0.0, 0.0));
	label3->setPosition(0, -(0.6)*label3->getLineHeight());
	label1->addChild(label3);
	auto label4 = Label::createWithTTF(labelConfig, "Plec:");
	//
	label4->setAnchorPoint(Vec2(0.0, 0.0));
	label4->setPosition(0, -(0.6)*label4->getLineHeight());
	label3->addChild(label4);
	auto label5 = Label::createWithTTF(labelConfig, "Poz X:");
	//
	label5->setAnchorPoint(Vec2(0.0, 0.0));
	label5->setPosition(0, -(0.6)*label5->getLineHeight());
	label4->addChild(label5);
	auto label6 = Label::createWithTTF(labelConfig, "Poz Y");
	//
	label6->setAnchorPoint(Vec2(0.0, 0.0));
	label6->setPosition(0, -(0.6)*label6->getLineHeight());
	label5->addChild(label6);

	auto label7 = Label::createWithTTF(labelConfig, "Usun po ID:");
	label7->setAnchorPoint(Vec2(0.0, 0.0));
	label7->setPosition(Vec2(visibleSize.width *1 / 20, visibleSize.height * 9 / 10));
	this->addChild(label7);

//KONIEC STREFY LABELI DODAJ ZWIERZE



//TEXT FIELDY DO OBS£UGI DODAWANIE ZWIERZAT DO LISTY

	//TEXT FIELD DO WPROWADZENIA WIEKU
	TextField *txtField3 = ui::TextField::create("wiek", "fonts/fabrik.ttf", 12);////////////WIEK AGE
	txtField3->setMaxLength(3);//////////////////////////////////////////////////////////////////////
	txtField3->setMaxLengthEnabled(true);///////////////////////////////////////////////DOESN'T DO ANYTHING, NOT GETTING ANY DATA
	txtField3->setAnchorPoint(Vec2(0.0, 0.0));////////////////////////////////////////////////////////
	txtField3->setPosition(Vec2(visibleSize.width *0.89, visibleSize.height * 9.65/ 10));////////////////////////////////////////////////////////////
	this->addChild(txtField3);
	txtField3->addEventListener(CC_CALLBACK_2(MapScene::textFieldEvent3, this));
	txtField3->setColor(ccc3(127.0f, 255.0f, 0.0f));//c333 = kolory RGB od 0-255;


	//TEXT FIELD DO WPROWADZENIA GATUNKU									
	TextField *txtField4 = ui::TextField::create("gatunek", "fonts/fabrik.ttf", 12);////////////
	txtField4->setMaxLength(1);//////////////////////////////////////////////////////////////////////
	txtField4->setMaxLengthEnabled(true);///////////////////////////////////////////////DOESN'T DO ANYTHING, NOT GETTING ANY DATA
	txtField4->setAnchorPoint(Vec2(0.0, 0.0));////////////////////////////////////////////////////////
	txtField4->setPosition(Vec2(0, -(0.6)*label1->getLineHeight()));////////////////////////////////////////////////////////////
	txtField3->addChild(txtField4);
	txtField4->addEventListener(CC_CALLBACK_2(MapScene::textFieldEvent4, this));
	txtField4->setColor(ccc3(127.0f, 255.0f, 0.0f));//c333 = kolory RGB od 0-255;

	//TEXT FIELD DO WPROWADZENIA P£CI
	TextField *txtField5 = ui::TextField::create("plec", "fonts/fabrik.ttf", 12);////////////
	txtField5->setMaxLength(1);//////////////////////////////////////////////////////////////////////
	txtField5->setMaxLengthEnabled(true);///////////////////////////////////////////////DOESN'T DO ANYTHING, NOT GETTING ANY DATA
	txtField5->setAnchorPoint(Vec2(0.0, 0.0));////////////////////////////////////////////////////////
	txtField5->setPosition(Vec2(0, -(0.6)*label1->getLineHeight()));////////////////////////////////////////////////////////////
	txtField5->addEventListener(CC_CALLBACK_2(MapScene::textFieldEvent5, this));
	txtField5->setColor(ccc3(127.0f, 255.0f, 0.0f));//c333 = kolory RGB od 0-255;
	txtField4->addChild(txtField5);
	
	//TEXT FIELD DO WPROWADZENIA POZYCJI X ZWIERZECIA NA MAPIE
	TextField *txtField6 = ui::TextField::create("poz X", "fonts/fabrik.ttf", 12);////////////
	txtField6->setMaxLength(2);//////////////////////////////////////////////////////////////////////
	txtField6->setMaxLengthEnabled(true);///////////////////////////////////////////////DOESN'T DO ANYTHING, NOT GETTING ANY DATA
	txtField6->setAnchorPoint(Vec2(0.0, 0.0));////////////////////////////////////////////////////////
	txtField6->setPosition(Vec2(0, -(0.6)*label1->getLineHeight()));////////////////////////////////////////////////////////////
	txtField6->addEventListener(CC_CALLBACK_2(MapScene::textFieldEvent6, this));
	txtField6->setColor(ccc3(127.0f, 255.0f, 0.0f));//c333 = kolory RGB od 0-255;
	txtField5->addChild(txtField6);

	//TEXT FIELD DO WPROWADZENIA POZYCJI X ZWIERZECIA NA MAPIE
	TextField *txtField7 = ui::TextField::create("poz Y", "fonts/fabrik.ttf", 12);////////////
	txtField7->setMaxLength(2);//////////////////////////////////////////////////////////////////////
	txtField7->setMaxLengthEnabled(true);///////////////////////////////////////////////DOESN'T DO ANYTHING, NOT GETTING ANY DATA
	txtField7->setAnchorPoint(Vec2(0.0, 0.0));////////////////////////////////////////////////////////
	txtField7->setPosition(Vec2(0, -(0.6)*label1->getLineHeight()));////////////////////////////////////////////////////////////
	txtField7->addEventListener(CC_CALLBACK_2(MapScene::textFieldEvent7, this));
	txtField7->setColor(ccc3(127.0f, 255.0f, 0.0f));//c333 = kolory RGB od 0-255;
	txtField6->addChild(txtField7);

	//TEXT FIELD DO WPROWADZENIA ID ZWIERZECIA KTORE CHCEMY USUNAC
	TextField *txtField8 = ui::TextField::create("podaj ID", "fonts/fabrik.ttf", 12);////////////
	txtField8->setMaxLength(6);//////////////////////////////////////////////////////////////////////
	txtField8->setMaxLengthEnabled(true);///////////////////////////////////////////////DOESN'T DO ANYTHING, NOT GETTING ANY DATA
	txtField8->setAnchorPoint(Vec2(0.0, 0.0));////////////////////////////////////////////////////////
	txtField8->setPosition(Vec2(visibleSize.width *0.5 / 10, visibleSize.height * 8.5 / 10));////////////////////////////////////////////////////////////
	txtField8->addEventListener(CC_CALLBACK_2(MapScene::textFieldEvent8, this));
	txtField8->setColor(ccc3(127.0f, 255.0f, 0.0f));//c333 = kolory RGB od 0-255;
	this->addChild(txtField8);

//KONIEC STREFY TEXTFIELDÓW


//WYSWIETLA I AKTUALIZUJE LISTE ZWIERZAT ZNAJDUJACYCH SIE AKTUALNIE NA MAPIE
	label8 = Label::createWithTTF(" ", "fonts/CaviarDreams.ttf", 8);//tworze napis do wyswietlania listy zwierzat
	label8->setPosition(Vec2(visibleSize.width / 8, visibleSize.height * 5 / 10));
	this->addChild(label8, 25);
	animalList = " ";
	this->schedule(schedule_selector(MapScene::TimerMethod), 1);

	
//STREFA PRZYCISKÓW								  
//przycisk zatwierdzajacy dodanie zwierzecia
	ui::Button *ourButton = Button::create("dodajzwierze.png");
	ourButton->setPosition(Vec2(-visibleSize.width /50,
		-visibleSize.height / 20));
	ourButton->addTouchEventListener(CC_CALLBACK_2(MapScene::touchEvent, this));
	txtField7->addChild(ourButton, 2);
//przycisk zatwierdzajacy dodanie roslin na mapie
	ui::Button *ourButton1 = Button::create("dodajflore.png");
	ourButton1->setPosition(Vec2(visibleSize.width/10,
		visibleSize.height / 5));
	ourButton1->addTouchEventListener(CC_CALLBACK_2(MapScene::touchEvent1, this));
	this->addChild(ourButton1,20);
//przycisk zatwierdzajacy dodanie wody na mapie
	ui::Button *ourButton2 = Button::create("dodajwode.png");
	ourButton2->setPosition(Vec2(visibleSize.width /10*3,
		visibleSize.height / 5));
	ourButton2->addTouchEventListener(CC_CALLBACK_2(MapScene::touchEvent2, this));
	this->addChild(ourButton2,20);
//przycisk zatwierdzajacy dodanie zwierzecia LOSOWO na mapie
	ui::Button *ourButton3 = Button::create("dodajzwierzelosowo.png");
	ourButton3->setPosition(Vec2(visibleSize.width / 10 *5.6,
		visibleSize.height / 5));
	ourButton3->addTouchEventListener(CC_CALLBACK_2(MapScene::touchEvent3, this));
	this->addChild(ourButton3, 20);
//przycisk zatwierdzajacy USUNIECIE ZWIERZAKA PO ID
	ui::Button *ourButton4 = Button::create("usun.png");
	ourButton4->setPosition(Vec2(visibleSize.width / 10 *1.5,
		visibleSize.height / 5* 4));
	ourButton4->addTouchEventListener(CC_CALLBACK_2(MapScene::touchEvent4, this));
	this->addChild(ourButton4, 20);
//przycisk zatwierdzajacy ZAKONCZENIE SYMULACJI I PRZEJSCIE DO STATYSTYK
	ui::Button *ourButton5 = Button::create("zakoncz.png");
	ourButton5->setPosition(Vec2(visibleSize.width / 10 * 8.5,
		visibleSize.height / 5 *1.5));
	ourButton5->addTouchEventListener(CC_CALLBACK_2(MapScene::touchEvent5, this));
	this->addChild(ourButton5, 20);
//KONIEC STREFY PRZYCISKÓW

//UTWORZENIE MAPY FIXED SIZE 60X40 W POSTACI DWUWYMIAROWEJ DYNAMICZNEJ TABLICY WSKAZNIKOW CTile




	for (int i = 0; i< 60; i++)
	{
		for (int j = 0; j< 40; j++)
		{
			CTile a(i,j);
			spriteArray[i][j] = a;
			spriteArray[i][j].mapTile->setAnchorPoint(Vec2(0,0));
			spriteArray[i][j].mapTile->setPosition(Point((120 + 4 * i), (75 + 4 * j)));
			addChild(spriteArray[i][j].mapTile, 10);

		}

	}
	animals.clear();
//ODSWIEZANIE FUNKCJI STERUJACEJ ZYCIEM NA MAPIE CO 0.33S (UpdateFuntion)
	this->schedule(schedule_selector(MapScene::UptadeFunction), 0.33);

	return true;




}

//FUNKCJA WYSWIETLAJACA LISTE ZWIERZAT
void MapScene::TimerMethod(float dt) 
{
	animalList = "";
	animalList.append("Lista zwierzat: \n");
	int i = 0;
	for (list<CAnimal*>::iterator it = animals.begin(); it != animals.end(); ++it)
	{//ITERACJA PO WSZYSTKICH ZWIERZÊTACH
		
		animalList+= std::to_string((*it)->getID());
		animalList.append(" HP:");
		animalList += std::to_string((*it)->getHealth());
		animalList.append(" P:");
		animalList += std::to_string((*it)->getFertility());
		animalList.append(" W:");
		animalList += std::to_string((*it)->getAge());

		switch ((*it)->getMale())
		{
		case true:
		{animalList.append(" M"); }break;
		default:
		{animalList.append(" F"); }break;
		}
		animalList.append("\n");
	}
	label8->setString(animalList);
	
}
//FUNKCJA STERUJACA ZYCIEM NA MAPIE
void MapScene::UptadeFunction(float dt)
{
	srand(time(NULL));
	CStats::setSimulationTime(CStats::getSimulationTime() + 1);//ZLICZANIE CZASU SYMULACJI
	//PÊTLA PO LISCIE ZWIERZAT
		for (list<CAnimal*>::iterator it = animals.begin(); it != animals.end(); ++it)
		{
			(*it)->Logic();
			(*it)->PhysicalNeeds();
		}
		list<CAnimal*>::iterator it = animals.begin();
			while(it != animals.end())
		{
			if ((*it)->getAge() >= 1000 || (*it)->getHealth() <= 0)
			{
				(*it)->Die();
				delete(*it);
				it = animals.erase(it);

			}
			else it++;
		}
			Reproduce();
		
	}

//POWROT DO HELLOWORLDSCENE
void MapScene::GoBack(Ref *pSender) {
	Clean();
	auto scene = HelloWorld::createScene();
	Director::getInstance()->replaceScene(scene);


}
//TEXTFIELDY EVENTY:
//1.WIEK
void MapScene::textFieldEvent3(Ref *sender, ui::TextField::EventType type)//WIEK
{
	ui::TextField *textField = dynamic_cast<ui::TextField *>(sender);
	switch (type)
	{
	case ui::TextField::EventType::DETACH_WITH_IME:
	{log("Text stopped, Zapisano rozmiar mapy");
	std::string str = textField->getString().c_str();
	if(!str.empty())
	age = (stoi(str));
	cout << str << " " << age;
	}
	break;
	default:
		break;
	}
}
//2.GATUNEK
void MapScene::textFieldEvent4(Ref *sender, ui::TextField::EventType type)
{
	ui::TextField *textField = dynamic_cast<ui::TextField *>(sender);
	switch (type)
	{
	case ui::TextField::EventType::DETACH_WITH_IME:
	{log("Text stopped, Zapisano rozmiar mapy");
	std::string str = textField->getString().c_str();
	int a = (stoi(str));//pobieram nr gatunku ktory uzytkownik widzi na liscie o prawo
	switch (a) {/////////////////////////////////////////GATUNEK
	case 1:

		break;
	case 2:

		break;
	case 3:

		break;
	case 4:

		break;
	case 5:

		break;

	}


	}
	break;
	default:
		break;
	}
}
//3.PLEC
void MapScene::textFieldEvent5(Ref *sender, ui::TextField::EventType type)
{
	ui::TextField *textField = dynamic_cast<ui::TextField *>(sender);
	switch (type)
	{
	case ui::TextField::EventType::DETACH_WITH_IME:
	{log("Text stopped, Zapisano rozmiar mapy");
	std::string str = textField->getString().c_str();
	int a = (stoi(str));
	switch (a)
	{
	case 1:
		male = true;
		break;
	default:
		male = false;
		break;
	}

	}
	}
}
//4.POSX
void MapScene::textFieldEvent6(Ref *sender, ui::TextField::EventType type)
{
	ui::TextField *textField = dynamic_cast<ui::TextField *>(sender);
	switch (type)
	{
	case ui::TextField::EventType::DETACH_WITH_IME:
	{
		std::string str = textField->getString().c_str();

		posx = (stoi(str));

		cout << posx << endl;
	}
	break;
	default:
		break;
	}
}
//5.POSY
void MapScene::textFieldEvent7(Ref *sender, ui::TextField::EventType type)
{
	ui::TextField *textField = dynamic_cast<ui::TextField *>(sender);
	switch (type)
	{
	case ui::TextField::EventType::DETACH_WITH_IME:
	{
	std::string str = textField->getString().c_str();
	posy = (stoi(str));
	cout << posy << " ";
	}
	break;
	default:
		break;
	}
}
//6.ID DO USUNIECIA
void MapScene::textFieldEvent8(Ref *sender, ui::TextField::EventType type)
{
	ui::TextField *textField = dynamic_cast<ui::TextField *>(sender);
	switch (type)
	{
	case ui::TextField::EventType::DETACH_WITH_IME:
	{
	std::string str = textField->getString().c_str();
	IDdelete = (stoi(str));
	cout << posy << " ";
	}
	break;
	default:
		break;
	}
}
//KONIEC TEXTFIELD EVENTOW
//TOUCH EVENTY DO BUTTONOW
//1.DODAJ ZWIERZE
void MapScene::touchEvent(Ref *sender, Widget::TouchEventType type)
{


	switch (type)
	{
	case ui::Widget::TouchEventType::BEGAN:
	{

		
		
	}break;
	case ui::Widget::TouchEventType::MOVED:
	{
		log("Touch moved");

	}break;
	case ui::Widget::TouchEventType::ENDED:
	{

		/*MapScene::AddAnimal(male, age, posx, posy, n);
		animals.back()->animalsprite->setPosition(Vec2(Point((120 + 4 * posx), (75 + 4 * posy))));
		addChild(animals.back()->animalsprite, 13);*/
	}break;
	case ui::Widget::TouchEventType::CANCELED:
	{
		log("Touch canceled");
	}break;
	default:
		break;
	}
}
//2.DODAJ FLORE
void MapScene::touchEvent1(Ref *sender, Widget::TouchEventType type)
{


	switch (type)
	{
	case ui::Widget::TouchEventType::BEGAN:
	{


	}break;
	case ui::Widget::TouchEventType::MOVED:
	{
		log("Touch moved");

	}break;
	case ui::Widget::TouchEventType::ENDED:
	{
		MapScene::AddRandomTree();

	}break;
	case ui::Widget::TouchEventType::CANCELED:
	{
		log("Touch canceled");
	}break;
	default:
		break;
	}
}
//3.DODAJ WODE
void MapScene::touchEvent2(Ref *sender, Widget::TouchEventType type)
{


	switch (type)
	{
	case ui::Widget::TouchEventType::BEGAN:
	{


	}break;
	case ui::Widget::TouchEventType::MOVED:
	{
		log("Touch moved");

	}break;
	case ui::Widget::TouchEventType::ENDED:
	{
		MapScene::AddRandomWater();

	}break;
	case ui::Widget::TouchEventType::CANCELED:
	{
		log("Touch canceled");
	}break;
	default:
		break;
	}
}
//4.DODAJ ZWIERZE LOSOWO
void MapScene::touchEvent3(Ref *sender, Widget::TouchEventType type)
{


	switch (type)
	{
	case ui::Widget::TouchEventType::BEGAN:
	{


	}break;
	case ui::Widget::TouchEventType::MOVED:
	{
		log("Touch moved");

	}break;
	case ui::Widget::TouchEventType::ENDED:
	{
		AddRandomAnimal();
		cout << "Touch ended" << endl;
		animals.back()->animalsprite->setPosition(Vec2(cocos2d::Point((120 + 4 * (animals.back()->getPosX())), (75 + 4 * (animals.back()->getPosY())))));
		addChild(animals.back()->animalsprite, 13);
		

	}break;
	case ui::Widget::TouchEventType::CANCELED:
	{
		log("Touch canceled");
	}break;
	default:
		break;
	}
}
//5.USUN ZWIERZE PO ID
void MapScene::touchEvent4(Ref *sender, Widget::TouchEventType type)
{
	switch (type)
	{
	case ui::Widget::TouchEventType::BEGAN:
	{


	}break;
	case ui::Widget::TouchEventType::MOVED:
	{
		log("Touch moved");

	}break;
	case ui::Widget::TouchEventType::ENDED:
	{
		DeleteID(IDdelete);

	}break;
	case ui::Widget::TouchEventType::CANCELED:
	{
		log("Touch canceled");
	}break;
	default:
		break;
	}
}
//6.ZAKONCZ
void MapScene::touchEvent5(Ref *sender, Widget::TouchEventType type)
{
	switch (type)
	{
	case ui::Widget::TouchEventType::BEGAN:
	{


	}break;
	case ui::Widget::TouchEventType::MOVED:
	{
		log("Touch moved");

	}break;
	case ui::Widget::TouchEventType::ENDED:
	{
		Clean();
		auto scene = EndGameScene::createScene();
		Director::getInstance()->replaceScene(scene);

	}break;
	case ui::Widget::TouchEventType::CANCELED:
	{
		log("Touch canceled");
	}break;
	default:
		break;
	}
}
//KONIEC TOUCH EVENTÓW
//FUNKCJE:
//DODAJ ZWIERZE
void MapScene::AddAnimal(bool male, int age, int posX, int posY, int a)
{
	CAnimal* ben;
	try {
		switch (a)
		{
		case 1: ben = new CHippo; break;
		case 2: ben = new CCrocodile; break;
		case 3: ben = new CLion; break;
		case 4: ben = new CGiraffe; break;
		case 5: ben = new CVulture; break;
		}
		if (ben == nullptr) throw 1;
	}
	catch (int) {
		cout << "blad tworzenia zwierzcia" << endl;
	}
	catch (...)
	{
		cout << "blad krytyczny" << endl;
	}
	ben->setAge(age);//DOPISZ ZABEZPIECZENIA
	ben->setPosX(posX);
	ben->setPosY(posY);
	ben->setMale(male);
	animals.push_back(ben);
	CStats::setNumberOfAnimals(CStats::getNumberOfAnimals() + 1);
	ben->animalsprite->setPosition(Vec2(Point((120 + 4 * posx), (75 + 4 * posy))));
	//addChild(beniz->animalsprite, 13);
	ben->animalsprite->setAnchorPoint(Vec2(0.5, 0.5));
}
//DODAJ ZWIERZE LOSOWO
void MapScene::AddRandomAnimal()
{
		

		bool b;
		int random = rand() % 2;
		if (random ==1)
			b = true;
		else b = false;
		bool male = b;////////////////////////////////////LOSOWANIE DANYCH POTRZEBNYCH DLA KONSTRUKTORA CAnimal;
		int age = rand() % 99;;///////////////////////////////WIEK
		int a = rand() % 5 + 1;
		int posX = rand() % 10 +9*a;////////////POZYCJA X
		int posY = rand() % 6 + 6*a;////////////POZYCJA Y
		
		AddAnimal(b, age, posX, posY, a);
		
}
//DODAJ LOSOWO WODE NA MAPIE
void MapScene::AddRandomWater()
{
	

	for (int i = 0; i < 25; i++)
	{
		
		int a = rand() % 2400;
		spriteArray[a/40][a%40].setIsWater();
		spriteArray[a/40][a%40].mapTile->setTexture("water.png");

	}


}
//DODAJ LOSOWO ROSLINNOSC NAMAPIE
void MapScene::AddRandomTree()
{

	
	for (int i = 0; i <25; i++)
	{
		int a = rand() % 2400;
		spriteArray[a / 40][a % 40].setIsFlora();
		spriteArray[a / 40][a % 40].mapTile->setTexture("tree.png");

	}

}
//USUN PO ID
void MapScene::DeleteID(int id)

{

	for (list<CAnimal*>::iterator it = animals.begin(); it != animals.end(); it++)
	{
		if ((*it)->getID() == id)
		{
			((*it)->animalsprite)->removeFromParentAndCleanup(true);
			delete (*it);
			animals.erase(it);
			return;
		}
	}
	cout << "Nie ma takiego zwierza, lul" << endl;
}

//KASOWANIE TABLICY Z CTileami oraz LISTY ZWIERZAT
void MapScene::Clean()
{
	for (int i = 0; i < 60; i++)
		for (int j = 0; j < 40; j++)
		{
			spriteArray[i][j].mapTile->removeFromParentAndCleanup(true);
		
		}

	for (list<CAnimal*>::iterator it1 = animals.begin(); it1 != animals.end(); ++it1)
	{
		(*it1)->animalsprite->removeFromParentAndCleanup(true);
	}
	animals.clear();
	

}

void MapScene::Reproduce()
{
for (list<CAnimal*>::iterator it = animals.begin(); it != animals.end(); ++it)
{
if((*it)->getOnTheWay() == true)//JESLI ZWIERZE JEST GOTOWE DO ROZMNOZENIA
{//CZEKA NA REPREZENTANTA TEGO SAMEGO GATUNKU PLCI PRZECIWNEJ
for (list<CAnimal*>::iterator it1 = animals.begin(); it1 != animals.end(); ++it1)
{
if ((*it)->getPosX() == (*it1)->getPosX() && (*it1)->getOnTheWay() == true && (*it)->getMale() != (*it1)->getMale()) {
CStats::setNumberOfReproductions(CStats::getNumberOfReproductions() + 1); // +1 do rozmnozen
(*it)->AfterReproduction();
(*it1)->AfterReproduction();
//AKT ROZMNOZENIA (dodawanie nowego zwierzecia)
int a = rand() % 2;bool b;
if (a == 1) b = true; else b = false;
AddAnimal(b, 0, (*it)->getPosX(), (*it)->getPosY(), rand()%5+1);
animals.back()->animalsprite->setPosition(Vec2(Point((120 + 4 * animals.back()->getPosX()), (75 + 4 * animals.back()->getPosY()))));
addChild(animals.back()->animalsprite, 13);
break;
}
}
}
}
}


