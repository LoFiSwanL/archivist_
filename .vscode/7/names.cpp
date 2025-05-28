#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int numb_names();
string* input_names(int numberofnames);
void sorting(string* names, int numberofnames);

int main(){
    int numberofnames = numb_names();
    string* names = input_names(numberofnames);
    sorting(names, numberofnames);
    return 0;
}

int numb_names(){
    int number;
    cout << "Enter number of names: ";
    cin >> number;
    return number;
}
string* input_names(int numberofnames){
    string* names = new string[numberofnames];
    cout << "Enter names: ";
    for(int i = 0; i < numberofnames; ++i){
        cin >> names[i];
    }
    return names;
}
void sorting(string* names, int numberofnames){
    for(int i = 0; i < numberofnames - 1; ++i){
        int smallest_word = i;
        for(int g = i + 1; g < numberofnames; ++g){
            if(names[g] < names[smallest_word]){
                smallest_word = g;
            }
        }
        swap(names[i], names[smallest_word]);
    }
    cout << " ";
    for(int in = 0; in < numberofnames; ++in){
        cout << names[in] << endl;
    }
    
}