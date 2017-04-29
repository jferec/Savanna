#include "Water.h"
#include "MapScene.h"
void CWater::Checkposition(int x, int y) {
	if (MapScene::spriteArray[x][y].getIsWater())
	{//nie rob nic 
	}
	else {
		int a = 0, b = 0;
		if (MapScene::spriteArray[x][y].getIsWater()== false)//jesli nie wyladuje na wodzie
		{
			for (int i = -1; i < 2; i++) {
				for (int j = -1; j < 2; j++) {
					if (MapScene::spriteArray[getPosX() + i][getPosY() + j].getIsWater())
						a = i; b = j; break;
				}
			}
			setPosX(getPosX() + a);
			setPosY(getPosY() + b);
			auto action = MoveBy::create(0.3, Point(Vec2(4 * a, 4 * b)));
			animalsprite->runAction(action);
		}
	}
}

CWater::CWater()
{
}


CWater::~CWater()
{
	cout << " Usuwam plywajace" << endl;
}
