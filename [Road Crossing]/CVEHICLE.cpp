#include "CVEHICLE.h"

CVEHICLE::CVEHICLE(int y, int spd) {pos.Y = y; speed = spd; }
CTruck::CTruck() : CVEHICLE(TRUCK_Y, TRUCK_SPD)
{
	avatar[0] = { char(218), char(196), char(196), char(191) };			//┌──┐
	avatar[1] = { char(179), ' ', char(219), char(219), char(219) };	//│ ███
	avatar[2] = { 'O', char(196), char(196), 'O' };						//O──O
	voice += "Truck.wav";
}
CTruck::CTruck(int x) : CTruck() { pos.X = x; }
CCar::CCar() : CVEHICLE(CAR_Y, CAR_SPD)
{
	avatar[1] = { char(218), char(196), char(191) };	//┌─┐
	avatar[2] = { 'O', char(223), char(223), 'o' };		//O▀▀o
	voice += "Car.wav";
}
CCar::CCar(int x) : CCar() { pos.X = x; }