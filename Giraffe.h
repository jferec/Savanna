
#pragma once
#include <iostream>
#include "Herbivore.h"
#include "Land.h"

class CGiraffe : public CHerbivore, public CLand
{
public:
	CGiraffe();
	virtual ~CGiraffe();
	void Logic();
};

