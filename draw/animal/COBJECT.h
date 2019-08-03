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

	//timer: biến đếm trong vòng lặp của thread, dùng để tránh di chuyển liên tục từng frame
	void moveXY(short x = -1, short y = -1, long timer = 0);
	void speak();

	Point getPos();
	void speedDirChange(int i = 1);

protected:
	void flip();			//Lật ngược avatar tuỳ vào chiều di chuyển

	string type;			//Loại object
	Point pos;				//y tính theo số thứ tự làn đường (ko phải toạ độ trên màn hình!!)
	int speed;				//Giá trị càng nhỏ, khoảng cách giữa step vẽ càng ngắn → Di chuyển càng nhanh
	vector<string> avatar;	//Chứa ngoại hình của các vật (có 3 dòng)
	string voice;			//Âm thanh của object để nói 
};
