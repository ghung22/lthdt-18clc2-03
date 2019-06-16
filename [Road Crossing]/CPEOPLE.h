#pragma once

#include "CGAME.h"

class CPEOPLE
{
public:
	CPEOPLE();

	void Move(char button); //Call 4 direction functions below
	void up();
	void left();
	void right();
	void down();

	bool inContact(const CVEHICLE*&);
	bool inContact(const CANIMAL*&);

	bool isFinish();
	bool isDead();

private:
	char icon; //Assigned to PLAYER_SYMBOL in contructor, change in setting menu
	int x, y;
	bool alive;
};