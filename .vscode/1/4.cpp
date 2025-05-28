#include <iostream>
#include <cmath>
#include <format>

using namespace std;

int main(){
    int x, n;
    int size = 10;
    int array[size];
    cout << "Введіть кількість чисел в масиві(<= 10): ";
    cin >> n;
    cout << "Введіть числа масиву: ";
    for(int i = 0; i < n; i++){
        cin >> array[i];
    }
    cout << "Введіть після якого числа хочете вставити 42: ";
    cin >> x;
     cout << "Масив до: ";
     for(int i = 0; i < n; i++){
        cout << array[i] << " ";
    }

    int p = 1;
    while(p < size - 1 && n < 10){
        if(array[p - 1] == x){
            for(int i = n; i >= p + 1; i--){
                array[i] = array[i-1];
            }
            n++;
            array[p] = 42;
            p++;
        }
        p++;
     }
    cout << "\nМасив після: ";
    for(int i = 0; i < n; i++){
        cout << array[i] << " ";
    }
      return 0;
}