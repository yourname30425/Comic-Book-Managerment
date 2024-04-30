

#include "Account.h"
#include "MangaManager.h"
#include "file_handling.h "
#include"Graphic.h"
#include "Menu_.h"
#include "Staff.h"





const int MAX_COLUMS_SCREEM = 250;
const int MAX_ROWS_SCREEM = 55;

vector<Person*> people; // Vector to store Person* objects // Global
std::vector<Manga> list;
Person* current = nullptr; // Global
extern void menuAdmin();
AccountManager ac;


int main() {
	while (1) {
		readfile(list);
		readfile(people);
		setConsoleSize(MAX_COLUMS_SCREEM, MAX_ROWS_SCREEM);
		system("cls");
		printCapybara("t_totoro.txt");
		gotoXY(0, 0);
		printCapybara("capybara.txt");
		ac.start(people);
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





