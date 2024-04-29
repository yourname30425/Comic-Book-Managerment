#include "Graphic.h"



using namespace std;

void setConsoleSize(int columns, int rows) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SMALL_RECT rect = { 0, 0, static_cast<SHORT>(columns - 1), static_cast<SHORT>(rows - 1) };
	SetConsoleWindowInfo(hConsole, TRUE, &rect);
	COORD size = { static_cast<SHORT>(columns), static_cast<SHORT>(rows) };
	SetConsoleScreenBufferSize(hConsole, size);
}

int whereX()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.X;
	return -1;
}
//========= lấy tọa độ y của con trỏ hiện tại =======
int whereY()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.Y;
	return -1;
}
//============== dịch con trỏ hiện tại đến điểm có tọa độ (x,y) ==========
void gotoXY(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x, y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
//============= đặt màu cho chữ =========
void SetColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
//============== làm ẩn trỏ chuột ===========
void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}
//======= trả về mã phím người dùng bấm =========
int inputKey()
{
	if (_kbhit()) //true
	{
		int key = _getch();

		if (key == 224)
		{
			key = _getch();
			return key + 1000;
		}

		return key;
	}
	else
	{
		return KEY_NONE;
	}
	return KEY_NONE;
}



void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}



std::string lowercase(const std::string& str) {
	std::string result;
	for (char ch : str) {
		result += std::tolower(ch);
	}
	return result;
}



void thanh_sang(int x, int y, int w, int h, int b_color, std::string  nd)
{
	textcolor(b_color);
	for (int iy = y + 1;iy <= y + h - 1;iy++)
	{
		for (int ix = x + 1;ix <= x + w - 1;ix++)
		{
			gotoXY(ix, iy);cout << " ";
		}
	}
	SetColor(7);
	gotoXY(x + (w - nd.length()) / 2, y + 1);
	cout << nd;
}

void box(int x, int y, int w, int h, int t_color, int b_color, string nd)
{
	textcolor(b_color);
	for (int iy = y + 1;iy <= y + h - 1;iy++)
	{
		for (int ix = x + 1;ix <= x + w - 1;ix++)
		{
			gotoXY(ix, iy);cout << " ";
		}
	}
	SetColor(7);
	gotoXY(x + (w - nd.length()) / 2, y + 1);
	cout << nd;
	//============= ve vien =============
	textcolor(1);
	SetColor(t_color);//update
	if (h <= 1 || w <= 1)return;
	for (int ix = x;ix <= x + w;ix++)
	{
		gotoXY(ix, y);
		cout << char(196);
		gotoXY(ix, y + h);
		cout << char(196);
	}
	for (int iy = y;iy <= y + h;iy++)
	{
		gotoXY(x, iy);
		cout << char(179);
		gotoXY(x + w, iy);
		cout << char(179);
	}
	gotoXY(x, y);cout << char(218);
	gotoXY(x + w, y);cout << char(191);
	gotoXY(x, y + h);cout << char(192);
	gotoXY(x + w, y + h);cout << char(217);

}



void n_box(int x, int y, int w, int h, int t_color, int b_color, const vector<string>& nds) {
	int sl = nds.size();
	for (int i = 0; i < sl; ++i) {
		box(x, y + (i * 2), w, h, t_color, b_color, nds[i]);
		if (i != 0) {
			gotoXY(x, y + (i * 2)); cout << char(195);
			gotoXY(x + w, y + (i * 2)); cout << char(180);
		}
	}
}

void box_hien_thi_list(int x, int y, int w, int h, int t_color, int b_color, string nds)
{
	box(x, y, w, h, t_color, b_color, "");
	gotoXY(x + 3, y + 1);
	std::cout << std::setfill(' ');
	std::cout << std::setw(2) << std::left << "" << "| ";
	std::cout << "\033[31m" << std::setw(50) << std::left << "Title";
	std::cout << "\033[32m" << std::setw(50) << std::left << "Tags";
	std::cout << "\033[33m" << std::setw(30) << std::left << "Author";
	std::cout << "\033[34m" << std::setw(15) << std::left << "Date released";
	std::cout << "\033[35m" << std::setw(5) << std::right << "Rating" << std::endl << "\033[0m";
	gotoXY(x + 3, y + 2);
	std::cout << std::setfill('-') << std::setw(147) << "-" << std::endl;
}



void setFullscreen() {
	HWND hwnd = GetConsoleWindow();
	ShowWindow(hwnd, SW_MAXIMIZE); // Maximize cửa sổ console
	ShowWindow(hwnd, SW_SHOWMAXIMIZED); // Hiển thị fullscreen
}

#include <iostream>
#include <Windows.h>

void clearRectangle(int x1, int y1, int x2, int y2) {
	COORD topLeft = { static_cast<SHORT>(x1), static_cast<SHORT>(y1) };
	COORD bottomRight = { static_cast<SHORT>(x2), static_cast<SHORT>(y2) };

	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen;
	if (!GetConsoleScreenBufferInfo(console, &screen)) {
		std::cerr << "Error getting screen buffer info." << std::endl;
		return;
	}

	DWORD written;
	DWORD rectSize = (x2 - x1) * (y2 - y1);
	FillConsoleOutputCharacter(console, ' ', rectSize, topLeft, &written);
	FillConsoleOutputAttribute(console, screen.wAttributes, rectSize, topLeft, &written);
	SetConsoleCursorPosition(console, topLeft);
}

void clearConsoleLine(const std::string& nds) {
	ShowCur(0);
	std::cout << std::setfill(' ');
	std::cout << "\033[90m" << std::setw(nds.size()) << nds;
	_getch();
	std::cout << "\033[" << nds.size() << "D" << std::setw(nds.size()) << " ";
	std::cout << "\033[" << nds.size() << "D";
	ShowCur(1);
}
