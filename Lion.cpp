#include "Lion.h"

void CLion::Logic()
{
	CCarnivore::Move();
	CLand::Checkposition(getPosX(), getPosY());
}


CLion::CLion()
{
	animalsprite = cocos2d::Sprite::create("lew.png");
	setAnimalID(4);
}


CLion::~CLion()
{
}
