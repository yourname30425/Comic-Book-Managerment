#include "Search.h"




// Định nghĩa các hàm tìm kiếm khác tại đây





std::vector<Manga> searchbyName(const std::vector<Manga>& list) {
    while (true) {
        ShowCur(1);
        std::vector<Manga> result;
        textcolor(7);
        gotoXY(20, 8);
        std::string keyword;
        std:: cout << std::setfill(' ');
        std::cout << std::setw(7) <<std::left<< "NAME |";
        std::cout << std::setw(25) << "Searching for keyword:";
        std::getline(std::cin, keyword);
        keyword = lowercase(keyword);
        for (int i = 0; i < list.size(); i++) {
            if (lowercase(list[i].name).find(keyword) != std::string::npos) {
                result.push_back(list[i]);
            }
        }
        if (result.empty()) {
            gotoXY(20, 10);
            std::cout << std::setfill(' ') << std::setw(50) << "Can't find any manga with that keyword."; 
            return list; // Nếu người dùng chọn thoát, trả về danh sách ban đầu        
        }
      
        ShowCur(0);
        return result;
    }
}


std::vector<Manga> searchbyTag(const std::vector<Manga>& list) {
    while (true) {
        ShowCur(1);
        std::vector<Manga> result;
        std::string keyword;
        textcolor(7);
        gotoXY(20, 8);
        std::cout << "Searching for tags: ";
        std::getline(std::cin, keyword);
        keyword = lowercase(keyword);
        for (int i = 0; i < list.size(); i++) {
            for (int j = 0;j < list[i].tag.size();j++) {
                if (lowercase(list[i].tag[j]).find(keyword) != std::string::npos) {
                    result.push_back(list[i]);
                    break;
                }
            }
        }
        if (result.empty()) {
            gotoXY(20, 10);
            std::cout << std::setfill(' ') << std::setw(50) << "Can't find any manga with that keyword.";
            return list; // Nếu người dùng chọn thoát, trả về danh sách ban đầu
        }
        //showList(result, 11, 15, 160, 35, 0,10);
        return result;
    }
}

std::vector<Manga> searchbyAuthor(const std::vector<Manga>& list) {
    while (true) {
        ShowCur(1);
        std::vector<Manga> result;
        std::string keyword;
        textcolor(7);
        gotoXY(20, 8);
        std::cout << "Searching for author: ";
        std::getline(std::cin, keyword);
        keyword = lowercase(keyword);
        for (int i = 0; i < list.size(); i++) {
            if (lowercase(list[i].author).find(keyword) != std::string::npos) {
                result.push_back(list[i]);
            }
        }
        if (result.empty()) {
            gotoXY(20, 10);
            std::cout << std::setfill(' ') << std::setw(50) << "Can't find any manga with that author.";
            return list; // Nếu người dùng chọn thoát, trả về danh sách ban đầu
        }
        //showList(result, 11, 15, 160, 35, 0,10);
        ShowCur(0);
        return result;
    }
}

std::vector<Manga> searchbyYear(const std::vector<Manga>& list) {
    while (true) {
        ShowCur(1);
        std::vector<Manga> result;
        std::string keyword;
        textcolor(7);
        gotoXY(20, 8);
        std::cout << "Searching for year released: ";
        std::getline(std::cin, keyword);
        for (int i = 0; i < list.size(); i++) {
            if (list[i].date.find(keyword) != std::string::npos) {
                result.push_back(list[i]);
            }
        }
        if (result.empty()) {
            gotoXY(20, 10);
            std::cout << std::setfill(' ') << std::setw(50) << "Can't find any manga released in that year.";
            return list; // Nếu người dùng chọn thoát, trả về danh sách ban đầu
        }
        ShowCur(0);
        return result;
    }
}

std::vector<Manga> searchbyRating(const std::vector<Manga>& list) {
    while (true) {
        ShowCur(1);
        std::vector<Manga> result;
        double r;
        textcolor(7);
        gotoXY(20, 8);
        std::cout << "Searching for mangas with rating above: ";
        inputNumber(r);
        for (int i = 0; i < list.size(); i++) {
            if (list[i].rate >= r) {
                result.push_back(list[i]);
            }
        }
        if (result.empty()) {
            gotoXY(20, 10);
            std::cout << std::setfill(' ') << std::setw(50) << "Can't find any manga above that rating.";
            return list; // Nếu người dùng chọn thoát, trả về danh sách ban đầu
        }
        ShowCur(0);
        return result;
    }
}
