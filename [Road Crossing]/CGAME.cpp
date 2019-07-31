#include "CGAME.h"
#include "Constants.h"

#include <fstream>
#include <string>
#include <conio.h>
#include <mmsystem.h>

Window w;
extern void UpdateGameFrame(CGAME* g); //cho biết có hàm này ở bên file khác, để đem vào thread bên dưới ko bị lỗi undefined
extern void CheckCollision(CGAME* g);
extern bool IS_RUNNING;
bool IS_PAUSED;

CGAME::CGAME() { sound = true; }

void CGAME::reset(bool loss) { initObjects(loss); }
void CGAME::exit(thread& t)
{
	exitGame(t);
	start();
}

void CGAME::start()
{
	PlaySound(0, 0, 0); //mute sound
	settingLoad();
	w.LockWinSize();
	w.HideCursor();

	char lc = 0; // biến lựa chọn menu
	system("cls"); // xóa màn hình
	cout << endl << endl
		<< "\t\t\t\t================ ROAD CROSSING ================" << endl
		<< "\t\t\t\t\t1. NEW GAME " << endl
		<< "\t\t\t\t\t2. LOAD GAME " << endl
		<< "\t\t\t\t\t3. SETTINGS " << endl
		<< "\t\t\t\t\t0. EXIT " << endl
		<< "\t\t\t\t===============================================" << endl;
	cout << "Choose your option" << endl << endl;

	// Nhập lựa chọn
	while (lc != '0')
	{
		if (_kbhit())
		{
			lc = _getch();
			switch (lc)
			{
			case '1': game(); break;
			case '2': load(); break;
			case '3': setting(); break;
			}
		}
	}
}
void CGAME::game()
{
	PlaySound(0, 0, 0); //mute sound
	w.HideCursor();
	initObjects();
	char pressed;
	thread gThread(UpdateGameFrame, this);		//Chạy hàm song song với main()
	IS_RUNNING = true;
	IS_PAUSED = false;
	bool escape = false;
	while (!escape)
	{
		if (_kbhit())
		{
			pressed = toupper(_getch());
			if (!p.isDead())	//Nếu người chơi chưa die, nhận nút di chuyển và các nút menu
				switch (pressed)
				{
				case VK_ESCAPE:	//Phím ESC
					escape = true;
					exit(gThread);
					break;
				case 'P':
					pause();
					break;
				default:
					resume();
					p.Move(pressed); //Các phím di chuyển người chơi
					break;
				}
			else	//Khi đã die hoặc mới bắt đầu game, ấn Y thì bắt đầu chơi
			{
				w.GotoXY(40, 10);
				cout << "Lost. Press Y to play again.";
				if (pressed == 'Y')
					start();
				else
					exit(gThread);
			}
		}
	}
}
void CGAME::setting()
{
	w.HideCursor();
	
	char o = 0;

	REFRESH:
	system("cls");
	cout
		<< "================ SETTINGS ================" << endl
		<< "1. Music and Sounds: " << sound << endl
		<< "2. Player head: " << p.getIcon(0) << endl
		<< "3. Restore default settings" << endl
		<< "0. Quit." << endl
		<< "==========================================" << endl;
	cout << "Choose your option";

	while (o != '0')
	{
		if (_kbhit())
		{
			o = _getch();
			switch (o)
			{
			case '1': sound = !sound; break;
			case '2':
				p.setIcon(p.getIcon() + 1);
				break;
			case '3':
				sound = true;
				p.setIcon(0);
				break;
			}
			goto REFRESH;
		}
	}

	settingSave();
	if (!sound)
		PlaySound(0, 0, 0); //mute sound

	start();
}
void CGAME::settingLoad()
{
	ifstream fin("setting.ini");
	if (fin.fail())
	{
		settingSave();
		return;
	}
	string temp;
	while (!fin.eof())
	{
		getline(fin, temp);
		if (temp.length() > 0)
		{
			char c = temp[temp.length() - 1];
			if (temp.find("bSound") != string::npos)
				sound = c - '0';
			else if (temp.find("cPlayerCharacter") != string::npos)
				p.setIcon(c);
		}
	}
	fin.close();
}
void CGAME::settingSave()
{
	ofstream fout("setting.ini");
	if (fout.fail())
	{
		cout << "Failed to save settings to file" << endl;
		return;
	}
	fout << "[Setting]" << endl
		<< "bSound=" << sound << endl
		<< "cPlayerCharacter=" << p.getIcon() << endl;
	fout.close();
}

void CGAME::load()
{
	w.GotoXY(5, 40);
	ifstream fin("roadcrossing.sav", ios::binary);
	if (fin.fail())
	{
		cout << "Error loading file";
		return;
	}
	int temp;
	fin.read((char*)&temp, sizeof(int));
	fin.close();
	p.setLevel(temp);
}
void CGAME::save()
{
	w.GotoXY(5, 40);
	ofstream fout("roadcrossing.sav", ios::binary);
	if (fout.fail())
	{
		cout << "Error saving file";
		return;
	}
	fout.write((char*)p.getLevel(), sizeof(int));
	fout.close();
	cout << "Saved to roadcrossing.sav";
}
void CGAME::pause() { IS_PAUSED = true; }
void CGAME::resume() { IS_PAUSED = false; }

void CGAME::UpdateGameInfo()
{
	w.GotoXY(3, 2);
	cout << "Level: " << p.getLevel();
	w.GotoXY(32, 2);
	cout << "Press WASD to move";
	w.GotoXY(32, 3);
	cout << "ESC to exit, P to pause";
}

void CGAME::initObjects(bool resetP)
{
	clearObjects(resetP);
	UpdateGameInfo();

	//thêm một object vào làn đường mỗi 2 level
	unsigned level = p.getLevel(),
		add = level / 2;
	short x0 = w.GetConsoleSize().Right / (add + 1), //chia đều các xe trên làn
		x1 = rand() % 20,
		x2 = rand() % 20, 
		x3 = rand() % 20, 
		x4 = rand() % 20;
	for (unsigned i = 0; i <= add; i++)
	{
		CTruck t(x1);
		CCar c(x2);
		CDino d(x3);
		CBird b(x4);
		t.draw();
		c.draw();
		d.draw();
		b.draw();
		truck.push_back(t);
		car.push_back(c);
		dino.push_back(d);
		bird.push_back(b);
		x1 += x0; x2 += x0; x3 += x0; x4 += x0;
	}
}
void CGAME::clearObjects(bool resetP)
{
	w.SplitLanes();
	for (unsigned i = 0; i < truck.size(); i++)
		truck.pop_back();
	for (unsigned i = 0; i < car.size(); i++)
		car.pop_back();
	for (unsigned i = 0; i < dino.size(); i++)
		dino.pop_back();
	for (unsigned i = 0; i < bird.size(); i++)
		bird.pop_back();

	unsigned level = p.getLevel();

	p.erase();
	p.reset();
	if (!resetP) //Nếu người chơi tahwsng trước đó, thay đổi lại level
		if (level < MAX_LEVEL)
			p.setLevel(level + 1);
		else
			p.setLevel(MAX_LEVEL);
	p.draw();
}

bool CGAME::getSound() { return sound; }