#include "Land.h"
#include "MapScene.h"
void CLand::Checkposition(int x, int y)
{
	int a = 0, b = 0;
	if (MapScene::spriteArray[x][y].getIsWater())//jesli wyladuje na wodzie
	{
		for (int i = -1; i < 2; i++) {
			for (int j = -1; j < 2; j++) {
				if (MapScene::spriteArray[getPosX() + i][getPosY() + j].getIsWater() == false)
					a = i; b = j; break;
			}
		}
		setPosX(getPosX() + a);
		setPosY(getPosY() + b);
		auto action = MoveBy::create(0.3, Point(Vec2(4 * a, 4 * b)));
		animalsprite->runAction(action);
	}

}

CLand::CLand()
{
}


CLand::~CLand()
{
	cout << " Usuwam chodzace" << endl;
}
