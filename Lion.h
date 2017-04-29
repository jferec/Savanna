#pragma once

#include "Carnivore.h"
#include "Land.h"

class CLion : public CCarnivore, public CLand

{
public:
	CLion();
	virtual ~CLion();
	void Logic();
};

