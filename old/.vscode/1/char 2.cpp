#include <iostream>
#include <сstring>

using namespace std;
void string_n();

int main(){
    string_n();

    return 0;
}
void string_n(){
    char words[40];
    const char X[] = "ERROR";
    cout << "Введіть речення для визначення в ньому ERROR: ";
    cin >> words;

    if(strncmp(words, X, strlen(X)) == false){
        cout << "Ваше речення починаєтсья з ERROR" << endl;
    }
    else{
        cout << "Ваше речення не починаєтсья з ERROR" << endl;
    }
}