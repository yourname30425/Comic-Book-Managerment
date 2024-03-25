#pragma once
#ifndef SEARCH_H
#define SEARCH_H
#include "MangaManager.h"



// Khai báo các hàm tìm kiếm khác tại đây
std::vector<Manga> searchbyName(const std::vector<Manga>& list);

std::vector<Manga> searchbyTag(const std::vector<Manga>& list);

std::vector<Manga> searchbyAuthor(const std::vector<Manga>& list);

std::vector<Manga> searchbyYear(const std::vector<Manga>& list);

std::vector<Manga> searchbyRating(const std::vector<Manga>& list);

#endif