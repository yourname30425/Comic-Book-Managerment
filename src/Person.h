#pragma 
#ifndef PERSON_H
#define PERSON_H
#include "Graphic.h"
#include <iostream>
#include <iomanip>


using namespace std;


class Person {
private:
    string full_name;
    string cccd;
    string date_of_birth;
    string phone_number;
    string email;
    string account;
    string password;

public:
    string type;

    // Constructor
    Person();

    // Destructor
    virtual ~Person();

    // Getter methods
    string getFullname();
    string getCCCD();
    string getDateOfBirth();
    string getPhoneNumber();
    string getEmail();
    string getAccount();
    string getPassword();

    // Setter methods
    void setFullname(string& name);
    void setCCCD(string& cccdNumber);
    void setDateOfBirth(string& dob);
    void setPhoneNumber(string& phone);
    void setEmail(string& emailAddress);
    void setAccount(string& acc);
    void setPassword(string& pass);

    // Other member functions
    virtual void print_info(int x, int y);
    virtual void input(vector<Person*>& people);

    //void box_hien_thi_user(int x, int y, int w, int h, int t_color, int b_color, vector<Person*>& people);

};



std::vector<Person*> getUserList(const std::vector<Person*>& people);

void printUserAll(const std::vector<Person*>& people, int x, int y, int h, int w, int startIndex, int pageSize);

#endif // PERSON_H