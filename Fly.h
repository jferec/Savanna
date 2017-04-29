#pragma once
#include"Animal.h"
class CFly : virtual public CAnimal
{
public:
	void Checkposition(int x, int y);
	CFly();
	virtual ~CFly();
};

