#include "CANIMAL.h"

CANIMAL::CANIMAL(int y, int spd) {pos.Y = y; speed = spd; }
CBird::CBird() : CANIMAL(BIRD_Y, BIRD_SPD)
{
	avatar[0] = { char(169), char(250), char(170) };	//⌐·¬	-·-
	voice += "Bird.wav";
}
CBird::CBird(int x) : CBird() { pos.X = x; }
CDino::CDino(): CANIMAL(DINO_Y, DINO_SPD)
{
	avatar[0] = { ' ', char(244) };			// ⌠
	avatar[1] = "(0)";						//(0)
	avatar[2] = { char(217), 'L', 'L' };	//┘LL
	voice += "Dino.wav";
}
CDino::CDino(int x) : CDino() { pos.X = x; }