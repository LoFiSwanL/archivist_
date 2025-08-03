#include <iostream>
#include <cmath>
#include <format>

using namespace std;

int main(){
    int x;
    int size = 5;
    int array[size];
    cout << "Введіть числа масиву: ";
    for(int i = 0; i < size; i++){
    cin >> array[i];
    }
    int n = size;
    int is = true;
    int in = true;

    for (int i = 0; i < size - 1; i++) {
        if (array[i] < array[i + 1]) {
            is = false;
        } else if (array[i] > array[i + 1]) {
            in = false;
        }
    }
    if(in){
        cout << "Масив є монотонно зростаючою послідовністю." << endl;
    }
    else if (is) {
        cout << "Масив є монотонно спадною послідовністю." << endl;
    } 
    else {
        cout << "Масив не є монотонною послідовністю." << endl;
    }
    return 0;
}