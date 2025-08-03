#include <iostream>
#include "fruit.h"
using namespace std;

int main(){
    int numb;
    string name;
    Basket basket;
    cout << "ENter number of fruits: ";
    cin >> numb;
    for(int i = 0; i < numb; ++i){
        cout << "name of fruit";
        cin >> name;
        Fruit a(name);
        basket += a;
        cout << "\nprice now: " << basket.price() << endl;
    }

}