#include <iostream>
#include <cmath>
#include <format>

using namespace std;

int main(){
    int index;
    const int l = 5;
    int array[l];
    cout << "Введіть числа масиву: ";
    for (int k = 0; k < l; k++) {
        cin >> array[k];
    }
    cout << "Введіть індекс який треба видалити (" << l - 1 << "): ";
    cin >> index;

    cout << "Масив до: ";
    for(int i = 0; i < l; i++){
        cout << array[i];
    }
    for (int p = index; p < l - 1; p++) {
        array[p] = array[p + 1];
    }
    cout << "\nМасив після: ";
    for(int p = 0; p < l-1; p++){
    cout << array[p];
    }
    return 0;
}