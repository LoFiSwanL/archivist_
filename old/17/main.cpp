#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <ostream>
#include <iterator>
#include <algorithm>

using namespace std;

ostream& operator<<(ostream& os, vector <int>& array){
    for(int i = 0; i < array.size(); ++i){
        os << array[i] << " ";
    }
    return os;
}
void f(){
    vector <int> arr {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};
    vector <int> arr2(11);
    for(int i = 0; i < 11; ++i){
        arr2[i] = pow(2, i);
    }
    vector <int> arr3;
    for(int i = 0; i < 11; ++i){
        arr3.push_back(pow(2, i));
    }
    cout << arr << endl;
    cout << arr2 << endl;
    cout << arr3 << endl;


    int N;
    cin >> N;
    vector <int> arr4(N);

    arr4[0] = arr4[1] = 1;
    for(int i = 2; i < N; ++i){
        arr4[i] = arr4[i-1] + arr4[i-2];
    }
    cout << "\n" << arr4 << endl;
}

// set<int> operator&(const set<int> &a, const set<int> &b){
//     set<int> inter;
//     for(auto &n: a){
//         if(b.contains(n)){
//             inter.insert(n);
//         }
//     }
//     return inter;
// }
set<int> operator&(const set<int> &a, const set<int> &b){
    set<int> inter;
    // auto it_a = a.begin();
    // auto it_b = b.begin();

    // while(it_a != a.end() && it_b != b.end()){
    //     int val_a = *it_a;
    //     int val_b = *it_b;
    //     if(val_a < val_b){
    //         it_a++;
    //     }
    //     else if(val_b < val_a){
    //         it_b++;
    //     }
    //     else{
    //         inter.insert(val_a);
    //         it_a++;
    //         it_b++;
    //     }
    // }

    set_intersection(a.begin(), a.end(), b.begin(), a.end(), inserter(inter, inter.end()));
    return inter;
}
ostream& operator<<(ostream& os, set<int> N){
    for(auto &i: N){
        cout << i << " ";
    }

    return os;
}
int main(){
    set<int> a {1, 2, 5, 6, 8};
    set<int> b {9, 2, 5, 3, 7};
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    cout << "Intersection: " << (a&b) << endl;
}