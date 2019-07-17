#pragma once

#include "Window.h"

class CPEOPLE
{
public:
	CPEOPLE();

	//void Move(char button) { } //Gọi 4 hàm hướng đi bên dưới
	//void up() { }
	//void left() { }
	//void right() { }
	//void down() { }

	//bool inContact(CVEHICLE v);
	//bool inContact(CANIMAL a);
	//CVEHICLE nowContact(const CVEHICLE*& v); //Trả về vehicle đang va chạm với people
	//CANIMAL nowContact(const CANIMAL*& a);

	//bool isFinish() { return true; }
	bool isDead();

//private:
	char icon; //Có giá trị là PLAYER_SYMBOL (hằng số nằm trong CGAME.h và biến được gán trong contructor), có thể thay đổi lại trong mục Setting của game
	Point pos;
	bool alive;
};