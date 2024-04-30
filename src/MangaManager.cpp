#include "MangaManager.h"
#include "Menu_.h"










template<typename T>
void inputNumber(T& i) {
    while (1) {
        if (std::cin >> i) {
            std::cin.ignore();
            break;
        }
        else {
            //Input failed
            gotoXY(20, 8);
            std::cout << "Invalid input. Please enter an integer: ";
            std::cin.clear(); // Clear the error flag
            //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cin.ignore();
        }
    }
}

void Manga::input(Manga& m) {
    int x = 55;int y = 19;
    setfill(' ');
    gotoXY(x, y += 2);
    std::cout << setw(20) << left << "Title: ";
    clearConsoleLine("Enter Name of manga ");
    std::getline(std::cin, m.name);
    gotoXY(x, y += 2);
    std::cout << setw(20) << "Tags: ";
    std::string tt;
    clearConsoleLine("Enter Type of manga ");
    std::getline(std::cin, tt);
    std::stringstream ss(tt);
    std::string t;
    while (ss >> t) m.tag.push_back(t);
    gotoXY(x, y += 2);
    std::cout << setw(20) << "Author: ";
    clearConsoleLine("Enter the author's name");
    std::getline(std::cin, m.author);
    gotoXY(x, y += 2);
    std::cout << setw(20) << "Date released: ";
    clearConsoleLine("Enter release time ");
    std::getline(std::cin, m.date);
    gotoXY(x, y += 2);
    std::cout << setw(20) << "Rating: ";
    clearConsoleLine("Enter Rating ");
    inputNumber(m.rate);
}

void Manga::show(const Manga& m) {
    std::cout << std::setfill(' ');
    std::cout << std::setw(50) << std::left << m.name;
    std::string allTags = m.tag[0];
    for (int j = 1;j < m.tag.size();j++) {
        allTags += ", ";
        allTags += m.tag[j];
    }
    std::cout << std::setw(50) << std::left << allTags;
    std::cout << std::setw(30) << std::left << m.author;
    std::cout << std::setw(15) << std::left << m.date;
    std::cout << std::setw(5) << std::right << m.rate << std::endl;

}

void Manga::showList(const std::vector<Manga>& list, int x, int y, int w, int h, int startIndex, int pageSize) {
    system("color 0A");
    box_hien_thi_list(x, y, w, h, 1, 1, "");
    // in list lên khung hiển thị
    if (list.size() == 0) {
        gotoXY(x + 1, y + 2);
        std::cout << "Empty list!";
        gotoXY(x + 10, y + 3);
        system("pause");
        system("cls");
        return;
    }
    int y_ = 3;
    for (int i = startIndex; i < startIndex + pageSize && i < list.size(); ++i) {
        gotoXY(x + 3, y + y_);
        y += 2;
        std::cout << std::setfill(' ') << std::setw(2) << std::left << i + 1 << "| ";
        show(list[i]);

    }
}



void Manga::add(std::vector<Manga>& list) {
    system("cls");
    std::vector<std::string> nsd = { " "," "," "," "," " };
    n_box(50, 20, 100, 2, 11, 1, nsd);
    setfill(' ');
    textcolor(6);
    gotoXY(50, 19);std::cout << std::setw(50) << std::left << "Adding new manga...";
    std::cout << setw(50) << right << "ENTER: add";
    Manga newManga;
    input(newManga);
    list.push_back(newManga);
    gotoXY(50, 40);cout << "complete!";
    system("cls");
}

void Manga::remove(std::vector<Manga>& list) {
    while (1) {
        system("cls");
        int x = 50; int y = 20; int w = 100; int h = 14;
        box(x, y - 1, w, h, 11, 1, " ");
        gotoXY(x, y - 2);
        cout << "\033[25m";
        ShowCur(1);
        std::cout << "Index of the manga that you want to delete: ";
        int n;
        cin >> n;
        if (n > 0 && n < list.size() + 1) {
            gotoXY(x + 1, y += 1);
            show_list_i(x, y, list[n - 1]);
            gotoXY(x, y + h);
            cout << "\033[33m" << "Do you want to Delete ? (y / n) : ";
            char choice;
            cin >> choice;
            ShowCur(0);
            gotoXY(x, y + h + 1);
            if (choice == 'y' || choice == 'Y') {
                list.erase(list.begin() + n - 1);
                cout << "Manga index = " << n << " has been removed.";
            }
            else  cout << " NOT deleted!";

        }
        else {
            std::cout << "Invalid index.";
        }
        gotoXY(x, 40);
        cout << "ENTER: Continue    |       ANYKEY: Cancel";
        char c = _getch();
        if (c != 13) {
            system("cls");
            break;
        }
    }
}



void Manga::update(std::vector<Manga>& list) {
    system("cls");
    box(65, 3, 60, 13, 8, 11, "INFOMATION");

    gotoXY(65, 2);std::cout << "\033[33m" << "Choose index: " << "\033[37m";
    int choice; cin >> choice;
    if (choice<1 || choice>list.size()) {
        std::cout << "Invalid index." << std::endl;
        return;
    }
    else {
        show_list_i(50, 4, list[choice - 1]);
        gotoXY(65, 19);
        std::cout << "Updating manga [" << choice << "] " << list[choice - 1].name << std::endl;

        list[choice - 1].tag.clear();
        list[choice - 1].tag.shrink_to_fit();
        std::vector<std::string> nsd = { " "," "," "," "," " };
        n_box(54, 20, 80, 2, 7, 7, nsd);
        input(list[choice - 1]);
    }
}


void Manga::show_list_i(int x, int y, const Manga& m) {
    std::setfill(' ');
    gotoXY(x + 20, y += 2);
    cout << setw(10) << "\033[33m" << std::left << "Title:" << "\033[37m" << m.name;
    gotoXY(x + 20, y += 2);
    cout << setw(10) << std::left << "\033[33m" << "Tags:";
    std::string allTags = m.tag[0];
    for (int j = 1; j < m.tag.size(); j++) {
        allTags += ", ";
        allTags += m.tag[j];
    }
    std::cout << "\033[37m" << allTags;
    gotoXY(x + 20, y += 2);
    cout << setw(10) << "\033[33m" << std::left << "Author: " << "\033[37m" << m.author;
    gotoXY(x + 20, y += 2);
    cout << setw(10) << "\033[33m" << std::left << "Date:" << "\033[37m" << m.date;
    gotoXY(x + 20, y += 2);
    cout << std::right << setw(10) << "\033[33m" << "Rate:";cout << "\033[37m" << m.rate;
}