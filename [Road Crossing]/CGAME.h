#pragma once

#include "CPEOPLE.h"
#include "CVEHICLE.h"
#include "CANIMAL.h"

#define PLAYER_SYMBOL 'Y';
#define MAX_LEVEL 5;
#define MAX_TRUCK 5;
#define MAX_CAR 5;
#define MAX_BIRD 5;
#define MAX_DINO 5;

class Vect2D //2D vector
{
public:
	Vect2D();

private:
	int x, y;
};

class CGAME
{
public:
	CGAME();
	void draw();
	~CGAME();

	CPEOPLE getPeople();
	CVEHICLE* getVehicle();
	CANIMAL* getAnimal();

	void reset();
	void exit();
	void start();

	void load();
	void save();
	void pause();
	void resume();

	void updatePosPeople(char button);
	void updatePosVehicle();
	void updatePosAnimal();

private:
	CTruck* tObj;
	CCar* cObj;
	CDino* dObj;
	CBird* bObj;
	CPEOPLE* p;
};