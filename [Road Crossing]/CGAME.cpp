#include "CGAME.h"

char MOVING;

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
	quick_exit(0);
}

void CGAME::start()
{
	LockWinSize(); //Khoá thay đổi size màn hình
	while (true)
	{
		int lc; // biến lựa chọn menu
		do {
			system("cls"); // xóa màn hình
			cout << endl << endl
				<< "\t\t\t\t================ Menu ================" << endl
				<< "\t\t\t\t\t1. NEW GAME " << endl
				<< "\t\t\t\t\t2. LOAD GAME " << endl
				<< "\t\t\t\t\t3. SETTINGS " << endl
				<< "\t\t\t\t\t0. EXIT " << endl
				<< "\t\t\t\t================ End =================" << endl;
			// Nhập lựa chọn
			cout << "Choose your option: ";
			cin >> lc;
			cin.ignore();
			switch (lc)
			{
			case 0: break;
			case 1: game(); break;
			case 2: load(); break;
			case 3: break;
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
	char pressed;
	thread gThread(UpdateGameFrame);		//Chạy hàm song song với main()
	while (true)
	{
		pressed = toupper(getchar());
		if (!getPeople().isDead())	//Nếu người chơi chưa die, nhận nút di chuyển và các nút menu
			switch (pressed)
			{
			case 27:	//Phím ESC
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

void CGAME::load() { }
void CGAME::save() { }
void CGAME::pause(thread::native_handle_type handle) { }
void CGAME::resume(thread::native_handle_type handle) { }

void CGAME::updatePosPeople(char button) { }
void CGAME::updatePosVehicle() { }
void CGAME::updatePosAnimal() { }