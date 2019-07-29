#include "CGAME.h"
#include "Constants.h"

#include <fstream>
#include <string>
#include <conio.h>

Window w;
extern void UpdateGameFrame(CGAME* g); //cho biết có hàm này ở bên file khác, để đem vào thread bên dưới ko bị lỗi undefined

CGAME::CGAME()
{
	CTruck t;
	CCar c;
	CBird b;
	CDino d;
	truck.push_back(t);
	car.push_back(c);
	dino.push_back(d);
	bird.push_back(b);

	music = 1;
	sound = 1;
}

void CGAME::reset() { }
void CGAME::exit(thread& t)
{
	exitGame(t);
	start();
}

void CGAME::start()
{
	settingLoad();
	w.LockWinSize(); //Khoá thay đổi size màn hình
	w.HideCursor(); //Ẩn con trỏ

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
	system("cls");
	w.HideCursor(); //Giấu con trỏ
	w.SplitLanes();	//Chia làn
	UpdateGameInfo();
	char pressed;
	thread gThread(UpdateGameFrame, this);		//Chạy hàm song song với main()
	bool escape = false;
	while (!escape)
	{
		if (_kbhit())
		{
			pressed = _getch();
			if (!p.isDead())	//Nếu người chơi chưa die, nhận nút di chuyển và các nút menu
				switch (pressed)
				{
				case VK_ESCAPE:	//Phím ESC
					escape = true;
					exit(gThread);
					break;
				case 'P':
					pause(gThread);
					break;
				default:
					resume(gThread);
					p.Move(pressed); //Các phím di chuyển người chơi
					break;
				}
			else	//Khi đã die hoặc mới bắt đầu game, ấn Y thì bắt đầu chơi
			{
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
		<< "1. Music: " << music << endl
		<< "2. Sound: " << sound << endl
		<< "3. Player head: " << p.getIcon(0) << endl
		<< "4. Restore default settings" << endl
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
			case '1': music = !music; break;
			case '2': sound = !sound; break;
			case '3':
				p.setIcon(p.getIcon() + 1);
				break;
			case '4':
				music = true;
				sound = true;
				p.setIcon(0);
				break;
			}
			goto REFRESH;
		}
	}

	settingSave();
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
			if (temp.find("bMusic") != string::npos)
				music = c - '0';
			else if (temp.find("bSound") != string::npos)
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
	fout << "[Media]" << endl
		<< "bMusic=" << music << endl
		<< "bSound=" << sound << endl
		<< endl
		<< "[Main]" << endl
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
	fin.read((char*)p.getLevel(), sizeof(int));
	fin.close();
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
void CGAME::pause(thread& t) { }
void CGAME::resume(thread& t) { }

void CGAME::UpdateGameInfo()
{
	w.GotoXY(3, 2);
	cout << "Level: " << p.getLevel();
	w.GotoXY(32, 2);
	cout << "Press WASD to move";
	w.GotoXY(32, 3);
	cout << "ESC to exit, P to pause";
}