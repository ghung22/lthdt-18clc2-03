#pragma once

#include "COBJECT.h"

class CVEHICLE : public COBJECT
{
public:
	CVEHICLE(int y, int spd);
};
class CTruck : public CVEHICLE
{
public:
	CTruck();
	CTruck(int x);
};
class CCar : public CVEHICLE
{
public:
	CCar();
	CCar(int x);
}
