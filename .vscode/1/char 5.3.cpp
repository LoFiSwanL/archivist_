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
   char maxword[100] = "";
   int maxlength = 0;

   while(word != 0){
       int length = strlen(word);
        if(length > maxlength){
            maxlength = length;
            strcpy(maxword, word);
        }
            word = strtok(0, " ,.!?");
    }
   if(maxlength > 0){
   cout << "найдовше слово рядка: " << maxword << endl;
   }
    else{
        cout << "найдовшого слова не існує" << endl;
    }
}