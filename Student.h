#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include "Graphic.h"

class Student : public Person {
private:
    string student_id;
    string class_name;
    string cohort;
    string school;
public:
    // Constructor
    Student();
    // Getter
    string getStudentID();
    string getClassName();
    string getCohort();
    string getSchool();
    // Setter
    void setStudentID(string& id);
    void setClassName(string& className);
    void setCohort(string& cohortValue);
    void setSchool(string& schoolName);
    // Other member functions
    void print_info(int x, int y) override;
    void input(vector<Person*>& people) override;
};



std::vector<Student*> getStudentList(const std::vector<Person*>& people);

void printStudentAll(const std::vector<Person*>& people, int x, int y, int w, int h, int startIndex, int pageSize);





#endif // STUDENT_H


