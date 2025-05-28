#pragma once;
#include <string>
using std::string;

class Zoo{
    int Zones_zoo(string such_number){
        int price = 0;
        int Zones[6] = {42, 25, 46, 39, 57, 33};

        for (int i = 0; i < 6; i++) {
        if (such_number[i] == '1') price += Zones[i];
        }
        return price;
    }
public:
    string information_for_customer();
    int get_Zones_zoo(string such_number);
    void inf_ticket(int price_ticket);
};