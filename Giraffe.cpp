#include "Giraffe.h"





CGiraffe::CGiraffe()
{
	setAnimalID(3);
	try {
		animalsprite = cocos2d::Sprite::create("zyrafas.png");
	}
	catch (...) {
		log("Blad wczytywania tekstury zwierza");
	}
}


CGiraffe::~CGiraffe()
{
}
void CGiraffe::Logic()
{
CHerbivore::Move();
CLand::Checkposition(getPosX(), getPosY());
}