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

	void draw(Point p = { -1, -1 });
	void erase(Point p = { -1, -1 });

	void moveXY(short x, short y);
	void speak();

	Point getPos();

protected:
	Point pos;				//y tính theo số thứ tự làn đường (ko phải toạ độ trên màn hình!!)
	int speed;				//Giá trị càng nhỏ, khoảng cách giữa step vẽ càng ngắn → Di chuyển càng nhanh
	vector<string> avatar;	//Chứa ngoại hình của các vật (có 3 dòng)
	string voice;			//Âm thanh của object để nói hoặc kêu
};