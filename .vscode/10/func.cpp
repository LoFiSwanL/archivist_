#include <iostream>
#include "head.h"

using namespace std;



int main(){
    Persons person1("John");
    cout << person1.to_string() << endl;
    person1.get_id();
    cout << person1.to_string() << endl;
    person1.get_id();
    cout << person1.to_string() << endl;
    person1.get_id();
    cout << person1.to_string() << endl;
    
}