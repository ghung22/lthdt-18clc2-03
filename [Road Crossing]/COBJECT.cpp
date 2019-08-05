//Cần thêm winmm.lib vào Linker trong Project Properties để hàm speak hoạt động
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
	voice = "";
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

	if (rand() % 100 == 0)
		speak();
}
void COBJECT::speak()
{
	static CGAME* g;
	if (g->getSound() && voice != "")
	{
		string temp = "Data\\Sounds\\" + voice;
		PlaySound(temp.c_str(), NULL, SND_ASYNC | SND_FILENAME);
	}
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

CLIGHT::CLIGHT() : COBJECT()
{
	type = "light";
	speed = LIGHT_SPD;
	voice = "Light.wav";
	green = false;
}
CLIGHT::CLIGHT(short x, short y) : CLIGHT() { pos.X = x; pos.Y = y; }
void CLIGHT::changeColor() { green = !green; }
void CLIGHT::draw()
{
	short Y = (10 - pos.Y) * 5;
	wd.GotoXY(pos.X, Y);
	char temp[2] = { char(223), 0 };

	if (!green)
	{
		printf("\033[031m"); //red
		printf(temp); //▀
		printf("\033[0m"); //reset color
		printf(temp); //▀
	}
	else
	{
		printf("\033[0m"); //reset color
		printf(temp); //▀
		printf("\033[032m"); //green
		printf(temp); //▀
		printf("\033[0m"); //reset color
	}
}
bool CLIGHT::moveXY(long timer)
{
	if (timer % abs(speed) != 0)
		return green;

	changeColor();
	draw();
	speak();

	return green;
}