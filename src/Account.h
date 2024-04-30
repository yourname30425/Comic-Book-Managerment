#pragma once
#include"Person.h"
#include "Student.h"
#include "Staff.h"

extern Person* current;

class AccountManager
{
public:
	void createAccount(vector<Person*>& people);
	void changePass(int x, int y);
	void asterisk(string& pass);
	void login(vector<Person*>& people);
	void start(vector<Person*>& people);

};

