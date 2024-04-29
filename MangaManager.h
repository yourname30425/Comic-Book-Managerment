#pragma once 
#ifndef MANGA_H
#define MANGA_H

#include"Graphic.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>
//#include <limits>
class Manga {
public:
    std::string name;
    std::vector<std::string> tag;
    std::string author;
    std::string date;
    double rate;
    void input(Manga& m);
    void show(const Manga& m);
    void showList(const std::vector<Manga>& list, int x, int y, int w, int h, int startIndex, int pageSize);
    void show_list_i(int x, int y, const Manga& m);
    void add(std::vector<Manga>& list);
    void remove(std::vector<Manga>& list);
    void update(std::vector<Manga>& list);
};


template<typename T>
void inputNumber(T& i);
void inputDouble(double& num);










std::vector<Manga> searchbyTag(const std::vector<Manga>& list);
std::vector<Manga> searchbyName(const std::vector<Manga>& list);
std::vector<Manga> searchbyAuthor(const std::vector<Manga>& list);
std::vector<Manga> searchbyYear(const std::vector<Manga>& list);
std::vector<Manga> searchbyRating(const std::vector<Manga>& list);

#endif // MANGA_H
