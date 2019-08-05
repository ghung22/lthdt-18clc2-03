#pragma once

/*
Mỗi làn rộng 5 hàng:
	1 hàng trống
	3 hàng vẽ nhân vật
	1 hàng đường

Chia màn hình thành các làn đường (list từ trên xuống)
	Đầu màn hình: Menu
	Làn 9: Đích đến
	Làn 8: CDino
	Làn 7: Dòng trống
	Làn 6: CTruck
	Làn 5: Dòng trống
	Làn 4: CBird
	Làn 3: Dòng trống
	Làn 2: CCar
	Làn 1: Điểm bắt đầu
*/

//Số level tối đa của 1 ván
#define MAX_LEVEL 10

//Thứ tự làn đường
#define TRUCK_Y 6
#define CAR_Y 2
#define BIRD_Y 4
#define DINO_Y 8
#define PEOPLE_Y 1

//Tốc độ của các vật
#define TRUCK_SPD 26
#define CAR_SPD 22
#define BIRD_SPD 21
#define DINO_SPD 31
#define LIGHT_SPD 2000

//Biểu tượng của CPEOPLE
#define P_HEAD0 'o'
#define P_HEAD1 char(235) //δ
#define P_HEAD2 char(229) //σ

//Các giá trị dialog của hàm prompt()
#define TIMEUP_DIALOG 0
#define PLAYERDIE_DIALOG 1
#define LOADGAME_DIALOG 2
#define SAVEGAME_DIALOG 3
#define PAUSED_DIALOG 4

//Ngoại hình của các object
class defaultAva
{
public:
	static vector<string> avatar(string object)
	{
		vector<string>
			//default
			d_null = { "", "", "" },
			d_p =
		{
			{ ' ', P_HEAD0},						// o				 o
			{ char(218), char(197), char(217) },	//┌┼┘ //192 197 191 └┼┐
			{ ' ', char(227)}						// π				 π
		},
			d_truck =
		{
			{ char(218), char(196), char(196), char(191)},			//┌──┐
			{ char(179), ' ', char(219), char(219), char(219) },	//│ ███
			{ 'O', char(196), char(196), 'O'}						//O──O
		},
			d_car =
		{
			"",
			{ char(218), char(196), char(191)},			//┌─┐
			{ 'O', char(223), char(223), 'o' }			//O▀▀o
		},
			d_bird = { { char(169), char(250), char(170) }, "", "" },	//⌐·¬	-·-
			d_dino =
		{
			{ ' ', char(244)},			// ⌠
			"(0)",						//(0)
			{ char(217), 'L', 'L' }		//┘LL
		},
			//flipped
			f_truck = { { ' ', char(218), char(196), char(196), char(191) }, { char(219), char(219), char(219), ' ', char(179) }, { ' ', 'O', char(196), char(196), 'O' } },
			f_car = { "", { ' ', char(218), char(196), char(191)}, { 'o', char(223), char(223), 'O' } };

		if (object == "people" || object == "people_flipped")
			return d_p;
		else if (object == "truck")
			return d_truck;
		else if (object == "truck_flipped")
			return f_truck;
		else if (object == "car")
			return d_car;
		else if (object == "car_flipped")
			return f_car;
		else if (object == "bird" || object == "bird_flipped")
			return d_bird;
		else if (object == "dino" || object == "dino_flipped")
			return d_dino;
		else
			return d_null;
	}
};
#define TRUCK_AVA defaultAva::avatar("truck")
#define CAR_AVA defaultAva::avatar("car")
#define BIRD_AVA defaultAva::avatar("bird")
#define DINO_AVA defaultAva::avatar("dino")
#define PEOPLE_AVA defaultAva::avatar("people")