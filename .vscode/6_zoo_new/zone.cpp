#include <iostream>
#include "sign.h"

using namespace std;

string Zoo::information_for_customer(){
    string digit_number;
    bool valid_numb = false;
    while(!valid_numb){
        std::cout << "We have 6 zones: Авіарій, Акваріум, Арктика, Лісова зона, Савана, Тераріум";
        std::cout << "\nEnter a 6-digit number, without spaces, of zeros and ones, where 1 - yes, I will visit the zone, 0 - no. \nExample: 110110 = Авіарій - yes, Акваріум - yes, Арктика -no, Лісова зона - yes, Савана - yes, Тераріум - no. ";
        std::cout << "\nWrite your number there --> ";
        std::cin >> digit_number;
        if(digit_number.size() != 6){
            std::cout << "Wrong number! Write 6-digit number\n" << std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }
        else{
            valid_numb = true;
        }
    }
    return digit_number;
}
int Zoo::get_Zones_zoo(string such_number){
    return Zones_zoo(such_number);
}
void Zoo::inf_ticket(int price_ticket){
    srand(time(0));
    std::cout << "\nYour ticket №" << rand() << " " << std::endl;
    std::cout << "Price: " << price_ticket << std::endl;
}

