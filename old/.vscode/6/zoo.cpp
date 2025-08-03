#include <iostream>
#include "sign.h"

using namespace std;

int main(){
    string such_number = information_custumer();
    int price_t = Zones_zoo(such_number);
    inf_ticket(price_t);

    return 0;
}
//My varian 182 = 10110110