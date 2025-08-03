#include <iostream>
#include "fruit.h"

using namespace std;

int Basket::price(){
    int sum = 0;
    for(int i = 0; i < numbers_of_fruits; ++i){
        sum += fruits[i].get_price();
    }
    return sum;
}
Basket& Basket::operator += (Fruit fruit){
    if(numbers_of_fruits < NUMBER){
        fruits[numbers_of_fruits] = fruit;
        numbers_of_fruits++;
    }
    return *this;
}
int Fruit::get_price(){
    return price;
}
string Fruit::get_name(){
    return name;
}
Fruit::Fruit(string name){
     this -> name = name;
     price = rand()%20+5;
}