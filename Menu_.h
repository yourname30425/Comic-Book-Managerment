#include "file_handling.h"
#include "Graphic.h"
#include "Account.h"
#include "MangaManager.h"
#include "Search.h"
#include <iostream>
#include <conio.h>


 // Global
extern vector<Person*> people;
extern Person* current;// Vector to store Person* objects // Global



using namespace std;
extern std::vector<Manga> list;

void menuAdmin();

void menuUser();

void menuStudent();

void showMainMenu(int x, int y, int w, int h, const std::vector<  std::string>& nds);

void menuSearch();

void menuViewAccount();

void editInformation();