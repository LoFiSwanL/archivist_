#include <iostream>
#include "head.h"

using namespace std;

int main(){
    Book mybook("1984", "Orwell", 1949);
    cout << "Book name: " << mybook.get_book() << endl;
    cout << "Book author: " << mybook.get_author() << endl;
    cout << "Book year: " << mybook.get_year() << endl;

    Book mybook1("Animal Farm", "Orwell", 1954);
    cout << "Book name: " << mybook1.get_book() << endl;
    cout << "Book author: " << mybook1.get_author() << endl;
    cout << "Book year: " << mybook1.get_year() << endl;
    return 0;
}