﻿#pragma once

#include "COBJECT.h"

class CPEOPLE : public COBJECT
{
public:
	CPEOPLE();
	void setAvatar(int i);
	void reset(); //reset các biến về default

	void Move(char button); //Gọi 4 hàm hướng đi bên dưới
	void arms(); //Chuyển động tay
	void up();
	void left();
	void down();
	void right();

	bool isDead();
	void kill();

	char getIcon(int mode = 1); //0: return char, 1: return id
	int setIcon(int i);

	unsigned getLevel();
	unsigned setLevel(unsigned l);

private:
	int icon;
	bool alive;
	unsigned lv;
};