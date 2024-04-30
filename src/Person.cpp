#include "Person.h"


// Constructor
Person::Person() {
    type = "User";
    full_name = "";
    cccd = "";
    date_of_birth = "";
    phone_number = "";
    email = "";
    account = "";
    password = "";
}

// Destructor
Person::~Person() {}

// Getter methods
string Person::getFullname() {
    return full_name;
}

string Person::getCCCD() {
    return cccd;
}

string Person::getDateOfBirth() {
    return date_of_birth;
}

string Person::getPhoneNumber() {
    return phone_number;
}

string Person::getEmail() {
    return email;
}

string Person::getAccount() {
    return account;
}

string Person::getPassword() {
    return password;
}

// Setter methods
void Person::setFullname(string& name) {
    full_name = name;
}

void Person::setCCCD(string& cccdNumber) {
    cccd = cccdNumber;
}

void Person::setDateOfBirth(string& dob) {
    date_of_birth = dob;
}

void Person::setPhoneNumber(string& phone) {
    phone_number = phone;
}

void Person::setEmail(string& emailAddress) {
    email = emailAddress;
}

void Person::setAccount(string& acc) {
    account = acc;
}

void Person::setPassword(string& pass) {
    password = pass;
}

// Other member functions
void Person::print_info(int x, int y) {
    textcolor(8);
    gotoXY(x, y);
    cout << setw(15) << left << "Account type: " << type << endl;
    gotoXY(x, y+=2);
    cout << setw(15) << left << "Full Name: " << full_name << endl;
    gotoXY(x, y += 2);
    cout << setw(15) << left << "CCCD: " << cccd << endl;
    gotoXY(x, y += 2);
    cout << setw(15) << left << "Date of Birth: " << date_of_birth << endl;
    gotoXY(x, y += 2);
    cout << setw(15) << left << "Phone Number: " << phone_number << endl;
    gotoXY(x, y += 2);
    cout << setw(15) << left << "Email: " << email << endl;
    gotoXY(x, y += 2);
    cout << setw(15) << left << "Username: " << account << endl;

}

void Person::input(vector<Person*>& people) {
    string temp;
    std::vector<std::string> nsd = { " "," "," "," "," "," "," "};
    int x = 55;int y = 10;
    gotoXY(x-5, y); std::cout << "\033[33mCreating...";
    n_box(x-5, y+1, 100, 2, 7, 9, nsd);
    setfill(' ');
    gotoXY(x, y += 2);
    std::cout << setw(30) << left<< "\033[35mFull Name: ";
    clearConsoleLine("Enter full name ");
    std::getline(std::cin, temp);
    setFullname(temp);
    gotoXY(x, y += 2);
    std::cout << setw(30) << "\033[35mCCCD: ";
    clearConsoleLine("Enter CCCD ");
    std::getline(std::cin, temp);
    setCCCD(temp);
    gotoXY(x, y += 2);
    std::cout << setw(30) << "\033[35mDate of birth: ";
    clearConsoleLine("Enter date of birth (dd.mm.yyyy)");
    std::getline(std::cin, temp);
    setDateOfBirth(temp);
    gotoXY(x, y += 2);
    std::cout << setw(30) << "\033[35mphone number: ";
    clearConsoleLine("Enter phone number ");
    std::getline(std::cin, temp);
    setPhoneNumber(temp);
    gotoXY(x, y += 2);
    std::cout << setw(30) << "\033[35memail: ";
    clearConsoleLine("Enter email ");
    std::getline(std::cin, temp);
    setEmail(temp);
    gotoXY(x, y += 2);
    std::cout << setw(30) <<  "\033[35mUsername: ";
    clearConsoleLine("Enter Username ");
    while (1) {
        bool found = false;
        getline(cin, temp);
        for (int i = 0;i < people.size();i++) {
            if (temp == people[i]->getAccount()) found = true;
        }
        if (found == false) break;
        else { 
            cout << "\033[37mUsername already exist. Please enter another username: "; }
    }
    setAccount(temp);
    gotoXY(x, y += 2);
    cout << "\033[35mEnter password: " << "\033[37";

    getline(cin, temp);
    setPassword(temp);
}

std::vector<Person*> getUserList(const std::vector<Person*>& people) {
    std::vector<Person*> userList;
    for (const auto& person : people) {
        if (person->type == "User") {
            userList.push_back(person);
        }
    }
    return userList;
}

void printUserAll(const std::vector<Person*>& people,int x, int y ,int w , int h, int startIndex, int pageSize) {
    box(x, y, w, h, 8, 1, "");
    gotoXY(x + 3, y + 1); // Sử dụng toán tử + để di chuyển vị trí X, và sửa lỗi gán bằng '=' thành toán tử cộng '+'
    std::cout << std::setfill(' ');
    std::cout << std::setw(2) << std::left << "" << "| ";
    std::cout << "\033[31m" << std::setw(30) << std::left << "Account";
    std::cout << "\033[32m" << std::setw(30) << std::left << "Full Name";
    std::cout << "\033[33m" << std::setw(20) << std::left << "DateOfBirth";
    std::cout << "\033[35m" << std::setw(50) << std::left << "email";
    std::cout << "\033[35m" << std::setw(10) << std::right << "Phone Number" << std::endl << "\033[0m";
    gotoXY(x+2, y += 2);
    std::cout << std::setfill('-') << std::setw(145) << "-" << std::endl;
    int num = 1;
    std::vector<Person*> userList = getUserList(people);
    for (int i = startIndex; i < startIndex + pageSize && i < userList.size(); i++) {
        if (userList[i]->type == "User") {
            gotoXY(x+3, y += 2);
            std::cout << std::setfill(' ') << std::setw(2) << std::left << num << "| ";
            num++;
            std::cout << "\033[31m" << std::setw(30) << std::left << userList[i]->getAccount();
            std::cout << "\033[32m" << std::setw(30) << std::left << userList[i]->getFullname();
            std::cout << "\033[33m" << std::setw(20) << std::left << userList[i]->getDateOfBirth();
            std::cout << "\033[35m" << std::setw(50) << std::left << userList[i]->getEmail();
            std::cout << "\033[35m" << std::setw(10) << std::right << userList[i]->getPhoneNumber() << std::endl << "\033[0m";
        }
    }
    
}


