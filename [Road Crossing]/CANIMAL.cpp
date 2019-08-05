#include "CANIMAL.h"

CANIMAL::CANIMAL(int y, int spd) {pos.Y = y; speed = spd; }
CBird::CBird() : CANIMAL(BIRD_Y, BIRD_SPD)
{
	type = "bird";
	avatar = BIRD_AVA;
	voice = "Bird.wav";
}
CBird::CBird(int x) : CBird() { pos.X = x; }
CDino::CDino(): CANIMAL(DINO_Y, DINO_SPD)
{
	type = "dino";
	avatar = DINO_AVA;
	voice = "Dino.wav";
}
CDino::CDino(int x) : CDino() { pos.X = x; }