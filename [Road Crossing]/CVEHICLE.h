#pragma once

#include "COBJECT.h"

class CVEHICLE : public COBJECT
{
public:
	CVEHICLE(int y, int spd);

	bool inContact(Point ppos);
};
class CTruck : public CVEHICLE
{
public:
	CTruck();
};
class CCar : public CVEHICLE
{
public:
	CCar();
};