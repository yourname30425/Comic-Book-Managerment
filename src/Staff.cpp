#include "Staff.h"



Staff::Staff() {
    staff_id = "";
    school = "";
    department = "";
    type = "Staff";
}

string Staff::getStaffID() {
    return staff_id;
}

string Staff::getSchool() {
    return school;
}

string Staff::getDepartment() {
    return department;
}

void Staff::setStaffID(string& id) {
    staff_id = id;
}

void Staff::setSchool(string& schoolName) {
    school = schoolName;
}

void Staff::setDepartment(string& departmentName) {
    department = departmentName;
}

void Staff::print_info(int x, int y) {
    Person::print_info(x,y);
    gotoXY(x, y += 14);
    cout << setw(15) << left << "Staff ID: " << staff_id << endl;
    gotoXY(x, y += 2);
    cout << setw(15) << left << "Department: " << department << endl;
    gotoXY(x, y += 2);
    cout << setw(15) << left << "School: " << school << endl;
}

void Staff::input(vector<Person*>& people) {
    string temp;
    int x = 55;int y = 30;
    std::vector<std::string> nsd = { " "," "," "," " };
    Person::input(people);
    setfill(' ');
    gotoXY(x, y += 2);
    std::cout << setw(30) << left << "\033[35mStaffID: ";
    clearConsoleLine("Enter StaffID ");
    std::getline(std::cin, temp);
    setStaffID(temp);
    gotoXY(x, y += 2);
    std::cout << setw(30) << "\033[35mDepartment: ";
    clearConsoleLine("Enter Department ");
    std::getline(std::cin, temp);
    setDepartment(temp);
    gotoXY(x, y += 2);
    std::cout << setw(30) << "\033[35mSchool: ";
    clearConsoleLine("Enter School ");
    getline(cin, temp);
    setSchool(temp);
   
    
}

void Staff::createAdminAccount(vector<Person*>& people) {


    std::vector<std::string> choice_a = {       "User",
                                                "Student",
                                                "Staff",
                                                "Cancel" };
    int x = 5, y = 40;
    int w = 30;
    int h = 2;
    printMenuOptions(x, y, w, h, choice_a);
    int choice = (whereY() - y) / 2;
    if (choice == 0) {
        Person* ptr = new Person();
        ptr->input(people);
        people.push_back(ptr);
        gotoXY(55, 35);std::cout << "Successful!" << endl;
        

    }
    else if (choice == 1) {
        Student* ptr = new Student();
        ptr->input(people);
        people.push_back(ptr);
        std::cout << "Successful!" << endl;
    }
    else if (choice == 2) {
        Staff* ptr = new Staff();
        ptr->input(people);
        people.push_back(ptr);
        std::cout << "Successful!" << endl;
    }
    else {
        system("cls");
        return;
    }
    _getch();
    system("cls");
}


void Staff::changePassword(vector<Person*> &people) {
    cout << "Username you want to change password: ";
    string temp; getline(cin,temp);
    for (int i=0;i<people.size();i++) {
        if(people[i]->getAccount()==temp && people[i]->type != "Staff") {
            cout << "Set new password: ";
            getline(cin,temp);
            people[i]->setPassword(temp);
            cout << "Success!" << endl;
            return;
        }
    }
    cout << "Can't find any user or student with that username." << endl;
}


void printStaffsAll(const std::vector<Person*>& people, int x, int y, int w, int h, int startIndex, int pageSize) {
    box(x, y, w, h, 8, 1, "");
    gotoXY(x + 3, y + 1); 
    std::cout << std::setfill(' ');
    std::cout << std::setw(2) << std::left << "" << "| ";
    std::cout << "\033[31m" << std::setw(25) << std::left << "Account";
    std::cout << "\033[32m" << std::setw(25) << std::left << "Full Name";
    std::cout << "\033[33m" << std::setw(15) << std::left << "Staff ID";
    std::cout << "\033[35m" << std::setw(30) << std::left << "email";
    std::cout << "\033[35m" << std::setw(20) << std::right << "Department";
    std::cout << "\033[35m" << std::setw(20) << std::right << "School" << std::endl << "\033[0m";
    gotoXY(x + 3, y +=2);
    std::cout << std::setfill('-') << std::setw(145) << "-" << std::endl;
    int num = 1;
    std::vector<Staff*> staffs = getStaffsList(people);
    for (int i = startIndex; i < startIndex + pageSize && i < staffs.size(); i++) {
        if (staffs[i]->type == "Staff") {
            gotoXY(x + 3, y += 2);
            std::cout << std::setfill(' ') << std::setw(2) << std::left << num << "| ";
            num++;
            std::cout << "\033[31m" << std::setw(25) << std::left << staffs[i]->getAccount();
            std::cout << "\033[32m" << std::setw(25) << std::left << staffs[i]->getFullname();
            std::cout << "\033[33m" << std::setw(15) << std::left << staffs[i]->getStaffID();
            std::cout << "\033[35m" << std::setw(30) << std::left << staffs[i]->getEmail();
            std::cout << "\033[35m" << std::setw(20) << std::left << staffs[i]->getDepartment();
            std::cout << "\033[35m" << std::setw(20) << std::right << staffs[i]->getSchool() << std::endl << "\033[0m";
        }
    }
}

std::vector<Staff*> getStaffsList(const std::vector<Person*>& people) {
    std::vector<Staff*> staffs;

    // Loop through each person
    for (Person* person : people) {

        Staff* staff = dynamic_cast<Staff*>(person); // Chuyển đổi thành Staff*
        if (staff != nullptr) {

            staffs.push_back(staff);
        }
    }

    return staffs;
}