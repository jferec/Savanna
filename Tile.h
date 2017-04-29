//Autor : Jan Ferêc Prowadz¹cy: Mgr Bart³omiej Gajewski
#ifndef TILE_H
#define TILE_H

#include "cocos2d.h"
#include "ui\CocosGUI.h"

USING_NS_CC;

using namespace ui;

class CTile//////////////////KAFELEK MAPY
{
private://///////////////POLA KLASY:
	int m_PosX;//////////POZYCJA X
	int m_PosY;//////////POZYCJA Y
	bool m_IsDesert;/////CZY PUSTYNIA?
	bool m_IsWater;//////CZY WODA?
	bool m_IsFlora;//////CZY ROŒLINA

public:

	Sprite * mapTile;
	CTile() {};
	CTile(int posX, int posY);
	~CTile() {};
	int getPosX() { return m_PosX; };/////////////////
	int getPosY() { return m_PosY; };/////////////////
	bool getIsDesert() { return m_IsDesert; };////////GETTERY
	bool getIsWater() { return m_IsWater; };//////////
	bool getIsFlora() { return m_IsFlora; };//////////
	void setIsFlora();/////////////////////////////FUNKCJA ZAMIENIAJ¥CA OBIEKT CTile W ROŒLINNOŒÆ
	void setIsDesert();////////////////////////////FUNKCJA ZAMIENIAJ¥CA OBIEKT CTile W PUSTYNIE
	void setIsWater();/////////////////////////////FUNKCJA ZAMIENIAJ¥CA OBIEKT CTile W WODE
	
};
#endif
