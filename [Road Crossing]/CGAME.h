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

	//Các hàm mang tính global đến game screen
	void reset(bool loss = true);
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
	void pause();
	void resume();

	//Các hàm update trong game screen
	void UpdateGameInfo(); //in thông tin

	//Hàm để trong thread
	friend void UpdateGameFrame(CGAME* g);

private:
	void initObjects(bool resetP = true); //tạo objects mới
	void clearObjects(bool resetP); //dọn objects cũ

	vector<CTruck> truck;
	vector<CCar> car;
	vector<CDino> dino;
	vector<CBird> bird;
	CPEOPLE p;

	bool sound;
};