#include <iostream>
#include <cmath>
#include <format>

using namespace std;

int main(){
    int x, index = -1;
    const int size = 6;
    int array[size];

    cout << "Введіть числа масиву: ";
    for (int k = 0; k < size; k++) {
        cin >> array[k];
    }
    cout << "Введіть число яке треба видалити(): ";
    cin >> x;

    cout << "Масив до: ";
    for(int i = 0; i < size; i++){
        cout << array[i] << " ";
    }

    for(int p = size - 1; p > 0; p--){
        if(array[p] == x){
            index = p;
        }
    }
    while(index != -1){
        for(int i = index; i < size - 1; i++){
            array[i] = array[i+1];
        }
        array[size - 1] = 0;
    }

    cout << "\nМасив після: ";
    for(int p = 0; p < size - 1; p++){
    cout << array[p] << " ";
    }
    return 0;
}
