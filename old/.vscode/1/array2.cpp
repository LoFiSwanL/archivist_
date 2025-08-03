#include <iostream>
#include <cmath>
#include <format>

using namespace std;

int main(){
    int x, index;
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
    int n = 0;
    for(int p = 0; p < size - n; p++){
        if(array[p] == x){
            n++;
            for(int i = p; i < size - 1; i++){
                array[i] = array[i+1];
            }
            p--;
        }
    }

    cout << "\nМасив після: ";
    for(int p = 0; p < size - n; p++){
    cout << array[p] << " ";
    }
    return 0;
}
