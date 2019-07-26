#pragma once

#include "Threads.h"
#include "CPEOPLE.h"
#include "CVEHICLE.h"
#include "CANIMAL.h"

//extern bool IS_RUNNING;

class CGAME
{
public:
	CGAME();
	//~CGAME();

	void draw();
	void reset();
	void exit(thread& t);

	void start();
	void game();
	void setting();
	void settingLoad();
	void settingSave();

	void load();
	void save();
	void pause(thread& t);
	void resume(thread& t);

	void updatePosPeople(char button);
	void updatePosVehicle();
	void updatePosAnimal();

	friend void UpdateGameFrame(CGAME* g);

private:
	vector<CTruck> truck;
	vector<CCar> car;
	vector<CDino> dino;
	vector<CBird> bird;
	CPEOPLE p;

	bool music;
	bool sound;
};