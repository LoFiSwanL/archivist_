#include <iostream>
#include "sign.h"

int Zones_zoo(std::string such_number){
    int price = 0;
    int Zones[6] = {42, 25, 46, 39, 57, 33};

    for (int i = 0; i < 6; i++) {
        if (such_number[i] == '1') price += Zones[i];
    }

    return price;
}

std::string information_custumer(){
    std::string digit_number;
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

void inf_ticket(int price_t){
    srand(time(0));
    std::cout << "\nYour ticket №" << rand() << " " << std::endl;
    std::cout << "Price: " << price_t << std::endl;
}

