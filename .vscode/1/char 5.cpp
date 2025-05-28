#include <iostream>
#include <string.h>

using namespace std;
void string_n();

int main(){
    string_n();

    return 0;
}
void string_n(){
   char sentence[100];
   int n = 0;
   char a = 'a';
   char b = 'b';
   cout << "Введіть декілька слів з пробілами або іншими знаками пунктуації: ";
   cin.getline(sentence, 100);
   
   char* word = strtok(sentence, " ,.!?");
   while(word != 0){
    if(word[0] == a || word[0] == b){
        n++;
    }
    word = strtok(0, " ,.!?");
   }

   cout << "кількість слів що починаються на a або b: " << n << endl;
}