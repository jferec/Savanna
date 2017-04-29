#pragma once
#include <cmath>
#include "Animal.h"
#include "MapScene.h"

using namespace std;
using namespace ui;



class CHerbivore : virtual public CAnimal
{
public:

	void Move();

	CHerbivore();


	virtual ~CHerbivore();
};
