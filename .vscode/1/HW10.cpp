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

    cout << "\nA(" << n << ") = " << A_n(n) << endl;

    return 0;
}
long long A_n(int n){
    long long a_n, a_n_1 = 13, a_n_2 = 2;
    long long b_n , b_n_1 = 42;
    long long c_n, c_n_1 = 69;

    if (n == 1) return a_n_1;
    if (n == 2) return a_n_2;

    c_n = c_n_1;

    for (int i = 3; i <= n; i++){
        a_n =((a_n_1 * b_n_1 + a_n_2 * c_n) % 1000000007 + 1000000007) % 1000000007;
        b_n =((a_n + c_n + 2*b_n_1)%1000000007 + 1000000007) % 1000000007;
        c_n =((4*c_n_1 - a_n_1 * b_n_1) % 1000000007 + 1000000007) % 1000000007;

        c_n_1 = c_n;
        b_n_1 = b_n;
        a_n_2 = a_n_1;
        a_n_1 = a_n;
    }

    return a_n;
}