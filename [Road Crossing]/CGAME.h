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
	void reset(bool loss = true, thread* t = nullptr);
	void exit(thread& t);
	void lose(int dialog);

	//Các hàm menu
	void start();
	void game(bool load = false);
	void setting();
	void prompt(int dialog);

	//Các hàm liên quan đến file trong game screen
	void settingLoad();
	void settingSave();
	void load(string f);
	void save(string f);
	void pause();
	void resume();

	//Các hàm update trong game screen
	void ClearInfoBox();
	void UpdateGameInfo(); //in thông tin
	void MoveObjects(long timer); //timer: biến đếm trong vòng lặp của thread

	//Hàm để trong thread
	friend bool CheckCollision(CGAME* g); //kiểm va chạm
	friend void UpdateGameFrame(CGAME* g);

	bool getSound();

private:
	void initObjects(bool resetP = true); //tạo objects mới
	void clearObjects(bool resetP); //dọn objects cũ

	vector<CTruck> truck;
	vector<CCar> car;
	vector<CBird> bird;
	vector<CDino> dino;
	CPEOPLE p;
	vector<CLIGHT> light;

	bool sound;
};