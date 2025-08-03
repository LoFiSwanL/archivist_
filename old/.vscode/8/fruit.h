#pragma once
#include <string>
using std::string;

class Fruit{
    string name = "";
    int price = 0;
public:
    Fruit() = default;
    Fruit(string name);
    int get_price();
    string get_name();
};
class Basket{
    static const int NUMBER = 5;
    Fruit fruits[NUMBER];

    int numbers_of_fruits = 0;
public: 
    Basket() = default;
    Basket& operator += (Fruit fruit);
    int price();
};