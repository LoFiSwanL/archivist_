#include <iostream>
#include <cmath>

using namespace std;
int count_x(long long x, long long arr[]);

int main(){
    long long x;
    long long arr[1000];
    cout << "Вветь х: ";
    cin >> x;
    int size = count_x(x, arr);
    cout << "\nКількість дільників: " << count_x(x, arr) << endl;
    cout << "Дільники: ";
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
}
int count_x(long long x, long long arr[]){
    int cnt = 0;
    for(long long i = 2; i <= sqrt(x); i++){
        if(x % i == 0){
            arr[cnt] = i;
            cnt++;
            arr[cnt] = x / i;
            cnt++;
       }
    }
    return cnt;
}