#pragma once

#include <vector>
#include "Window.h"
#include "Threads.h"
#include "CPEOPLE.h"
#include "CVEHICLE.h"
#include "CANIMAL.h"

//extern bool IS_RUNNING;

class CGAME
{
public:
	//CGAME();
	//~CGAME();

	CPEOPLE getPeople();
	CVEHICLE* getVehicle();
	CANIMAL* getAnimal();

	void draw();
	void reset();
	void exit(thread::native_handle_type handle);

	void start();

	void load();
	void save();
	void pause(thread::native_handle_type handle);
	void resume(thread::native_handle_type handle);

	void updatePosPeople(char button);
	void updatePosVehicle();
	void updatePosAnimal();

private:
	vector<CTruck> tObj;
	vector<CCar> cObj;
	vector<CDino> dObj;
	vector<CBird> bObj;
	CPEOPLE p;
};