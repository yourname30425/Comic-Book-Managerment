#pragma once
#ifndef STAFF_H
#define STAFF_H

#include "Person.h"
#include "Student.h"
#include "MangaManager.h"
#include "Menu_.h"

class Staff : public Person {
private:
    string staff_id;
    string school;
    string department;
public:
    Staff();
    // Getter
    string getStaffID();
    string getSchool();
    string getDepartment();
    // Setter
    void setStaffID(string& id);
    void setSchool(string& schoolName);
    void setDepartment(string& departmentName);
    // Other member functions
    void print_info(int x, int y) override;
    void input(vector<Person*>& people) override;
    void createAdminAccount(vector<Person*>& people);
    void changePassword(vector<Person*>& people);   
};


std::vector<Staff*> getStaffsList(const std::vector<Person*>& people);
void printStaffsAll(const std::vector<Person*>& people, int x, int y, int w, int h, int startIndex, int pageSize);
#endif // STAFF_H
