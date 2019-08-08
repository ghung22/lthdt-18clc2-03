#include "Threads.h"
#include "CGAME.h"

#include <mmsystem.h>
#include <iostream>
using namespace std;

bool IS_RUNNING = true;
extern bool IS_PAUSED;

void exitGame(thread& t)
{
	system("CLS");
	IS_RUNNING = false;	//Stop update frames
	if (t.joinable())
		t.join();		//Join main thread
}

template <class T>
bool inContact(Point pos, T o)
{
	Window wt;
	short x = o.getPos().X, y = o.getPos().Y,
		maxX = wt.GetConsoleSize().Right,
		minX = wt.GetConsoleSize().Left;

	while (x > maxX)
		x -= maxX;
	while (x < minX)
		x += maxX;

	return x <= pos.X && pos.X <= x + 5
		&& pos.Y == y;
}
bool CheckCollision(CGAME* g)
{
	Point pos = g->p.getPos();
	bool colided = false;
	int n = g->p.getLevel() / 2 + 1; //Số object trên làn đường

	for (int i = 0; i < n; i++)
	{
		bool hitTruck = inContact(pos, g->truck[i]),
			hitCar = inContact(pos, g->car[i]), 
			hitBird = inContact(pos, g->bird[i]),
			hitDino = inContact(pos, g->dino[i]);
		if (hitTruck || hitCar || hitBird || hitDino)
		{
			colided = true;
			break;
		}
	}
	if (colided)
	{
		//Hiệu ứng va chạm và thua
		if (g->getSound())
		{
			string temp = "Data\\Sounds\\Crash.wav";
			PlaySound(temp.c_str(), NULL, SND_ASYNC | SND_FILENAME);
		}

		Window wt;
		Point t = pos;
		t.Y = (10 - t.Y) * 5 + 2;
		t.Y++; wt.GotoXY(t);
		cout << "  " << char(249) << "  ";
		Sleep(100); wt.GotoXY(t);
		cout << "  O  ";
		Sleep(100);

		t = pos;
		t.Y = (10 - t.Y) * 5 + 2;
		wt.GotoXY(t);
		cout << "\\ | /";
		t.Y++; wt.GotoXY(t);
		cout << "-   -";
		t.Y++; wt.GotoXY(t);
		cout << "/ | \\";
		Sleep(1);
	}
	return colided;
}
void UpdateGameFrame(CGAME* g)
{
	long temp = 0;

	while (IS_RUNNING)
	{
		if (!IS_PAUSED)
		{
			if (temp >= 50000) //Hết time, thua
			{
				g->lose(0);
				break;
			}

			if (g->p.getPos().Y >= 9) //Người chơi đến đích, tăng level
			{
				g->reset(false);
				temp = 0;
			}

			g->MoveObjects(temp); //Di chuyển vật
			if (!g->p.isDead()) //Nếu đã va chạm thì thua
				if (CheckCollision(g))
				{
					g->lose(1);
					break;
				}

			temp++;
			Sleep(1);
		}
	}
}