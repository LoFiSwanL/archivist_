#pragma once
#include <iostream>
#include <cstring>
#include <string>

using std::string;

class Book
{
    char *book;
    string author;
    int year;
public:
    Book(const char *book, const string &author, int year);
    ~Book();
    string get_author() const;
    int get_year() const;
    const char *get_book() const;

};