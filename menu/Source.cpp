#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<Windows.h>
using namespace std;

int main()
{
	while (true)
	{
		int lc; // biến lựa chọn menu
		do {
			system("cls"); // xóa màn hình
			cout << "\n\n\t\t\t\t\t\t\t================ Menu ================";
			cout << "\n\t\t\t\t\t\t\t\t1. NEW GAME ";
			cout << "\n\t\t\t\t\t\t\t\t2. LOAD GAME ";
			cout << "\n\t\t\t\t\t\t\t\t3. SETTINGS ";
			cout << "\n\t\t\t\t\t\t\t\t0. EXIT ";
			cout << "\n\t\t\t\t\t\t\t================ End =================";
			// Nhập lựa chọn
			cout << "\n Choose your option: ";
			cin >> lc;
			// Kiểm tra nếu người dùng nhập lựa chọn không hợp lệ thì yêu cầu người dùng nhập lại 
			if (lc != 0 && lc != 1 && lc != 2 && lc != 3)
			{
				cout << "\n ERROR! ";
				system("pause");// dừng màn hình cho người dùng xem
			}
		} while (lc != 0 && lc != 1 && lc != 2 && lc != 3 && lc != 4);// Nếu điều kiện đúng thì sẽ lặp lại do{}while();

		// Kiểm tra lựa chọn - thỏa lựa chọn nào thì thực hiện lựa chọn đó
		if (lc == 0)
		{
			break; // Thoát khỏi vòng lặp vô tận while. Kết thúc chương trình
		}
	}
	system("pause");
	return 0;
}