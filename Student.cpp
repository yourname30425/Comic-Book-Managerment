#include "Student.h"



Student::Student() {

    string student_id = "";
    string class_name = "";
    string cohort = "";
    string school = "";
    type = "Student";
}

string Student::getStudentID() {
    return student_id;
}

string Student::getClassName() {
    return class_name;
}

string Student::getCohort() {
    return cohort;
}

string Student::getSchool() {
    return school;
}

void Student::setStudentID(string& id) {
    student_id = id;
}

void Student::setClassName(string& className) {
    class_name = className;
}

void Student::setCohort(string& cohortValue) {
    cohort = cohortValue;
}

void Student::setSchool(string& schoolName) {
    school = schoolName;
}

void Student::print_info(int x, int y) {
    Person::print_info(x,y); // Call the base class print_info first
    gotoXY(x, y += 14);
    cout << setw(15) << left << "Student ID: " << student_id << endl;
    gotoXY(x, y += 2);
    cout << setw(15) << left << "Class Name: " << class_name << endl;
    gotoXY(x, y += 2);
    cout << setw(15) << left << "Cohort: " << cohort << endl;
    gotoXY(x, y += 2);
    cout << setw(15) << left << "School: " << school << endl;
}

void Student::input(vector<Person*>& people) {
    string temp;
    int x = 55;int y = 30;
    std::vector<std::string> nsd = { " "," "," "," "};
    Person::input(people);
    setfill(' ');
    gotoXY(x, y += 2);
    std::cout << setw(30) << left << "\033[35mStudentID: ";
    clearConsoleLine("Enter StudentID ");
    std::getline(std::cin, temp);
    setStudentID(temp);
    gotoXY(x, y += 2);
    std::cout << setw(30) << "\033[35mClass Name: ";
    clearConsoleLine("Enter Class Name ");
    std::getline(std::cin, temp);
    setClassName(temp);
    gotoXY(x, y += 2);
    std::cout << setw(30) << "\033[35mcohort: ";
    clearConsoleLine("Enter cohort");
    std::getline(std::cin, temp);
    setCohort(temp);
    gotoXY(x, y += 2);
    std::cout << setw(30) << "\033[35mSchool: ";
    clearConsoleLine("Enter School ");
    getline(cin, temp);
    setSchool(temp);
    
    
    
}

void printStudentAll(const std::vector<Person*>& people, int x, int y, int w, int h, int startIndex, int pageSize) {
    box(x, y, w, h, 8, 1, "");
    gotoXY(x + 3, y + 1);
    std::cout << std::setfill(' ');
    std::cout << std::setw(2) << std::left << "" << "| ";
    std::cout << "\033[31m" << std::setw(30) << std::left << "Account";
    std::cout << "\033[32m" << std::setw(30) << std::left << "Full Name";
    std::cout << "\033[33m" << std::setw(15) << std::left << "Student ID";
    std::cout << "\033[35m" << std::setw(20) << std::left << "Class";
    std::cout << "\033[35m" << std::setw(30) << std::left << "Cohost";
    std::cout << "\033[35m" << std::setw(20) << std::left << "School" << std::endl << "\033[0m";
    gotoXY(x + 2, y + 2);
    std::cout << std::setfill('-') << std::setw(145) << "-" << std::endl;

    // Lấy danh sách sinh viên từ vector people
    std::vector<Student*> students = getStudentList(people);

    int num = 1;
    int printY = y + 3; // Vị trí y của dòng tiếp theo sẽ in
    for (int i = startIndex; i < startIndex + pageSize && i < students.size(); i++) {
        // Kiểm tra xem students[i] thực sự là một đối tượng Student
        Student* student = dynamic_cast<Student*>(students[i]);
        if (student != nullptr) {
            gotoXY(x + 3, printY);
            std::cout << std::setfill(' ') << std::setw(2) << std::left << num << "| "; num++;
            std::cout << "\033[31m" << std::setw(30) << std::left << student->getAccount();
            std::cout << "\033[32m" << std::setw(30) << std::left << student->getFullname();
            std::cout << "\033[33m" << std::setw(15) << std::left << student->getStudentID();
            std::cout << "\033[33m" << std::setw(20) << std::left << student->getClassName();
            std::cout << "\033[35m" << std::setw(30) << std::left << student->getCohort();
            std::cout << "\033[35m" << std::setw(20) << std::left << student->getSchool() << std::endl << "\033[0m";
            printY += 2; // Di chuyển xuống dòng tiếp theo
        }
    }
}

std::vector<Student*> getStudentList(const std::vector<Person*>& people) {
    std::vector<Student*> students;

    // Loop through each person
    for (Person* person : people) {
        // Check if the person is of type Student
        Student* student = dynamic_cast<Student*>(person);
        if (student != nullptr) {
            // If yes, add to the students vector
            students.push_back(student);
        }
    }

    return students;
}

