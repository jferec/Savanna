#pragma once
#include"Animal.h"

#include "MapScene.h"
using namespace std;

class CCarnivore : virtual public CAnimal
{
public:

	void CCarnivore::Move();
	CCarnivore();
	virtual ~CCarnivore();
};



