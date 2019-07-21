#include "CGAME.h"
#include "Constants.h"

#include <fstream>
#include <string>

char MOVING;
Window w;

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

CPEOPLE CGAME::getPeople()
{
	return p;
}

CVEHICLE* CGAME::getVehicle() { return nullptr; }
CANIMAL* CGAME::getAnimal() { return nullptr; }

void CGAME::draw() { }
void CGAME::reset() { }
void CGAME::exit(thread::native_handle_type handle)
{
	system("cls");
	terminate();
	quick_exit(0);
}

void CGAME::start()
{
	settingLoad();
	w.LockWinSize(); //Khoá thay đổi size màn hình
	w.ShowCursor(); //Hiện con trỏ
	//ShowInput(); //Hiện input
	while (true)
	{
		int lc; // biến lựa chọn menu
		do {
			system("cls"); // xóa màn hình
			cout << endl << endl
				<< "\t\t\t\t================ ROAD CROSSING ================" << endl
				<< "\t\t\t\t\t1. NEW GAME " << endl
				<< "\t\t\t\t\t2. LOAD GAME " << endl
				<< "\t\t\t\t\t3. SETTINGS " << endl
				<< "\t\t\t\t\t0. EXIT " << endl
				<< "\t\t\t\t===============================================" << endl;
			// Nhập lựa chọn
			cout << "Choose your option: ";
			cin >> lc;
			cin.ignore();
			switch (lc)
			{
			case 0: break;
			case 1: game(); break;
			case 2: load(); break;
			case 3: setting(); break;
			default:
				//Nếu người dùng nhập lựa chọn không hợp lệ thì yêu cầu người dùng nhập lại 
				cout << "\n ERROR! ";
				system("pause");// dừng màn hình cho người dùng xembreak;
			}
		} while (lc != 0 && lc != 1 && lc != 2 && lc != 3 && lc != 4);// Nếu điều kiện đúng thì sẽ lặp lại do{}while();

		// Kiểm tra lựa chọn - thỏa lựa chọn nào thì thực hiện lựa chọn đó
		if (lc == 0)
		{
			break; // Thoát khỏi vòng lặp vô tận while. Kết thúc chương trình
		}
	}
}
void CGAME::game()
{
	system("cls");
	w.HideCursor(); //Giấu con trỏ
	//HideInput(); //Giấu input
	char pressed;
	thread gThread(UpdateGameFrame);		//Chạy hàm song song với main()
	while (true)
	{
		pressed = toupper(getchar());
		if (!getPeople().isDead())	//Nếu người chơi chưa die, nhận nút di chuyển và các nút menu
			switch (pressed)
			{
			case VK_ESCAPE:	//Phím ESC
				exit(gThread.native_handle());
			case 'P':
				pause(gThread.native_handle());
				break;
			default:
				resume(gThread.native_handle());
				MOVING = pressed;	//Cập nhật bước di chuyển
				break;
			}
		else	//Khi đã die hoặc mới bắt đầu game, ấn Y thì bắt đầu chơi
		{
			if (pressed == 'Y')
				start();
			else
				exit(gThread.native_handle());
		}
	}
}
void CGAME::setting()
{
	w.ShowCursor();
	//ShowInput();
	while (true)
	{
		int o;
		system("cls");
		cout
			<< "================ SETTINGS ================" << endl
			<< "1. Music: " << music << endl
			<< "2. Sound: " << sound << endl
			<< "3. Player head: " << p.getIcon() << endl
			<< "4. Restore default settings" << endl
			<< "0. Quit." << endl
			<< "==========================================" << endl;
		cout << "Choose your option: ";
		cin >> o;
		cin.ignore();
		switch (o)
		{
		case 1: music = !music; break;
		case 2: sound = !sound; break;
		case 3: 
			p.setIcon(p.getIcon() + 1);
			break;
		case 4: 
			music = true;
			sound = true;
			p.setIcon(0);
			break;
		}

		if (o == 0)
			break;
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

void CGAME::load() { }
void CGAME::save() { }
void CGAME::pause(thread::native_handle_type handle) { }
void CGAME::resume(thread::native_handle_type handle) { }

void CGAME::updatePosPeople(char button) { }
void CGAME::updatePosVehicle() { }
void CGAME::updatePosAnimal() { }