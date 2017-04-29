#include "Hippo.h"



void CHippo::Logic()
{
	CHerbivore::Move();
	CWater::Checkposition(getPosX(), getPosY());
}

CHippo::CHippo()
{
	setAnimalID(1);
try {
		animalsprite = cocos2d::Sprite::create("hippo.png");
	}
	catch (...) {
		log("Blad wczytywania tekstury zwierza");
	}
}


CHippo::~CHippo()
{
}
