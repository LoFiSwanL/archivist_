#include <iostream>
#include <cmath>
#include <format>

using namespace std;

int rec(int r);
void check_n(int r);

const int MOD = 1000000007;
const int MAX = 1000;
int arr[MAX] = {};

int main(){
    int r;
    
    cout << "Введіть r <1000: ";
    while(r > 0){
        cin >> r;
        if(r > 0){
            check_n(r);
            int result = rec(r);
            cout << "A" << r << ": " << result << endl;
        }
    }
    return 0;
}

void check_n(int r){
    if(r >= 1000){
        cout << "\nНеправильно введено число n" << endl;
    }

}
int rec(int r){
    arr[0] = 6;
    arr[1] = 3;
    arr[2] = 3;
    arr[3] = 5;

    for(int i = 4; i <= r; i++){
        arr[i] = ((arr[i - 1] * arr[i - 3] - arr[i - 2] * arr[i - 4]) % MOD + MOD) % MOD + 1;
    }

    return arr[r];
}
/*
int rec(int n){
    if(arr[n] != 0) return arr[n];
    if (n == 0) return arr[0];
    if (n == 1) return arr[1];
    if (n == 2) return arr[2];
    if (n == 3) return arr[3];
    arr[0] = 6;
    arr[1] = 3;
    arr[2] = 3;
    arr[3] = 5;

    arr[n] = ((rec(n - 1) * rec(n - 3) - rec(n - 2) * rec(n - 4)) % MOD) % MOD + 1;

    return arr[n];
}*/

