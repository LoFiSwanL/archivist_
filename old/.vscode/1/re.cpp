#include <iostream>
#include <cstring>

using namespace std;

void string_n();

int main() {
    string_n();
    return 0;
}

void string_n() {
    char sentence[100];
    cout << "Введіть декілька слів з пробілами або іншими знаками пунктуації: ";
    cin.getline(sentence, 100);

    char* word = strtok(sentence, " ,.!?");
    char maxword[100] = "";
    int maxlength = 0;

    while (word != 0) {
        int length = strlen(word);
        if (length > maxlength) {
            maxlength = length;
            strcpy(maxword, word);
        }
        word = strtok(0, " ,.!?");
    }

    if (maxlength > 0) {
        cout << "Найдовше слово рядка: " << maxword << endl;
    } else {
        cout << "Найдовшого слова не існує" << endl;
    }
}
