#include"Menu_.h"


using namespace std;


void menuAdmin() {
    Staff* st = nullptr;
    ShowCur(0);
    while (1) {
        std::vector<std::string> choice_a = { "All manga titles",
                                                "Search 3",
                                                "Add new manga",
                                                "Delete manga",
                                                "Update manga",
                                                "Create new account",
                                                "View registered accounts",
                                                "View/Edit account information",
                                                "Save & Log out" };
        int x = 75, y = 15;
        int w = 50;
        int h = 2;
        showMainMenu(x, y, w, h, choice_a);
        int choice = (whereY() - y) / 2;
        if (choice == 0) {
            // Show danh sách
            int startIndex = 0;
            int pageSize = 10;
            showList(list, 25, 10, 160, 35, startIndex, pageSize);
            char keyP;
            keyP = _getch();
            do {
                if (keyP == 77 && startIndex < list.size()) { // Mui tên ph?i
                    startIndex += pageSize;
                    clearRectangle(32, 13, 50, 30);
                    showList(list, 25, 10, 160, 35, startIndex, pageSize);
                }
                else if (keyP == 75 && startIndex > 0) { // Mui tên trái
                    startIndex -= pageSize;
                    clearRectangle(32, 13, 50, 30);
                    showList(list, 25, 10, 160, 35, startIndex, pageSize);
                }
                keyP = _getch();

            } while (keyP != 27);

        }
        else if (choice == 1) {
            system("cls");
            menuSearch();
        }
        else if (choice == 2) {
            system("cls");
            add(list);
        }
        else if (choice == 3) {
            system("cls");
            remove(list);
        }
        else if (choice == 4) {
            update(list);

        }
        else if (choice == 5) {
            system("cls");
            st = dynamic_cast<Staff*>(current);
            st->createAdminAccount(people);
            writePeopleToFile(people);

        }
        else if (choice == 6) {
            menuViewAccount();
            system("cls");

        }
        else if (choice == 7) {
            do{
            system("cls");
            int x = 75; int y = 15;
            st = dynamic_cast<Staff*>(current);
            box(x - 10, y - 2, 50, 22, 11, 1, "\033[31m INFORMATION ");
            st->print_info(x, y);
            vector<string> chooice_ = { "Change password","Change all informations" ,"Go back" };
            showMainMenu(5, 40, 40, 2, chooice_);
            int choice = (whereY() - 40) / 2;
                if (choice == 0) {
                    system("cls");
                    changePass(100, 25);
                }
                else if (choice == 1) {
                    system("cls");
                    current->input(people);
                    writePeopleToFile(people);
                }
                else {
                    system("cls");
                    break;
                }

            } while (1);
           

           
        }
        else if (choice == 8) {
            system("cls");
            box(75, 25, 50, 2, 2, 1, "Confirm log out. [Y/N]: ");
            char key_out = _getch();
            if (key_out == 'y'|| key_out == 'Y') {
                system("cls");
                break;
            }

        }
    }
}

  /* std::vector<std::string> choice_a = {"Display main functions",
                                        "All manga titles",
                                        "Search",
                                        "View/Edit account information",
                                        "Help",
                                        "About",
                                        "Save & Log out" };*/






void menuUser() {
    ShowCur(0);
    while (1) {
        std::vector<std::string> choice_a = {   "All manga titles",
                                                "Search",
                                                "View/Edit account information",
                                                "Help",
                                                "About",
                                                "Save & Log out" };                                      
        int x = 75, y = 15;
        int w = 50;
        int h = 2;
        showMainMenu(x, y, w, h, choice_a);
        int choice = (whereY() - y) / 2;
        if (choice == 0) {
            // Show danh sách
            int startIndex = 0;
            int pageSize = 10;
            showList(list, 25, 10, 160, 35, startIndex, pageSize);
            char keyP;
            keyP = _getch();
            do {
                if (keyP == 77 && startIndex < list.size()) { // Mui tên ph?i
                    startIndex += pageSize;
                    clearRectangle(32, 13, 50, 30);
                    showList(list, 25, 10, 160, 35, startIndex, pageSize);
                }
                else if (keyP == 75 && startIndex > 0) { // Mui tên trái
                    startIndex -= pageSize;
                    clearRectangle(32, 13, 50, 30);
                    showList(list, 25, 10, 160, 35, startIndex, pageSize);
                }
                keyP = _getch();

            } while (keyP != 27);

        }
        else if (choice == 1) {
            system("cls");
            menuSearch();
        }
        else if (choice == 2) {
            do {
                system("cls");
                int x = 75; int y = 15;
                //st = dynamic_cast<Student*>(current);
                box(x - 10, y - 2, 50, 22, 11, 1, "\033[31m INFORMATION ");
                current->print_info(x, y);
                vector<string> chooice_ = { "Change password","Change all informations" ,"Go back" };
                showMainMenu(5, 40, 40, 2, chooice_);
                int choice = (whereY() - 40) / 2;
                if (choice == 0) {
                    system("cls");
                    changePass(100, 25);
                }
                else if (choice == 1) {
                    system("cls");
                    current->input(people);
                    writePeopleToFile(people);
                }
                else {
                    system("cls");
                    break;
                }

            } while (1);
        }
        else if (choice == 4) {
            system("cls");
            char c;
            c = _getch();
            do {
                cout << "Hello Wourd!";


                c = _getch();
            } while (c != 27);
            system("cls");
        }
        else if (choice == 5) {
            system("cls");
            box(75, 25, 50, 2, 2, 1, "Confirm log out. [Y/N]: ");
            char key_out = _getch();
            if (key_out == 'y' || key_out == 'Y') {
                system("cls");
                break;
            }
        }
        
    }

}
void menuStudent() {
    Student* st = nullptr;
    ShowCur(0);
    while (1) {
        std::vector<std::string> choice_a = { "All manga titles",
                                                "Search",
                                                "View/Edit account information",
                                                "Help",
                                                "About",
                                                "Save & Log out" };
        int x = 75, y = 15;
        int w = 50;
        int h = 2;
        showMainMenu(x, y, w, h, choice_a);
        int choice = (whereY() - y) / 2;
        if (choice == 0) {
            // Show danh sách
            int startIndex = 0;
            int pageSize = 10;
            showList(list, 25, 10, 160, 35, startIndex, pageSize);
            char keyP;
            keyP = _getch();
            do {
                if (keyP == 77 && startIndex < list.size()) { // Mui tên ph?i
                    startIndex += pageSize;
                    clearRectangle(32, 13, 50, 30);
                    showList(list, 25, 10, 160, 35, startIndex, pageSize);
                }
                else if (keyP == 75 && startIndex > 0) { // Mui tên trái
                    startIndex -= pageSize;
                    clearRectangle(32, 13, 50, 30);
                    showList(list, 25, 10, 160, 35, startIndex, pageSize);
                }
                keyP = _getch();

            } while (keyP != 27);

        }
        else if (choice == 1) {
            system("cls");
            menuSearch();
        }
        else if (choice == 2) {
            do {
                system("cls");
                int x = 75; int y = 15;
                st = dynamic_cast<Student*>(current);
                box(x - 10, y - 2, 50, 30, 11, 1, "\033[31m INFORMATION ");
                current->print_info(x, y);
                vector<string> chooice_ = { "Change password","Change all informations" ,"Go back" };
                showMainMenu(5, 40, 40, 2, chooice_);
                int choice = (whereY() - 40) / 2;
                if (choice == 0) {
                    system("cls");
                    changePass(100, 25);
                }
                else if (choice == 1) {
                    system("cls");
                    current->input(people);
                    writePeopleToFile(people);
                }
                else {
                    system("cls");
                    break;
                }

            } while (1);
        }
        else if (choice == 4) {
            system("cls");
            char c;
            c = _getch();
            do {
                cout << "Hello Wourd!";


                c = _getch();
            } while (c != 27);
            system("cls");
        }
        else if (choice == 5) {
            system("cls");
            box(75, 25, 50, 2, 2, 1, "Confirm log out. [Y/N]: ");
            char key_out = _getch();
            if (key_out == 'y' || key_out == 'Y') {
                system("cls");
                break;
            }
        }

    }

}


void showMainMenu(int x,int y,int w,int h,const std::vector<std::string>& nds){
    
    int t_color = 11;
    int b_color = 1;
    int b_color_sang = 75;
    int sl = nds.size(); // Sử dụng phương thức size() thay vì sizeof() để lấy số lượng phần tử trong vector
   
    box(x, y-3, w, h, t_color, b_color, "============MENU============");
    n_box(x, y, w, h, t_color, b_color, nds);

    int xp = x, yp = y; // Tọa độ của thanh sáng
    int xcu = xp, ycu = yp;
    bool kt = true;
    bool check = true;
    while (check) {
        // In thanh sáng mới khi cần
       
        if (kt == true) {
            // Xóa thanh sáng cũ
            gotoXY(xcu, ycu);
            thanh_sang(xcu, ycu, w, h, b_color, nds[(ycu - y) / 2]);
            xcu = xp;
            ycu = yp;
            // Vẽ thanh sáng mới
            thanh_sang(xp, yp, w, h, b_color_sang, nds[(ycu - y) / 2]);
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            // Đặt màu nền của console thành màu đen
            SetConsoleTextAttribute(hConsole, 0);
            kt = false;
        }

        // Kiểm tra phím nhấn
        if (_kbhit()) {
            char c = _getch();
            if (c == -32) {
                kt = true; // Đã nhấn
                c = _getch();
                // Di chuyển lên hoặc xuống
                if (c == 72) { // Mũi tên lên
                    if (yp != y) yp -= 2; // Di chuyển lên
                    else yp = y + h * (sl - 1); // Quay về dòng cuối cùng
                }
                else if (c == 80) { // Mũi tên xuống
                    if (yp != y + h * (sl - 1)) yp += 2; // Di chuyển xuống
                    else yp = y; // Quay về dòng đầu tiên
                }
            }
            else if (c == 13) {
                check = false;
            }
        }

        // Tốc độ
    }

}







void menuSearch() {
    std::vector<std::string> search_for = { "Name",
                                            "Tags",
                                            "Author",
                                            "Rating",
                                            "Year",
                                            "Refresh filter",
                                            "Cancel" };
    int x_ = 165; int y_ = 3;
    int w_ = 35; int h_ = 2;
    int x = 1; int y = 15; int w = 160; int h = 35;
    box_hien_thi_list(1, 15, 160, 35, 1, 1, "");
    while (1) {
        ShowCur(0);
        showMainMenu(x_, y_, w_, h_, search_for);
        int choice = (whereY() - y_) / 2;

        std::vector<Manga> result = list;
        char keyPress;
        int startIndex = 0;
        int pageSize = 10;
        bool show_all_list = true;
        
        if (choice == 0 || choice == 1 ||choice == 2 || choice == 3 || choice == 4) {
            box(19, 7, 100, 2, 23, 1, " search");
            if (choice == 0)
                result = searchbyName(result);
            if (choice == 1)
                result = searchbyTag(result);
            else if (choice == 2)
                result = searchbyAuthor(result);
            else if (choice == 3)
                result = searchbyRating(result);
            else if (choice == 4)
                result = searchbyYear(result);

            ShowCur(0);
            showList(result, x, y, w, h, startIndex, pageSize);
            keyPress = _getch();
            do {
                gotoXY(20, 10);std::cout << "                                                                          ";
                if (keyPress == 77 && startIndex < list.size()) { // Mui tên phải
                    startIndex+= pageSize;
                    clearRectangle(x + 2, y + 3, w - 10, 30);
                    showList(result, x, y, w, h, startIndex, pageSize);
                }
                else if (keyPress == 75 && startIndex > 0) { // Mũi tên trái
                    startIndex-= pageSize;
                    clearRectangle(x+2, y+3, w-10, 30);
                    showList(result, x, y, w, h, startIndex, pageSize);
                }
                keyPress = _getch();
            } while (keyPress != 27);
        }
        else if (choice == 5) {
            // Hiển thị danh sách
            char key_Press = _getch();
            showList(list, x, y, w, h, startIndex, pageSize);
            do {
                if (key_Press == 77 && startIndex < list.size()) { // Mũi tên phải
                    ++startIndex;
                    clearRectangle(x + 2, y + 3, w - 10, 30);
                    showList(list, x, y, w, h, startIndex, pageSize);
                }
                else if (key_Press == 75 && startIndex > 0) { // Mũi tên trái
                    --startIndex;
                    clearRectangle(x + 2, y + 3, w - 10, 30);
                    showList(list, x, y, w, h, startIndex, pageSize);
                }
                key_Press = _getch();
            } while (key_Press != 27);
        }
        else if (choice == 6) { break; }
    }
}

void menuViewAccount() {
    std::vector<std::string> choice_a = {       "User",
                                                "Student",
                                                "Staff",
                                                "Cancel" };
    int x = 5, y = 40;
    int w = 30;
    int h = 2;
    showMainMenu(x, y, w, h, choice_a);
    int choice = (whereY() - y) / 2;
    auto st = dynamic_cast<Staff*>(current);
    
    if (choice == 0) {
        int x = 1;int y = 1; int w = 150; int h = 35;
        int startIndex = 0;
        int pageSize = 10;
        printUserAll(people, x, y, w, h, startIndex, pageSize);
        char keyP;
        keyP = _getch();
        do {
            if (keyP == 77 && (startIndex + 1) * pageSize < list.size()) { // Mui tên ph?i
                startIndex += pageSize;
                system("cls");
                printUserAll(people, x, y, w, h, startIndex, pageSize);
            }
            else if (keyP == 75 && startIndex > 0) { // Mui tên trái
                startIndex -= pageSize;
                system("cls");
                printUserAll(people, x, y, w, h, startIndex, pageSize);
            }
            keyP = _getch();

        } while (keyP != 27);
    }
    else if (choice == 1) {
        int x = 1;int y = 1; int w = 160; int h = 34;
        int startIndex = 0;
        int pageSize = 10;
        printStudentAll(people, x, y, w, h, startIndex, pageSize);
        char keyP;
        keyP = _getch();
        do {
            if (keyP == 77 && startIndex < list.size()) { // Mui tên ph?i
                startIndex += pageSize;
                clearRectangle(x, y, w, h);
                printStudentAll(people, x, y, w, h, startIndex, pageSize);
            }
            else if (keyP == 75 && startIndex > 0) { // Mui tên trái
                startIndex -= pageSize;
                clearRectangle(x+1, y+1, w-2, h-2);
                printStudentAll(people, x, y, w, h, startIndex, pageSize);
            }
            keyP = _getch();

        } while (keyP != 27);
    }
    else if (choice == 2) {
        int x = 1;int y = 1; int w = 150; int h = 35;
        int startIndex = 0;
        int pageSize = 10;
        printStaffsAll(people, x, y, w, h, startIndex, pageSize);
        char keyP;
        keyP = _getch();
        do {
            if (keyP == 77 && (startIndex + 1) * pageSize < list.size()) { // Mui tên ph?i
                startIndex += pageSize;
                clearRectangle(x, y, w, h);
                printStaffsAll(people, x, y, w, h, startIndex, pageSize);
            }
            else if (keyP == 75 && startIndex > 0) { // Mui tên trái
                startIndex -= pageSize;
                clearRectangle(x, y, w, h);
                printStaffsAll(people, x, y, w, h, startIndex, pageSize);
            }
            keyP = _getch();

        } while (keyP != 27);

    }
    else return;

}

void editInformation() {
    std::vector<std::string> choice_a = {       "Change All Information",
                                                "Change Pass Word",
                                                "Cancel"};                                               
    int x = 150; int y = 4; int w = 40;int h = 2;
    showMainMenu(x,y,w,h, choice_a);
    int choice = (whereY() - y);
    if (choice == 0) {
        int x_t = 80;int y_t = 15;
        box(x - 5, y - 2, 50, 2,8, 5, " ");
        current->print_info(x_t, y_t);

    }
    
}