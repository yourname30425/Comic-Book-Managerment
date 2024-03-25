#pragma once
#ifndef FILE_HANDLING_H
#define FILE_HANDLING_H

#include "Person.h"
#include "Student.h"
#include "Staff.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;



void writePeopleToFile(const vector<Person*>& people);

void readPeopleFromFile(vector<Person*>& people);

void readMangaFromFile(vector<Manga>& list);

void writeMangaToFile(const vector<Manga>& list);

void readfile(vector<Person*>& people);

void readfile(vector<Manga>& list);

void printCapybara();
#endif // FILE_HANDLING_H