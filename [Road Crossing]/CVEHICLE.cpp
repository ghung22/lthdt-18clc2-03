#include "CVEHICLE.h"

CVEHICLE::CVEHICLE() { pos.X = pos.Y = speed = 0; }
CVEHICLE::CVEHICLE(int y, int spd) { pos.Y = y; speed = spd; }
CTruck::CTruck() : CVEHICLE(TRUCK_Y, TRUCK_SPD)
{
	avatar[0] = { char(218), char(196), char(196), char(191) };			//┌──┐
	avatar[1] = { char(179), ' ', char(219), char(219), char(219) };	//│ ███
	avatar[2] = { 'O', char(196), char(196), 'O' };						//O──O
}
CCar::CCar() : CVEHICLE(CAR_Y, CAR_SPD)
{
	avatar[1] = { char(218), char(196), char(191) };	//┌─┐
	avatar[2] = { 'O', char(223), char(223), 'o' };		//O▀▀o
}

bool CVEHICLE::inContact(Point ppos)
{
	return pos.X <= ppos.X && ppos.X <= pos.X + 2
		&& pos.Y == ppos.Y;
	//Việc xét điểm y còn tuỳ vào kích cỡ của vehicle
}

void CCar::horn()
{
	PlaySound("C:\\Users\\ACER\\Documents\\GitHub\\lthdt-18clc2-03\\[Road Crossing]\\sound\\Car.wav", NULL, SND_SYNC);
}

void CTruck::horn()
{
	PlaySound("C:\\Users\\ACER\\Documents\\GitHub\\lthdt-18clc2-03\\[Road Crossing]\\sound\\Truck.wav", NULL, SND_SYNC);
}