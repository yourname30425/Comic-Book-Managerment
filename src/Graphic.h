#pragma once // tránh đụng độ thư viện khi gọi chồng file lên nhau
#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <iomanip>
#include "windows.h"



#define KEY_NONE	-1

void setConsoleSize(int columns, int rows);

//======= lấy tọa độ x của con trỏ hiện tại =============
int whereX();
//========= lấy tọa độ y của con trỏ hiện tại =======
int whereY();
//============== dịch con trỏ hiện tại đến điểm có tọa độ (x,y) ==========
void gotoXY(int x, int y);
//============= đặt màu cho chữ =========
void SetColor(WORD color);
//============== làm ẩn trỏ chuột ===========
void ShowCur(bool CursorVisibility);
//======= trả về mã phím người dùng bấm =========
int inputKey();
//======= chuyển đổi màu sắc của text =========
void textcolor(int x);


std::string lowercase(const std::string& str);


void thanh_sang(int x, int y, int w, int h, int b_color, std::string nd);

void box(int x, int y, int w, int h, int t_color, int b_color, std::string nd);

void n_box(int x, int y, int w, int h, int t_color, int b_color, const std::vector<std::string>& nds);

void box_hien_thi_list(int x, int y, int w, int h, int t_color, int b_color, std::string nds);
//====== thiết lập kích thước====
void setFullscreen();
// xóa các hiện thị trên console ======
void clearRectangle(int x1, int y1, int x2, int y2);

void clearConsoleLine(const std::string& nds);




