#include "head.h"

Book::Book(const char *book_name, const string &author, int year) :author(author) , year(year)
{
    book = new char[strlen(book_name) + 1];
    strcpy(book, book_name);
}
Book::~Book(){
    if(book != nullptr){
        delete[] book;
        book = nullptr;
    }
}
string Book::get_author() const{
    return author;
}
int Book::get_year() const{
    return year;
}
const char* Book::get_book() const{
    return book;
}
