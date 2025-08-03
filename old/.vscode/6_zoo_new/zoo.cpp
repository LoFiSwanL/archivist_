#include <iostream>
#include "sign.h"

using namespace std;

int main(){
    Zoo zoo;
    string such_number = zoo.information_for_customer();
    int price_ticket = zoo.get_Zones_zoo(such_number);
    zoo.inf_ticket(price_ticket);

    return 0;
}
//My varian 182 = 10110110