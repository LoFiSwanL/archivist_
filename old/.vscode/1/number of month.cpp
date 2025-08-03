#include <iostream>
#include <format>

using namespace std;

int main() 
{
    int x;
    cout << "Введіть номер місяця (від 1 до 12): ";
    cin >> x;

    if (x == 12 || x == 1 || x == 2){
        cout << "Winter" << endl;
        return 0;
    }
    else if (x >=3 && x <= 5){
        cout << "Spring" << endl;
        return 0;
    }
    else if (x >= 6 && x <= 8){
        cout << "Summer" << endl;
        return 0;
    }
    else if (x >=9 && x <= 11){
        cout << "Autumn" << endl;
        return 0;
    }
    else {
        cout << "число введено неправильно" << endl;
        return 0;
    }

}