#include <iostream>
#include <format>
#include <numbers>
#include <cmath>

using namespace std;

long long A_n(int n);


int main(){
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "A(" << n << ") = " << A_n(n) << endl;

    return 0;
}

long long A_n(int n){
    long long a_n, a_n_1 = 6, a_n_2 = 3, a_n_3 = -3, a_n_4 = 5;
    if (n == 1) return a_n_1;
    if (n == 2) return a_n_2;
    if (n == 3) return a_n_3;
    if (n == 4) return a_n_4;
    
    for(int i = 5; i <= n; i++){
        a_n = ((a_n_1 * a_n_4 - 2 * a_n_2 * a_n_3)%1000000007 + 1000000007) % 1000000007;
        a_n_4 = a_n_3;
        a_n_3 = a_n_2;
        a_n_2 = a_n_1;
        a_n_1 = a_n;
    }
    return a_n;
}
