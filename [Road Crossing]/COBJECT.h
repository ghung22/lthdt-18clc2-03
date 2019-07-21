#pragma once

#include <vector>
#include <iostream>
using namespace std;

#include "Window.h"
#include "Constants.h"

class COBJECT
{
public:
	COBJECT();

	void draw(Point p);
	void erase(Point p);

protected:
	Point pos;
	int speed;				//Giá trị càng nhỏ, khoảng cách giữa step vẽ càng ngắn → Di chuyển càng nhanh
	vector<string> avatar;	//Chứa ngoại hình của các vật (có 3 dòng)
};