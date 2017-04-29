#pragma once
#ifndef CROCODILE_H
#define CROCODILE_H
#include "Carnivore.h"
#include "Fly.h"


class CCrocodile : public CCarnivore, public CFly
{
public:
	CCrocodile();
	virtual ~CCrocodile();
	void Logic();
};

#endif CROCODILE_H