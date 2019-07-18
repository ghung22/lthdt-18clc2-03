#pragma once
#include <conio.h>
using namespace std;
class CGAME
{
private:
	bool quit;
	CPEOPLE *player;
public:
	CGAME();
	void Input();
	~CGAME();
};

