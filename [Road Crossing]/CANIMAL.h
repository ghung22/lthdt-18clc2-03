#pragma once

#include "COBJECT.h"

class CANIMAL : public COBJECT
{
public:
	CANIMAL(int y, int spd);
	virtual void speak();

	bool inContact(Point ppos);
};
class CBird : public CANIMAL
{
public:
	CBird();
};
class CDino : public CANIMAL
{
public:
	CDino();
};