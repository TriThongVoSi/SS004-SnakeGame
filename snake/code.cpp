#include"mySnake.h"
using namespace std;
//--------- snake 1 người chơi --------------------
void Snake::play() {
	
	//chọn tốc độ chạy của rắn
	   // mức 1: chậm nhất
	   // mức 2: trung bình
	   // mức 3: nhanh
	setting(); 

//chọn màu cho rắn
	



	ShowCur(0);
	//build gamex
	ve_tuong();
	khoi_tao_ran();
	tao_qua();
	ve_qua();
	xuat_diem(); 
	int x = toa_dox[0];
	int y = toa_doy[0];
	//điều kiện chạy
		//- check = 0 đi xuống 
		//- check = 1 đi lên
		//- check = 2 sang trái
		//- check = 3 sang phải
	int check = 3;
	//play
	while (true && !chien_thang_tro_choi()) {
		//xóa đuôi
		gotoXY(toa_dox[sl], toa_doy[sl]);
		std::cout << " ";
		// vẽ rắn
		ve_ran();

		//điều khiển
			//sử dụng các phím mũi tên hoặc w, a, s, d để di chuyển rắn
		if (_kbhit()) {
			char c = _getch();
			if (c == -32) {
				c = _getch();
				if (c == 72 && check != 0)  check = 1;
				else if (c == 80 && check != 1) check = 0;
				else if (c == 75 && check != 3) check = 2;
				else if (c == 77 && check != 2) check = 3;
			}
			if (c == (char)'w') check = 1;
			else if (c == (char)'s') check = 0;
			else if (c == (char)'a') check = 2;
			else if (c == (char)'d') check = 3;  
		}
		if (check == 3) x++;
		else if (check == 2) x--;
		else if (check == 1) y--;
		else if (check == 0) y++;
		//kiểm tra biên
		if (game_over(toa_dox[0], toa_doy[0])) {
			system("cls");
			std::cout << "Game over";
			break;
		}
		if (qua_to % 5 != 0) xu_li_ran_an_qua();
		else if (qua_to % 5 == 0) xu_li_ran_an_qua_to();
		di_chuyen(x, y);
		Sleep(sleep);

	}
	if (chien_thang_tro_choi()) std::cout << "Ban da chien thang tro choi"; 
}
//vẽ tường
void Snake::ve_tuong() {
	SetColor(11); 
	for (int i = 10; i <= 100; i++) {
		gotoXY(i, 1);
		std::cout << (char)176;
		gotoXY(i, 25);
		std::cout << (char)176;
	}
	for (int i = 1; i <= 25; i++) {
		gotoXY(10, i);	
		std::cout << (char)176;
		gotoXY(100, i);
		std::cout << (char)176;
	}
}
//khởi tạo rắn
void Snake::khoi_tao_ran() {
	int khoi_tao_x = 50;
	int khoi_tao_y = 13;
	for (int i = 0; i < sl; i++) {
		toa_dox[i] = khoi_tao_x--;
		toa_doy[i] = khoi_tao_y;
	}
}
//vẽ rắn
void Snake::ve_ran() {
	SetColor(mau_ran);
	for (int i = 0; i < sl; i++) {
		gotoXY(toa_dox[i], toa_doy[i]);
		if (i == 0) std::cout << (char)254;
		else std::cout << "o";
	}
}
//di chuyển
void Snake::di_chuyen(int x, int y) {
	for (int i = sl; i > 0; i--) {
		toa_dox[i] = toa_dox[i - 1];
		toa_doy[i] = toa_doy[i - 1];
	}
	toa_dox[0] = x;
	toa_doy[0] = y;
}
//kiểm tra game over
bool Snake::game_over(int x, int y) {
	if (toa_dox[0] == 10 || toa_dox[0] == 100 || toa_doy[0] == 1 || toa_doy[0] == 25)
		return true;
	return kiem_tra_ran_cham_than();
}
//tạo quả 
void Snake::tao_qua() {
		this->xqua = rand() % (99 - 11 + 1) + 11;
		this->yqua = rand() % (24 - 2 + 1) + 2;
		if (kiem_tra_ran_de_qua()) {
			tao_qua();
		}
	
  }
//vẽ quả
void Snake::ve_qua() {
		SetColor(15) ; 
		gotoXY(xqua, yqua); std::cout << '*';
	
}
//kiểm tra rắn ăn quả
bool Snake::kt_ran_an_qua() {
	return  (toa_dox[0] == xqua && toa_doy[0] == yqua);
}
// xử lí khi rắn ăn quả
void Snake::xu_li_ran_an_qua() {
	if (kt_ran_an_qua() ) {
		sl++;
		score += tocdo; 
		qua_to++;
		if (qua_to % 5 != 0) {
			tao_qua();
			ve_qua();
			xuat_diem(); 
		}
		else if (qua_to % 5 == 0) {
			tao_qua_to();
			in_qua_to(); 
		}
	}
}
//kiểm tra quả xuất hiện có trùng với rắn không
bool Snake::kiem_tra_ran_de_qua() {
	for (int i = 0; i < sl; i++) {
		if (toa_dox[i] == xqua && toa_doy[i] == yqua) return true;
	}
	return false;
}
//kiểm tra rắn chạm thân
bool Snake::kiem_tra_ran_cham_than() {
	for (int i = 4; i < sl; i++) {
		if (toa_dox[0] == toa_dox[i] && toa_doy[0] == toa_doy[i]) return true;
	}
	return false;
}

bool Snake::chien_thang_tro_choi() {
	if (sl == 91 * 25) return true; 
	return false; 
}

void Snake::tao_qua_to() {
	this->xqua_to = rand() % (98 - 12 + 1) + 12;
	this->yqua_to = rand() % (23 - 3 + 1) + 3;
	if (kiem_tra_ran_de_qua_to())
		tao_qua_to(); 
}

void Snake::in_qua_to() {
	if (!kiem_tra_ran_de_qua_to()) {
		for (int i = xqua_to - 1; i <= xqua_to + 1; i++) {
			for (int j = yqua_to - 1; j <= yqua_to + 1; j++)
			{
				gotoXY(i, j); 
				std::cout << "*";
			}
		}
	}
}
void Snake::xu_li_ran_an_qua_to() {
	if (kt_ran_an_qua_to()) {
		sl ++; 
		score +=10 ; 
		qua_to++;
		for (int i = xqua_to - 1; i <= xqua_to + 1; i++) {
			for (int j = yqua_to - 1; j <= yqua_to + 1; j++)
			{
				gotoXY(i, j);
				std::cout << " ";
			}
		}
		tao_qua(); 
		ve_qua(); 
		xuat_diem(); 
	}
}
bool Snake ::kt_ran_an_qua_to() {
		 if (toa_dox[0] == xqua_to -1 && toa_doy[0] == yqua_to -1) return true;
		else if (toa_dox[0] == xqua_to  && toa_doy[0] == yqua_to - 1) return true;
		else if (toa_dox[0] == xqua_to + 1 && toa_doy[0] == yqua_to - 1) return true;
		else if (toa_dox[0] == xqua_to + 1 && toa_doy[0] == yqua_to ) return true;
		else if (toa_dox[0] == xqua_to + 1 && toa_doy[0] == yqua_to + 1) return true;
		else if (toa_dox[0] == xqua_to && toa_doy[0] == yqua_to + 1) return true;
		else if (toa_dox[0] == xqua_to - 1 && toa_doy[0] == yqua_to + 1) return true;
		else if (toa_dox[0] == xqua_to - 1 && toa_doy[0] == yqua_to ) return true;
	return false;
}

bool Snake::kiem_tra_ran_de_qua_to() {
	for (int i = 0; i < sl; i++) {
		if (toa_dox[i] == xqua_to && toa_doy[i] == yqua_to) return true;
		else if (toa_dox[i] == xqua_to -1 && toa_doy[i] == yqua_to -1) return true;
		else if (toa_dox[i] == xqua_to  && toa_doy[i] == yqua_to - 1) return true;
		else if (toa_dox[i] == xqua_to + 1 && toa_doy[i] == yqua_to - 1) return true;
		else if (toa_dox[i] == xqua_to + 1 && toa_doy[i] == yqua_to ) return true;
		else if (toa_dox[i] == xqua_to + 1 && toa_doy[i] == yqua_to + 1) return true;
		else if (toa_dox[i] == xqua_to && toa_doy[i] == yqua_to + 1) return true;
		else if (toa_dox[i] == xqua_to - 1 && toa_doy[i] == yqua_to + 1) return true;
		else if (toa_dox[i] == xqua_to - 1 && toa_doy[i] == yqua_to ) return true;
	}
	return false;
}
//xuất điểm
void Snake::xuat_diem() {
	SetColor(3); 
	for (int i = 101; i <= 115; i++) {
		gotoXY(i, 1); 
		std::cout << (char)207; 
		gotoXY(i, 5); 
		std::cout << (char)209; 
	}
	for (int i = 1; i <= 5; i++) {
		gotoXY(115, i); 
		std::cout << (char)198;
		gotoXY(101, i); 
		std::cout << (char)181;
	}
	gotoXY(104, 3); 
	std::cout << "Score: " << score; 
}
void Snake::chon_toc_do() {
	ShowCur(0);
		SetColor(6);
		std::cout << "Chon toc do ";
	SetColor(10); 
	gotoXY(5, 3); std::cout << "1. Rat cham"; 
	gotoXY(5, 4); std::cout << "2. Cham";
	gotoXY(5, 5); std::cout << "3. Trung binh";
	gotoXY(5, 6); std::cout << "4. Nhanh"; 
	gotoXY(5, 7); std::cout << "5. Rat nhanh";
	gotoXY(5, 8); std::cout << "6. Cuc nhanh";
	int temp = _getch();
	if (temp == (int)'1') {
		sleep = 200;
		tocdo = 1;
	}
	else if (temp == (int)'2') {
		sleep = 170;
		tocdo = 2;
	}
	else if (temp == (int)'3') {
		tocdo = 3;
		sleep = 140;
	}
	else if (temp == (int)'4') {
		sleep = 110;
		tocdo = 4;
	}
	else if (temp == (int)'5') {
		sleep = 70;
		tocdo = 5;
	}
	else if (temp == (int)'6') {
		sleep = 50;
		tocdo = 6;
	}
		system("cls"); 
		setting();
}
void Snake::chon_mau_ran() {
	ShowCur(0); 
	SetColor(7); 
	std::cout << "Chon mau ran"; 
	SetColor(10);
	gotoXY(2, 2); std::cout << "1. Xanh dam";
	gotoXY(2, 3); std::cout << "2. Xanh la";
	gotoXY(2, 4); std::cout << "3. Trang";
	gotoXY(2, 5); std::cout << "4. Do";
	gotoXY(2, 6); std::cout << "5. Xanh nhat";
	gotoXY(2, 7); std::cout << "Nhan X de tro ve menu tuy chon";
	int temp = _getch();
	if (temp == (int)'1') {
		mau_ran = 1;
	}
	else if (temp == (int)'2') {
		mau_ran = 2;
	}
	else if (temp == (int)'3') {
		mau_ran = 7;
	}
	else if (temp == (int)'4') {
		mau_ran = 4;
	}
	else if (temp == (int)'5') {
		mau_ran = 3;
	}
		system("cls");
		setting();

}
void Snake::setting() {
	std::cout << "1. Play" << std::endl; 
	std::cout << "2. Chon toc do" << std::endl; 
	std::cout << "3. Chon mau ran" << std::endl; 
	int temp = _getch(); 
	system("cls"); 
	if (temp == (int)'1') return;
	else if(temp ==(int)'2') {
		gotoXY(10, 1);
		chon_toc_do();
		system("cls");
	}
	else if (temp == (int)'3') {
		gotoXY(10, 1);
		chon_mau_ran();
		system("cls");
	}
}

//-------------------- hàm main -----------------------------------------------------
int main() {
	SetColor(8);
	Snake s;
	srand(time(NULL)); //tạo trái cho rắn
	s.play();
	_getch();
}

