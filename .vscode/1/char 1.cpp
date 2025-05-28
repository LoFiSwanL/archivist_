#include <iostream>

using namespace std;
void string_n();

int main(){
    string_n();

    return 0;
}
void string_n(){
    char words[40];
    char X = 'X';
    cout << "Введіть слово для визначення в ньому букви X: ";
    cin >> words;
    bool isX = false;
    for(int i = 0; i < 40; i++){
        if(words[i] == X){
            isX = true;
            break;
        }
    }
    if(isX){
        cout << "у вашому слові є X" << endl;
    }
    else{
        cout << "у вашому слові нема X" << endl;
    }

}