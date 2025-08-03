#include <iostream>
#include <string.h>

using namespace std;
void string_n();
void wton();

int main(){
    string_n();

    return 0;
}
int wton(char wn){
    if(wn == 'i' || wn == 'l' || wn == 'I' || wn == 'j') return 1;
    else if(wn == 'U' || wn == 'W' || wn == 'w') return 2;
    else if(wn == 'E') return 3;
    else if(wn == 'c' || wn == 'C' || wn == 'h') return 4;
    else if(wn == 'V' || wn == 'v') return 5;
    else if(wn == 'b' || wn == 'G' || wn == 'd') return 6;
    else if(wn == 't' || wn == 'f' || wn == 'F') return 7;
    else if(wn == 'B') return 8;
    else if(wn == 'q' || wn == 'g' || wn == 'e') return 9;
    else if(wn == 'o' || wn == 'O' || wn == 'z' || wn == 'D' || wn == 'Z') return 0;
    else{
        return 10;
    }
}
void string_n(){
    char word[16];
    char num[16];
    cout << "Введіть ваше слово: ";
    cin >> word;
    int length = strlen(word);
    int numlenght = 0;
    for(int i = 0; i < length; i++){
        int numb = wton(word[i]); 
        if(numb != 10){
            num[numlenght++] = '0' + numb;
        }
        num[numlenght] = '\0';
    }

    cout << word << " = " << num << endl;
}