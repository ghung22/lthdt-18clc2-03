#pragma once
#include "Header.h"
#include "Obstacle.h"

#pragma pack(1)
class TrafficLight {
	int m_x;
	int m_y;
	int m_state;
public:
	TrafficLight() {
		m_x = 2;
		m_y = 2;
		m_state = 0;
	}

	TrafficLight(const int& forward, const int& line) {
		m_y = line * 6 + 2;
		if (forward < 0)
			m_x = 2;
		else m_x = boardWidth - 2;
		m_state = 2;
	}


	void drawTrafficLight() {
		GotoXY(m_x, m_y + m_state);
		switch (m_state) {
		case 0: {setTextAttribute(12);
			break; }
		case 1: {setTextAttribute(14);
			break; }
		case 2: {setTextAttribute(10);
			break; }
		}
		cout << char(219);
		setTextAttribute(ColorCode_Grey);
	}
	void setLight(const int& x, const int& y, const int& state) {
		m_state = state;
		m_x = x;
		m_y = y;
	}
	void setState(const int& state) {
		m_state = state;
	}
	int& getState() {
		return m_state;
	}
	void clearSelf() {
		GotoXY(m_x, m_y + m_state);
		cout << char(32);
	}
};

class Vehicle :public Obstacle
{
	friend class Game;
public:
	Vehicle() :Obstacle() {};
	Vehicle(int x, int y) :Obstacle(x, y) {}
	Vehicle(const Vehicle& p) :Obstacle(p) {}
	virtual void Draw() {};
	void UpdatePositionLevel0(const int& forward) {
		Obstacle::UpdatePositionLevel0(forward * 2);
	}
	virtual void clearSelf() {};
};
//-----------------

class Car : public Vehicle
{
public:
	Car() :Vehicle() {};
	Car(const int& x, const int& y) :Vehicle(x, y) {};
	Car& operator=(const Car& p) { Vehicle::operator=(p); }
	//void Horn();
	void Draw();
	void clearSelf();
};

/*void Car::Horn()
{
PlaySound(TEXT("car.wav"), NULL, SND_ASYNC | SND_LOOP);		//	NOT FINISHED
PlaySound(NULL, NULL, NULL);
}*/


void Car::Draw()
{
	int X = getX();
	int Y = getY();


	/*GotoXY(X, Y);
	cout << char(219);
	GotoXY(X - 1, Y);
	cout << char(219);
	GotoXY(X - 2, Y);
	cout << ' ' << char(220);
	GotoXY(X + 1, Y);
	cout << char(219);
	GotoXY(X + 2, Y);
	cout << char(220);
	GotoXY(X - 1, Y + 1);
	cout << ' ' << char(248);
	GotoXY(X + 1, Y + 1);
	cout << char(248);
	GotoXY(X - 1, Y - 1);
	cout << ' ' << char(193);*/

	/*GotoXY(X - 1, Y - 1);
	cout << ' ' << char(193);
	GotoXY(X - 3, Y);
	cout << ' ' << char(220) << char(219) << char(220);
	GotoXY(X - 3, Y + 1);
	cout << ' ' << char(248) << ' ' << char(248);*/

	GotoXY(X, Y);
	cout << char(219);
	GotoXY(X - 1, Y);
	cout << char(219);
	GotoXY(X - 2, Y);
	cout << char(220);
	GotoXY(X + 1, Y);
	cout << char(219);
	GotoXY(X + 2, Y);
	cout << char(220);
	GotoXY(X - 1, Y + 1);
	cout << char(248);
	GotoXY(X + 1, Y + 1);
	cout << char(248);
	GotoXY(X, Y - 1);
	cout << char(193);
}

void Car::clearSelf() {
	int X = getX();
	int Y = getY();

	/*GotoXY(X, Y);
	cout << char(32);
	GotoXY(X - 1, Y);
	cout << char(32);
	GotoXY(X - 2, Y);
	cout << char(32);
	GotoXY(X + 1, Y);
	cout << char(32);
	GotoXY(X + 2, Y);
	cout << char(32);
	GotoXY(X - 1, Y + 1);
	cout << char(32);
	GotoXY(X + 1, Y + 1);
	cout << char(32);
	GotoXY(X, Y - 1);
	cout << char(32);*/

	GotoXY(X, Y);
	cout << char(32);
	GotoXY(X - 1, Y);
	cout << char(32);
	GotoXY(X - 2, Y);
	cout << char(32);
	GotoXY(X + 1, Y);
	cout << char(32);
	GotoXY(X + 2, Y);
	cout << char(32);
	GotoXY(X - 1, Y + 1);
	cout << char(32);
	GotoXY(X + 1, Y + 1);
	cout << char(32);
	GotoXY(X, Y - 1);
	cout << char(32);

	/*GotoXY(X - 1, Y - 1);
	cout << ' ' << ' ' << ' ';
	GotoXY(X - 1, Y);
	cout << ' ' << ' ' << ' ';
	GotoXY(X - 1, Y + 1);
	cout << ' ' << ' ' << ' ';*/

}

//-----------------

class Truck : public Vehicle
{
public:
	Truck(const int& x, const int& y) : Vehicle(x, y) {};
	//void Horn();
	void Draw();
	void clearSelf();
};

/*void Truck::Horn()
{
PlaySound(TEXT("truck.wav"), NULL, SND_ASYNC | SND_LOOP);		//	NOT FINISHED
PlaySound(NULL, NULL, NULL);
}
*/
void Truck::Draw()
{
	int X = getX();
	int Y = getY();

	GotoXY(X - 2, Y);
	cout << char(219);
	GotoXY(X - 1, Y);
	cout << char(219);
	GotoXY(X, Y);
	cout << char(219);
	GotoXY(X + 1, Y);
	cout << char(219);
	GotoXY(X + 2, Y);
	cout << char(220);
	GotoXY(X + 1, Y - 1);
	cout << char(218);
	GotoXY(X + 1, Y);
	cout << char(220);
	GotoXY(X - 1, Y + 1);
	cout << char(248);
	GotoXY(X + 1, Y + 1);
	cout << char(248);

	/*GotoXY(X - 1, Y - 1);
	cout << ' ' << char(193);
	GotoXY(X - 3, Y);
	cout << ' ' << char(219) << char(219) << char(220);
	GotoXY(X - 3, Y + 1);
	cout << ' ' << char(248) << ' ' << char(248);*/   //official truck
}

void Truck::clearSelf() {
	int X = getX();
	int Y = getY();
	/*GotoXY(boardWidth + 3, 19);
	cout << "cleared trcuk";*/
	//GotoXY(X - 2, Y);
	//cout << char(32);
	GotoXY(X - 2, Y);
	cout << char(32);
	GotoXY(X - 1, Y);
	cout << char(32);
	GotoXY(X, Y);
	cout << char(32);
	GotoXY(X + 1, Y);
	cout << char(32);
	GotoXY(X + 2, Y);
	cout << char(32);
	GotoXY(X + 1, Y - 1);
	cout << char(32);
	GotoXY(X + 1, Y);
	cout << char(32);
	GotoXY(X - 1, Y + 1);
	cout << char(32);
	GotoXY(X + 1, Y + 1);
	cout << char(32);

	/*GotoXY(X - 1, Y - 1);
	cout << ' ' << ' ' << ' ';
	GotoXY(X - 1, Y);
	cout << ' ' << ' ' << ' ';
	GotoXY(X - 1, Y + 1);
	cout << ' ' << ' ' << ' ';*/
}