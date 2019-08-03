#pragma once
#include "Header.h"

class Obstacle {
	int X;
	int Y;
public:
	Obstacle() { X = 0; Y = 0; };
	Obstacle(int x, int y) {
		X = x;
		Y = y;
	}
	Obstacle& operator =(const Obstacle& p) {
		X = p.X;
		Y = p.Y;
		return *this;
	}
	virtual void UpdatePositionLevel0(const int& forward) {
		X += forward;
		if (forward > 0) {
			if (X > boardWidth - 4)
			{
				X = 4;
			}

		}
		else if (X <= 5)
			X = boardWidth - 4;
	}
	Obstacle(const Obstacle& p) {
		X = p.X;
		Y = p.Y;
	}
	virtual void Draw() = 0;
	int& getX() {
		return X;
	}
	int& getY() {
		return Y;
	}
	virtual void clearSelf() = 0;

};