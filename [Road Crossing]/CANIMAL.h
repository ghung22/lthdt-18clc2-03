#pragma once

#include "COBJECT.h"

class CANIMAL : public COBJECT
{
public:
	CANIMAL();
	CANIMAL(int y, int spd);
	virtual void speak();

	bool inContact(Point ppos);
};
class CBird : public CANIMAL
{
public:
	CBird();
	void speak();
};
class CDino : public CANIMAL
{
public:
	CDino();
	void speak();
};