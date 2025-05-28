#include <iostream>
using namespace std;

int readNumber(){
    int a, b;
    cout << "Введіть перше число: ";
    cin >> a;
    cout << "Введіть друге число: ";
    cin >> b;
    return a, b;
}
void writeAnswer(){
    int a, b;
    cout << "Сума введених двох чисел = " << a + b << endl;
}