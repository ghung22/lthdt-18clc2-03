#pragma once

#include "COBJECT.h"

class CVEHICLE : public COBJECT
{
public:
	CVEHICLE();
	CVEHICLE(int y, int spd);
	virtual void horn() {};
	bool inContact(Point ppos);
};
class CTruck : public CVEHICLE
{
public:
	CTruck();
	void horn();
};
class CCar : public CVEHICLE
{
public:
	CCar();
	void horn();
};

class TrafficLight
{

};