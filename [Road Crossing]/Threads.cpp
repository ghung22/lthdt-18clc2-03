#include "Threads.h"
#include "CGAME.h"

#include <iostream>
using namespace std;

bool IS_RUNNING = true;
extern bool IS_PAUSED;

void exitGame(thread& t)
{
	system("CLS");
	IS_RUNNING = false;	//Stop update frames
	t.join();			//Join main thread
}

template <class T>
bool inContact(Point pos, T o)
{
	return pos.X <= o.getPos().X && o.getPos().X <= pos.X + 5
		&& pos.Y == o.getPos().Y;
}
void CheckCollision(CGAME* g)
{
	Point pos = g->p.getPos();
	bool colided = false;
	int n = g->p.getLevel() / 2 + 1; //Số object trên làn đường

	for (int i = 0; i < n; i++)
	{
		bool hitTruck = inContact(pos, g->truck[0]),
			hitCar = inContact(pos, g->car[0]), 
			hitDino = inContact(pos, g->dino[0]), 
			hitBird = inContact(pos, g->bird[0]);
		if (hitTruck || hitCar || hitDino || hitBird)
		{
			colided = true;
			break;
		}
	}
	if (colided)
		//Hiệu ứng va chạm và thua
		cout << "Kimochi~~";
}
void UpdateGameFrame(CGAME* g)
{
	long temp = 0;

	while (IS_RUNNING)
	{
		if (!IS_PAUSED)
		{
			if (temp >= 50000) //Hết time, thua
				break;

			if (g->p.getPos().Y >= 9) //Người chơi đến đích, tăng level
			{
				g->reset(false);
				temp = 0;
			}

			if (temp % 20 == 0)
			{
				long s = temp / 20;
				//Di chuyển object
			}
			CheckCollision(g);

			temp++;
			Sleep(1);
		}
	}
}