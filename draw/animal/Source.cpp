﻿#include "CANIMAL.h"
#include <Windows.h>
#include <mmsystem.h>

#include "COBJECT.h"
#include "CGAME.h"

Window wd;

COBJECT::COBJECT()
{
	type = "object";
	pos = { 0, 0 };
	speed = 1;
	for (int i = 0; i < 3; i++)
		avatar.push_back("");
	voice = "Data\\Sounds\\";
}

void COBJECT::draw(Point p)
{
	flip();
	if (p.X == -1 && p.Y == -1)
		p = pos;

	p.Y = (10 - p.Y) * 5 + 2;
	wd.GotoXY(p.X, p.Y - 1);
	cout << "           "; //Xoá ký tự dư trên đầu khi wrap sang phía bên kia
	for (int i = 0; i < 3; i++)
	{
		wd.GotoXY(p.X, p.Y + i);
		cout << avatar[i];
	}
}
void COBJECT::erase(Point p)
{
	if (p.X == -1 && p.Y == -1)
		p = pos;

	p.Y = (10 - p.Y) * 5 + 2;
	for (int i = 0; i < 3; i++)
	{
		wd.GotoXY(p.X - 4, p.Y + i);
		cout << "          ";
	}
}

void COBJECT::moveXY(short x, short y, long timer)
{
	if (timer % abs(speed) != 0)
		return;

	//Di chuyển y theo làn, ko phải theo dòng kí tự trên console
	if (x != 0 || y != 0)
	{
		erase();
		pos.X += speed > 0 ? x : -x;
		pos.Y += y;
	}
	draw(pos);
}
void COBJECT::speak()
{
	static CGAME* g;
	if (g->getSound())
		PlaySound(voice.c_str(), NULL, SND_ASYNC | SND_FILENAME);
}

Point COBJECT::getPos() { return pos; }
void COBJECT::speedDirChange(int i)
{
	if (speed < 0)
		speed *= -1;
	speed *= i / abs(i);
}

void COBJECT::flip()
{
	//Nếu đang đi chiều nghịch mà avatar đang hướng chiều thuận
	if (speed < 0 && avatar == defaultAva::avatar(type))
		avatar = defaultAva::avatar(type + "_flipped");
	//Nếu đang đi chiều thuận mà avatar đang hướng chiều nghịch
	else if (speed > 0 && avatar != defaultAva::avatar(type))
		avatar = defaultAva::avatar(type);
}
CANIMAL::CANIMAL(int y, int spd) { pos.Y = y; speed = spd; }
CBird::CBird() : CANIMAL(BIRD_Y, BIRD_SPD)
{
	type = "bird";
	avatar = BIRD_AVA;
	voice += "Bird.wav";
}
CBird::CBird(int x) : CBird() { pos.X = x; }
CDino::CDino() : CANIMAL(DINO_Y, DINO_SPD)
{
	type = "dino";
	avatar = DINO_AVA;
	voice += "Dino.wav";
}
CDino::CDino(int x) : CDino() { pos.X = x; }
#include "CVEHICLE.h"

CVEHICLE::CVEHICLE(int y, int spd) { pos.Y = y; speed = spd; }
CTruck::CTruck() : CVEHICLE(TRUCK_Y, TRUCK_SPD)
{
	type = "truck";
	avatar = TRUCK_AVA;
	voice += "Truck.wav";
}
CTruck::CTruck(int x) : CTruck() { pos.X = x; }
CCar::CCar() : CVEHICLE(CAR_Y, CAR_SPD)
{
	type = "car";
	avatar = CAR_AVA;
	voice += "Car.wav";
}
CCar::CCar(int x) : CCar() { pos.X = x; }