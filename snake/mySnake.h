#pragma once
#include"myGraphic.h"
#include<iostream>	
using namespace std;
#define MAX 100
class Snake {
private:
	int toa_dox[MAX] = { '0' };
	int toa_doy[MAX] = { '0' };
	int sl = 1;
	int xqua = -1, yqua= -1; 
	int xqua_to = -1, yqua_to = -1; 
	int tocdo = 1; 
	int qua_to = 1; 
	int score = 0; 
	int mau_ran; 
	int sleep = 200; 
public:
	void setting(); 
 	void chon_toc_do();
	void chon_mau_ran(); 
	void xuat_diem();
	void play();
	void ve_tuong();
	void khoi_tao_ran();
	void ve_ran();
	void di_chuyen(int, int);
	bool game_over(int, int); 
	void tao_qua(); 
	bool kt_ran_an_qua(); 
	void ve_qua(); 
	void xu_li_ran_an_qua(); 
	bool kiem_tra_ran_de_qua(); 
	bool kiem_tra_ran_cham_than(); 
	bool chien_thang_tro_choi(); 
	void tao_qua_to(); 
	void in_qua_to(); 
	bool kiem_tra_ran_de_qua_to();
	void xu_li_ran_an_qua_to(); 
	bool kt_ran_an_qua_to(); 
};
