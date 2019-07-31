#pragma once

//Số level tối đa của 1 ván
#define MAX_LEVEL 10

//Thứ tự làn đường
#define TRUCK_Y 6
#define CAR_Y 2
#define BIRD_Y 4
#define DINO_Y 8
#define PEOPLE_Y 1

//Tốc độ của các vật
#define TRUCK_SPD 25
#define CAR_SPD 20
#define BIRD_SPD 20
#define DINO_SPD 30

//Biểu tượng của CPEOPLE
#define P_HEAD0 'o'
#define P_HEAD1 char(235)
#define P_HEAD2 char(229)

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