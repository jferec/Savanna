#pragma once
#include "Water.h"
#include "Herbivore.h"
class CHippo : public CHerbivore, public CWater
{
public:
	CHippo();
	virtual ~CHippo();
	void Logic();
};

