#pragma once

#include "COBJECT.h"

class CANIMAL : public COBJECT
{
public:
	CANIMAL(int y, int spd);
};
class CBird : public CANIMAL
{
public:
	CBird();
	CBird(int x);
};
class CDino : public CANIMAL
{
public:
	CDino();
	CDino(int x);
};