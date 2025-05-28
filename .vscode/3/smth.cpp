#include <iostream>
#include "car.h"
#include "truck.h"
#include "bicycle.h"

using namespace std;

int main(){
    cout << "This is a car" << endl;
    car::run();

    cout << "tis is a truck? wow" << endl;
    truck::run();

    cout << "This is i bicycle, oh no" << endl;
    bicycle::run();
}