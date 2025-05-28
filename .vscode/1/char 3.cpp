#include <iostream>
#include <string.h>

using namespace std;
void string_n();

int main(){
    string_n();

    return 0;
}
void string_n(){
    char words[40];
    int n;
    int i = 0;

    const char X[] = "ch";
    cout << "Введіть речення для визначення в ньому ch: ";
    cin >> words;
    cout << "\nВведіть яку кількість разів мініумум повинно бути ch: ";
    cin >> n;

    char* Num = words;
    while((Num = strstr(Num, X)) != 0){
        i++;
        Num++;
    }
    if(i >= n){
    cout << "ваше речення містить >=" << n << "-х ch" << endl;
    }
    else{
         cout << "ваше речення містить < " << n << " ch" << endl;
    }
}