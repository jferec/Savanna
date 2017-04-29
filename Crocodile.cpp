#include "Crocodile.h"



CCrocodile::CCrocodile()
{
	setAnimalID(2);
	animalsprite = cocos2d::Sprite::create("krokodyl.png");
}


CCrocodile::~CCrocodile()
{
}
void CCrocodile::Logic()
{
	CCarnivore::Move();
	CFly::Checkposition(getPosX(), getPosY());
}