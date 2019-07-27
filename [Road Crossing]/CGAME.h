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

	//Các hàm mang tính global đến game screen
	void reset();
	void exit(thread& t);

	//Các hàm menu
	void start();
	void game();
	void setting();
	void settingLoad();
	void settingSave();

	//Các hàm liên quan đến file trong game screen
	void load();
	void save();
	void pause(thread& t);
	void resume(thread& t);

	//Các hàm update trong game screen
	void UpdateGameInfo();
	void UpdatePosPeople(char button);
	void UpdatePosVehicle();
	void UpdatePosAnimal();

	//Hàm để trong thread
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