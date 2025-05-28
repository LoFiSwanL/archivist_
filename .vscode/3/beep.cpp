#include "car.h"
#include "truck.h"
#include "bicycle.h"
#include <iostream>

int car::run(){
    std::cout << "beep beep" << std::endl;
    return 0;
}
int truck::run(){
    std::cout << "too too" << std::endl;
    return 0;
}
int bicycle::run(){
    std::cout << "diling diling" << std::endl;
    return 0;
}