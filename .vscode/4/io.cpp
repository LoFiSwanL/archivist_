#include <iostream>
#include "oi.h"

int readnumber(){
    int a, b;
    std::cin >> a >> b;

    return a + b;
}
void writenumber(int s){
    std::cout << "a + b = " << s << std::endl;
}