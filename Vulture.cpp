#include "Vulture.h"



void CVulture::Logic()
{
	CCarnivore::Move();
	CFly::Checkposition(getPosX(), getPosY());
}

CVulture::CVulture()
{
	animalsprite = cocos2d::Sprite::create("sep.png");
	setAnimalID(5);
}


CVulture::~CVulture()
{
}
