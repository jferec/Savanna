#pragma once
#include "Animal.h"

class CLand : virtual public CAnimal
{
public:
	void Checkposition(int x, int y);

	CLand();
	virtual ~CLand();
};

