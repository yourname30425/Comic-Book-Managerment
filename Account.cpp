
#include "Account.h"
#include "Menu_.h"


void AccountManager::createAccount(vector<Person*>& people) {
	std::vector<std::string> choice_a = { "User",
										"Student",
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
		gotoXY(55, 35);cout << "Successful!" << endl;

	}
	else if (choice == 1) {
		Student* ptr = new Student();
		ptr->input(people);
		people.push_back(ptr);
		cout << "Successful!" << endl;
	}
	else return;

}

void AccountManager::asterisk(string& pass) {
	pass = "";
	char ch;
	while (true) {
		ch = _getch(); // Get a character without echoing it to the console

		if (ch == 13) { // Check if the Enter key is pressed
			break;
		}
		else if (ch == 8 && !pass.empty()) { // Check if Backspace is pressed
			cout << "\b \b"; // Move the cursor back, print a space, move back again
			pass.pop_back();
		}
		else if (ch == 127 && !pass.empty()) { // Check if Delete is pressed
			cout << " \b";
			pass.pop_back();
		}
		else if (isprint(ch)) { // Check if the character is printable
			cout << '*';
			pass.push_back(ch);
		}
	}
}

void AccountManager::login(vector<Person*>& people) {
	string u, pass;
	bool access = false;
	while (1) {
		cout << setw(40) << left << "" << "\033[36m----------------------------------------------------------\033[0m" << endl;
		cout << setw(66) << left << "" << "\033[32mLOG IN\033[0m" << endl;
		cout << setw(40) << left << "" << "\033[36m----------------------------------------------------------\033[0m" << endl;
		cout << setw(40) << left << "" << "Username: ";
		getline(cin, u);
		cout << setw(40) << left << "" << "Password: ";
		asterisk(pass);
		for (int i = 0;i < people.size();i++) {
			if (people[i]->getAccount() == u && people[i]->getPassword() == pass) {
				access = true;
				current = people[i];
			}
		}
		if (access == true) {
			system("pause");
			system("cls");
			gotoXY(30, 12);
			cout << "\033[32mLogged in successfully.\033[0m | Welcome \033[34m" << current->getAccount() << "\033[0m" << endl;
			gotoXY(30, 13);
			cout << "Account type: " << "\033[31m" << current->type << "\033[0m" << endl;
			cout << endl;
			return;
		}
		else {
			cout << endl;
			cout << setw(40) << left << "" << "\033[33mInvalid username or password. Please try again.\033[0m" << endl;
			cout << setw(40) << left << "" << "\033[36m----------------------------------------------------------\033[0m" << endl;
		}
	}
}

void AccountManager::start(vector<Person*>& people) {
here:
	gotoXY(3, 49);
	cout << "\033[21;15H" << ".....\033[32mEnter = Log In\033[0m || \033[36mSpace = Create new account\033[0m || \033[33mESC = Exit\033[0m.....";
	while (1) {
		if (_kbhit()) {
			char key = _getch(); // Read a single character
			if (key == '\r') {
				// Enter key was pressed
				system("cls");
				login(people);
				break;
			}
			else if (key == ' ') {
				// Space bar was pressed
				system("cls");
				cout << "\033[36mCreating new account...\033[0m" << endl;
				createAccount(people);
				goto here;
				break;
			}
			else if (key == 27) {
				writeMangaToFile(list);
				writePeopleToFile(people);
				exit(0); // Exit program
			}
			else {
				// Do nothing for other keys
			}
		}
	}
}

void AccountManager::changePass(int x, int y) {
	textcolor(7);

	box(x - 10, y - 3, 50, 10, 11, 1, "\033[31m========CHANGE PASSWORD=======");
	while (1) {
		string password, new_password;
		gotoXY(x, y);
		std::cout << setw(20) << left << "\033[37mPassword: "; getline(cin, password);
		if (password == current->getPassword()) {
			gotoXY(x, y + 2);
			cout << setw(20) << left << "\033[37mNew password: ";
			getline(cin, new_password);
			current->setPassword(new_password);
			cout << "\033[37mchange pass word complete.";
			writePeopleToFile(people);
			break;

		}
		else {
			gotoXY(x, y);
			cout << " Nhap mat khau sai, vui long nhap lai...";

		}
	}

}
