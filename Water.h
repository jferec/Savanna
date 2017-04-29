#pragma once
#include "Animal.h"

class CWater : virtual public CAnimal
{
public:
	void Checkposition(int x, int y);

	CWater();
	virtual ~CWater();
	
};

