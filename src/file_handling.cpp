#include "file_handling.h"

void writePeopleToFile(const vector<Person*>& people) {
    ofstream outFile("account_list.txt", ios::trunc);
    if (!outFile.is_open()) {
        cerr << "Error: Unable to open file for writing." << endl;
        return;
    }

    for (auto& person : people) {
        outFile << person->type << ",";
        outFile << person->getFullname() << ",";
        outFile << person->getCCCD() << ",";
        outFile << person->getDateOfBirth() << ",";
        outFile << person->getPhoneNumber() << ",";
        outFile << person->getEmail() << ",";
        outFile << person->getAccount() << ",";
        outFile << person->getPassword();

        if (person->type == "Student") {
            auto student = dynamic_cast<Student*>(person);
            outFile << "," << student->getStudentID() << ",";
            outFile << student->getClassName() << ",";
            outFile << student->getCohort() << ",";
            outFile << student->getSchool();
        }
        else if (person->type == "Staff") {
            auto staff = dynamic_cast<Staff*>(person);
            outFile << "," << staff->getStaffID() << ",";
            outFile << staff->getSchool() << ",";
            outFile << staff->getDepartment();
        }
        outFile << endl;
    }
    outFile.close();
}

void readPeopleFromFile(vector<Person*>& people) {
    for (auto& personPtr : people) {
        delete personPtr;
    }
    people.clear();
    people.shrink_to_fit();

    ifstream inFile("account_list.txt");
    if (!inFile.is_open()) {
        cout << "Error: Unable to open file for reading." << endl;
        return;
    }
    string line;
    while (getline(inFile, line)) {
        stringstream ss(line);
        string type, fullname, cccd, dob, phone, email, account, password;

        getline(ss, type, ',');
        getline(ss, fullname, ',');
        getline(ss, cccd, ',');
        getline(ss, dob, ',');
        getline(ss, phone, ',');
        getline(ss, email, ',');
        getline(ss, account, ',');
        getline(ss, password, ',');

        Person* person = nullptr;
        if (type == "User") {
            person = new Person();
            person->setFullname(fullname);
            person->setCCCD(cccd);
            person->setDateOfBirth(dob);
            person->setPhoneNumber(phone);
            person->setEmail(email);
            person->setAccount(account);
            person->setPassword(password);
        }
        else if (type == "Student") {
            string studentID, className, school, cohort;

            getline(ss, studentID, ',');
            getline(ss, className, ',');
            getline(ss, cohort, ',');
            getline(ss, school);

            Student* student = new Student();
            student->setFullname(fullname);
            student->setCCCD(cccd);
            student->setDateOfBirth(dob);
            student->setPhoneNumber(phone);
            student->setEmail(email);
            student->setAccount(account);
            student->setPassword(password);
            student->setStudentID(studentID);
            student->setClassName(className);
            student->setCohort(cohort);
            student->setSchool(school);

            person = student;
        }
        else if (type == "Staff") {
            string staffID, school, department;

            getline(ss, staffID, ',');
            getline(ss, school, ',');
            getline(ss, department);

            Staff* staff = new Staff();
            staff->setFullname(fullname);
            staff->setCCCD(cccd);
            staff->setDateOfBirth(dob);
            staff->setPhoneNumber(phone);
            staff->setEmail(email);
            staff->setAccount(account);
            staff->setPassword(password);
            staff->setStaffID(staffID);
            staff->setSchool(school);
            staff->setDepartment(department);

            person = staff;
        }
        if (person != nullptr) {
            people.push_back(person);
        }
    }
    cout << "Account list loaded!" << endl;
    inFile.close();
}

void readMangaFromFile(vector<Manga>& list) {
    list.clear();
    list.shrink_to_fit();
    ifstream save("manga_list.txt");
    if (save.is_open()) {
        string line;
        while (getline(save, line)) {
            Manga m;
            m.name = line;
            if (getline(save, line)) {
                stringstream ss(line);
                string t;
                while (ss >> t) m.tag.push_back(t);
            }
            if (getline(save, line)) m.author = line;
            if (getline(save, line)) m.date = line;
            if (getline(save, line)) m.rate = stod(line);
            list.push_back(m);
        }
        cout << "Manga list loaded!" << endl;
    }
    else cout << "Failed to load manga list!" << endl;
    save.close();
}

void writeMangaToFile(const vector<Manga>& list) {
    ofstream output("manga_list.txt", ios::trunc);
    if (output.is_open()) {
        for (const Manga& m : list) {
            // Write each field of the Manga object to the file
            output << m.name << endl;
            // Write tags with spaces between them
            for (const string& tag : m.tag) {
                output << tag << ' ';
            }
            output << endl;
            output << m.author << endl;
            output << m.date << endl;
            output << m.rate << endl;
        }
        cout << endl << "Data has been saved." << endl;
    }
    else {
        cout << "Unable to open manga_list.txt for writing." << endl;
    }
    output.close();
}
void readfile(vector<Person*>& people) {
	for (auto& personPtr : people) {
        delete personPtr;
    }
    people.clear();
	people.shrink_to_fit();
    ifstream inFile("account_list.txt");
    if (!inFile.is_open()) {
        cout << "Error: Unable to open file for reading." << endl;
        return;
    }
	string line;
    while (getline(inFile, line)) {
        stringstream ss(line);
        string type, fullname, cccd, dob, phone, email, account, password;

        getline(ss, type, ',');
        getline(ss, fullname, ',');
        getline(ss, cccd, ',');
        getline(ss, dob, ',');
        getline(ss, phone, ',');
        getline(ss, email, ',');
        getline(ss, account, ',');
        getline(ss, password, ',');

        Person* person = nullptr;
		if (type == "User") {
            person = new Person();
            person->setFullname(fullname);
            person->setCCCD(cccd);
            person->setDateOfBirth(dob);
            person->setPhoneNumber(phone);
            person->setEmail(email);
            person->setAccount(account);
            person->setPassword(password);
        } else if (type == "Student") {
            string studentID, className, school, cohort;

            getline(ss, studentID, ',');
            getline(ss, className, ',');
            getline(ss, cohort, ',');
            getline(ss, school);

            Student* student = new Student();
            student->setFullname(fullname);
            student->setCCCD(cccd);
            student->setDateOfBirth(dob);
            student->setPhoneNumber(phone);
            student->setEmail(email);
            student->setAccount(account);
            student->setPassword(password);
            student->setStudentID(studentID);
            student->setClassName(className);
            student->setCohort(cohort);
            student->setSchool(school);

            person = student;
        } else if (type == "Staff") {
            string staffID, school, department;

            getline(ss, staffID, ',');
            getline(ss, school, ',');
            getline(ss, department);

            Staff* staff = new Staff();
            staff->setFullname(fullname);
            staff->setCCCD(cccd);
            staff->setDateOfBirth(dob);
            staff->setPhoneNumber(phone);
            staff->setEmail(email);
            staff->setAccount(account);
            staff->setPassword(password);
            staff->setStaffID(staffID);
            staff->setSchool(school);
            staff->setDepartment(department);

            person = staff;
        }
        if (person != nullptr) {
            people.push_back(person);
        }
    }
    cout << "Account list loaded!" << endl;
    inFile.close();
}
void readfile(vector<Manga>& list) {
    list.clear();
    list.shrink_to_fit();
    ifstream save("manga_list.txt");
    if (save.is_open()) {
        string line;
        while (getline(save, line)) {
            Manga m;
            m.name = line;
            if (getline(save, line)) {
                stringstream ss(line);
                string t;
                while (ss >> t) m.tag.push_back(t);
            }
            if (getline(save, line)) m.author = line;
            if (getline(save, line)) m.date = line;
            if (getline(save, line)) m.rate = stod(line);
            list.push_back(m);
        }
        cout << "Manga list loaded!" << endl;
    }
    else cout << "Failed to load manga list!" << endl;
    save.close();
}

void printCapybara(std::string nsd) {
    ifstream file(nsd);
    if (file.is_open()) {
        cout << file.rdbuf();
        file.close();
    }
}
