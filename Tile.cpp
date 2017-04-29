#include <iostream>
#include "Tile.h"
//Autor : Jan Ferêc Prowadz¹cy: Mgr Bart³omiej Gajewski
CTile::CTile(int x, int y)//////KONSTRUKTOR KAFELKA
{

	m_IsDesert = true;
	m_IsWater = false;
	m_IsFlora = false;
	m_PosX = x;
	m_PosY = y;
	try {
		if (x > 20) {
			mapTile = cocos2d::Sprite::create("sand.png");
			m_IsDesert = true;
			m_IsWater = false;
			m_IsFlora = false;
		}
		else {
			mapTile = cocos2d::Sprite::create("water.png");
			m_IsDesert = false;
			m_IsWater = true;
			m_IsFlora = false;
		}
	}
	catch (...) {
		std::cout << "Blad wczytywania tekstury mapy" << std::endl;
	}
}

void CTile::setIsFlora() {/////////ZAMIANA KAFELKA W ROŒLINNOŒÆ

	m_IsDesert = false;
	m_IsWater = false;
	m_IsFlora = true;
}
void CTile::setIsWater() {/////////ZAMIANA KAFELKA W WODE

	m_IsDesert = false;
	m_IsWater = true;
	m_IsFlora = false;
}
void CTile::setIsDesert() {/////////ZAMIANA KAFELKA W PUSTYNIE

	m_IsDesert = true;
	m_IsWater = false;
	m_IsFlora = false;
}

