

#include "Account.h"
#include "MangaManager.h"
#include "file_handling.h "
#include"Graphic.h"
#include "Menu_.h"
#include "Staff.h"





const int MAX_COLUMS_SCREEM = 250;
const int MAX_ROWS_SCREEM = 50;

vector<Person*> people; // Vector to store Person* objects // Global
std::vector<Manga> list;
Person* current = nullptr; // Global


void setConsoleSize(int columns, int rows) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SMALL_RECT rect = { 0, 0, static_cast<SHORT>(columns - 1), static_cast<SHORT>(rows - 1) };
	SetConsoleWindowInfo(hConsole, TRUE, &rect);
	COORD size = { static_cast<SHORT>(columns), static_cast<SHORT>(rows) };
	SetConsoleScreenBufferSize(hConsole, size);
}




extern void menuAdmin();


int main() {
	while (1) {
		readfile(list);
		readfile(people);
		setConsoleSize(MAX_COLUMS_SCREEM, MAX_ROWS_SCREEM);
		printCapybara();
		start(people);
		if (current->type == "Staff") {
			menuAdmin();
		}
		else if (current->type == "Student") {
			menuStudent();
		}
		else menuUser();
		//printStudentAll(people,1,1,150,40,0,5);
		
	}		
}
	




