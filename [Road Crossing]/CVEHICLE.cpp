#include "CVEHICLE.h"

CVEHICLE::CVEHICLE(int y, int spd) {pos.Y = y; speed = spd; }
CTruck::CTruck() : CVEHICLE(TRUCK_Y, TRUCK_SPD)
{
	type = "truck";
	avatar = TRUCK_AVA;
	voice = "Truck.wav";
}
CTruck::CTruck(int x) : CTruck() { pos.X = x; }
CCar::CCar() : CVEHICLE(CAR_Y, CAR_SPD)
{
	type = "car";
	avatar = CAR_AVA;
	voice = "Car.wav";
}
CCar::CCar(int x) : CCar() { pos.X = x; }