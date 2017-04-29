#pragma once

#include "Carnivore.h"
#include "Fly.h"

class CVulture : virtual public CCarnivore, virtual public CFly
{
public:
	CVulture();
	virtual ~CVulture();
	void Logic();
};

