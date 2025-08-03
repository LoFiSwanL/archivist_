#include <iostream>
#include <string.h>

using namespace std;
void string_n();

int main(){
    string_n();

    return 0;
}
void string_n(){
    char word[40];
    char drow[40];
    cout << "Введіть ваше слово: ";
    cin >> word;

    int length = strlen(word);
    for(int i = 0; i < length; i++){
        drow[i] = word[length - 1 - i];
    }
    drow[length] = '\0';
    bool is = false;
    for(int g = 0; g < length; g++){
        if(word[g] != drow[g]){
            is = true;
            break;
        }
    }
    if(is){
        cout << "Ваше слово не є паліндромом" << endl;
    }
    else{
        cout << "Ваше слово є паліндромом " << word << " = " << drow << endl;
    }
}